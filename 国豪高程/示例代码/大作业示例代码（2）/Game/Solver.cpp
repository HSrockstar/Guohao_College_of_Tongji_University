/***************************************************************
*  Optimal English Peg-Solitaire Solver (33-hole)
*  RefPaper  : Barker & Korf, “Solving Peg Solitaire with
*              Bidirectional BFIDA*”, AAAI-12
*
*  yzxoi – 2025-05
***************************************************************/
#include <iostream>
#include <vector>
#include <array>
#include <bitset>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <limits>
#include <random>
#include <cstring>
#include <fstream>
#include <istream>
#include <chrono>
#include <atomic>
#include "Solver.h"
using namespace std;

std::vector<Jump> bestPath;

/*--------- 0. 基本类型与常量 ----------*/
using Board = uint64_t;
static constexpr int HOLE_CNT = 33;
static constexpr int DIRS[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };

/*– 0.1 坐标 ?? 索引映射表 –*/
int xy2idx[7][7];// -1 表示无洞
int idx2x[HOLE_CNT], idx2y[HOLE_CNT], CENTER;

/*– 0.2 角点 / Merson region / Peg-Type 预表 –*/
bitset<HOLE_CNT> cornerMask;// 8 corners
int pegType[HOLE_CNT];// 0..3 = (x&1)<<1 | (y&1), representing types
int pegTypeGoalCnt[4]; // goal type
vector<bitset<HOLE_CNT>> mersonRegs;//Merson Regions

/*--------- 1. 位运算工具 ----------*/
inline bool hasPeg(Board b,int idx){ return b>>idx & 1ULL; }
inline void setPeg(Board &b,int idx){ b |= 1ULL<<idx; }
inline void clrPeg(Board &b,int idx){ b &= ~(1ULL<<idx); }
inline int popcount(Board b) { return static_cast<int>(bitset<64>(b).count()); }

/*--------- 2. 棋盘固定信息构建 ----------*/
void buildIndexMap(){
    memset(xy2idx,-1,sizeof xy2idx);
    int k=0;
    auto add=[&](int x,int y){
        xy2idx[x][y]=k; idx2x[k]=x; idx2y[k]=y;
        if(x==3 && y==3) CENTER=k; ++k;
    };
    /* English board 十字布局 */
    for(int y:{2,3,4}) for(int x:{0,1}) add(x,y);
    for(int y=0;y<7;++y) for(int x:{2,3,4}) add(x,y);
    for(int y:{2,3,4}) for(int x:{5,6}) add(x,y);

    /* 角点: 无法被跳过的位置 (8) */
    int corners[][2]={{0,2},{0,4},{2,0},{4,0},
                      {2,6},{4,6},{6,2},{6,4}};
    for(auto &p:corners) cornerMask.set(xy2idx[p[0]][p[1]]);

    /* peg-type = (x&1)<<1 | (y&1) */
    for(int i=0;i<HOLE_CNT;++i){
        pegType[i]=((idx2x[i]&1)<<1)|(idx2y[i]&1);
    }

    /* 手动划分 7 个 Merson region */
    auto box=[&](int x0,int y0,int x1,int y1){
        bitset<HOLE_CNT> s;
        for(int x=x0;x<=x1;++x)for(int y=y0;y<=y1;++y){
            int id=xy2idx[x][y]; if(id!=-1) s.set(id);
        }
        mersonRegs.push_back(s & ~cornerMask);
    };
	box(2,0,4,0); box(2,6,4,6); box(0,2,0,4); box(6,2,6,4);
    box(2,2,4,4); box(1,2,1,4); box(5,2,5,4);
//    box(2,1,3,2);box(1,3,2,4);box(3,4,4,5);box(4,2,5,3); // Bad Mersons
}

// Using SYM 8
uint8_t toSym[8][HOLE_CNT], fromSym[8][HOLE_CNT];

void buildSymmetryTables() {
    for (int i = 0; i < HOLE_CNT; ++i) {
        int x = idx2x[i], y = idx2y[i];
        int m[8][2] = {
            {  x,  y}, { 6-y,  x}, {6-x, 6-y}, {  y, 6-x},
            { 6-x,  y}, {  x, 6-y}, {  y,  x}, {6-y, 6-x}
        };
        for (int s=0;s<8;++s){
            int j = xy2idx[m[s][0]][m[s][1]];
            toSym[s][i]   = j;
            fromSym[s][j] = i;
        }
    }
}

/*--------- 3. Move 结构与跳跃生成 ----------*/
vector<Jump> jumps;

void buildJumps(){
    for(int i=0;i<HOLE_CNT;++i){
        int x=idx2x[i], y=idx2y[i];
        for(auto d:DIRS){
            int mx=x+d[0], my=y+d[1];
            int tx=x+2*d[0], ty=y+2*d[1];
            if(mx<0||mx>=7||my<0||my>=7||tx<0||tx>=7||ty<0||ty>=7) continue;
            int mid=xy2idx[mx][my], to=xy2idx[tx][ty];
            if(mid!=-1 && to!=-1){
                jumps.push_back({i,mid,to});
            }
        }
    }
	cerr<<"Total jumps: "<<jumps.size()<<"\n";
}

/*--------- 4. 启发式函数 ----------*/
struct HeuInfo{
    int pegCnt;
    int cornerOcc;           // hc
    int typeExcess[4];       // 多余 peg-type 数
    int mersonOcc;           // hm
};

HeuInfo calcHeuInfo(Board b){
    HeuInfo h{}; h.pegCnt=popcount(b);
    h.cornerOcc=popcount(b & cornerMask.to_ullong());

    int typeCnt[4]={};
    for(int i=0;i<HOLE_CNT;++i)
        if(hasPeg(b,i)) ++typeCnt[pegType[i]];
    for(int t=0;t<4;++t)
        h.typeExcess[t]=max(0,typeCnt[t]-pegTypeGoalCnt[t]);

    h.mersonOcc=0;
    for(auto &reg:mersonRegs)
        if( ((b & reg.to_ullong()) == reg.to_ullong()) ) ++h.mersonOcc;
    return h;
}

/* 一致启发式：hc + max(ht, hm) */
int heur_basic(const HeuInfo &inf){
    /* ht = ceil(excess/4) per type，取最大 */
    int ht=0;
    for(int t=0;t<4;++t) ht=max(ht,(inf.typeExcess[t]+3)/4);
    int hm=inf.mersonOcc;
//	 cerr<<"Heuristic: hc="<<inf.cornerOcc
//	 	<<", ht="<<ht<<", hm="<<hm<<"\n";
    return inf.cornerOcc + max(ht,hm);
}

/*--------- 5. 置换表（Zobrist 哈希） ----------*/
struct Zobrist{
    uint64_t rnd[HOLE_CNT];
    Zobrist(){ mt19937_64 rng(20250427);
        for(auto &x:rnd) x=rng(); }
    uint64_t hash(Board b)const{
        uint64_t h=0;
        for(int i=0;i<HOLE_CNT;++i) if(hasPeg(b,i)) h^=rnd[i];
        return h;
    }
} zob;

/*--------- 6. PDB Building（构建逆向 PDB） ----------*/
constexpr int L_idx[11] = { 0, 1, 2, 3, 6, 7, 8, 9,12,13,14 };
constexpr int C_idx[11] = {15,16,17,18,19,22,23,24,25,26,27 };
constexpr int R_idx[11] = {28,29,30,31,32, 4, 5,10,11,20,21 };

constexpr const int* SUB[3] = { L_idx, C_idx, R_idx };
inline uint16_t compress(Board b, int k){
    uint16_t idx = 0;
    for (int i = 0; i < 11; ++i)
        if (b >> SUB[k][i] & 1ULL) idx |= 1u << i;
    return idx;
}

inline Board expand(uint16_t idx, int k){
    Board b = 0;
    for (int i = 0; i < 11; ++i)
        if (idx >> i & 1u) b |= 1ULL << SUB[k][i];
    return b;
}

vector<Jump> subJump[3];
void buildSubJumps(){
    for (int k = 0; k < 3; ++k){
        const int* S = SUB[k];
        unordered_set<int> hole(S, S+11);
        for (const auto& jp : jumps){
            if (hole.count(jp.from) && hole.count(jp.over) && hole.count(jp.to))
                subJump[k].push_back(jp);
        }
    }
}

static uint8_t PDB[3][2048];
inline int popcount16(uint16_t x) {
    return bitset<16>(x).count();
}
void build_or_load_PDB(const vector<Jump>& jumps) {
    FILE* fp = nullptr;
    errno_t err = fopen_s(&fp, "pdb11.dat", "rb");
    bool needBuild = (err != 0 || fp == nullptr);
    if (!needBuild) {
        fread(PDB, 1, sizeof PDB, fp);
        fclose(fp);
        cerr << "PDB loaded.\n";
        return;
    }
    cerr << "Building 3-way 11-hole PDB …\n";
    for (int k = 0; k < 3; ++k){
	    auto& dist = PDB[k];
	    fill(begin(dist), end(dist), 255);
	
	    deque<uint16_t> q;
	    for (uint16_t idx = 0; idx < 2048; ++idx)
	        if (popcount16(idx) == 1){
	            dist[idx] = 0;
	            q.push_back(idx);
	        }
	
	    while (!q.empty()){
	        uint16_t idx = q.front(); q.pop_front();
	        Board b = expand(idx, k);
	        uint8_t d = dist[idx];
	
	        for (const auto& jp : subJump[k]){
	            if (hasPeg(b,jp.to) && !hasPeg(b,jp.from) && !hasPeg(b,jp.over)){
	                Board b2 = b;
	                setPeg(b2, jp.from);
	                setPeg(b2, jp.over);
	                clrPeg(b2, jp.to);
	
	                uint16_t idx2 = compress(b2, k);
	                if (dist[idx2] == 255){
	                    dist[idx2] = d + 1;
	                    q.push_back(idx2);
	                }
	            }
	        }
	    }
	    cerr << "  block " << k << " done. max=" 
	         << int(*max_element(begin(dist), end(dist))) << '\n';
	}

    err = fopen_s(&fp, "pdb11.dat", "wb");
    if (err == 0 && fp) {
        fwrite(PDB, 1, sizeof PDB, fp);
        fclose(fp);
        cerr << "PDB saved to pdb11.dat (" << sizeof PDB << " bytes)\n";
    }
}
inline uint8_t safeVal(uint8_t d) { return d==255 ? 0 : d; }

inline uint8_t h_pdb(Board b) noexcept {
    return  safeVal(PDB[0][ compress(b,0) ]) +
            safeVal(PDB[1][ compress(b,1) ]) +
            safeVal(PDB[2][ compress(b,2) ]);
}

inline uint8_t heur_combined(Board b) {
    uint8_t h1 = heur_basic( calcHeuInfo(b) );  // 角子 + Type + Merson
    uint8_t h2 = h_pdb(b);                      // 三路 11-hole PDB
    return h1 > h2 ? h1 : h2;
}

/*--------- 6. IDA* 迭代加深搜索 ----------*/
struct Node{ Board b; array<Board,8> sym; Board canon; int last; uint8_t g; };
inline Board min8(const array<Board,8>& a){
    return *min_element(a.begin(), a.end());
}

inline void flipBit(Board& x, int p){ x ^= 1ULL << p; }
inline void setBit (Board& x, int p){ x |= 1ULL << p; }

unordered_map<uint64_t,int> trans;   // hash → g_min

void genSucc(const Node &cur, std::vector<Jump> &out) {
    out.clear();
    for (const auto &jp : jumps)
        if (hasPeg(cur.b, jp.from) && hasPeg(cur.b, jp.over) && !hasPeg(cur.b, jp.to))
            out.push_back(jp);
}

bool goalTest(const Board &b,const int &g){
    return g>=0 && b==(1ULL<<CENTER);
}

int nextThreshold; vector<Jump> path;
int goalMoves=0;
inline Board canonical(Board b){
    Board best = b;
    for(int s=1;s<8;++s){
        Board t = 0;
        for(int j=0;j<HOLE_CNT;++j)
            if(b >> fromSym[s][j] & 1ULL) t |= 1ULL<<j;
        if(t < best) best = t;
    }
    return best;
}

inline void updateSymBoards(Node& child, const Node& cur, const Jump& jp) {
    child.sym = cur.sym;

    for (int s=0;s<8;++s){ // 8 SYM
        int pF = toSym[s][jp.from];
        int pO = toSym[s][jp.over];
        int pT = toSym[s][jp.to];

        flipBit(child.sym[s], pF);
        flipBit(child.sym[s], pO);
        flipBit(child.sym[s], pT);
    }
    child.canon = min8(child.sym);
}


bool dfs(Node& cur, int thres, std::atomic<bool>& cancel) {
    if (cancel.load()) return false;
    int f = cur.g + heur_combined(cur.b);
    if (f > thres){ nextThreshold = min(nextThreshold,f); return false; }
    if (goalTest(cur.b,cur.g)){ bestPath=path; goalMoves=cur.g; return true; }

    uint64_t hh = zob.hash(cur.canon);
    auto it = trans.find(hh);
    if (it!=trans.end() && it->second < cur.g) return false;
    if (it==trans.end() || cur.g < it->second) trans[hh] = cur.g;

    vector<Jump> succ; genSucc(cur, succ);
    for (const auto& jp : succ){
        if (cancel.load()) return false;
        uint8_t cost = (jp.from != cur.last);

        Node nxt;
        nxt.b = cur.b;
        clrPeg(nxt.b, jp.from); clrPeg(nxt.b, jp.over); setPeg(nxt.b, jp.to);
        nxt.last = jp.to;
        nxt.g    = cur.g + cost;

        updateSymBoards(nxt, cur, jp);

        path.push_back(jp);
        if (dfs(nxt, thres, cancel)) return true;
        path.pop_back();
    }
    return false;
}

void Solver_Init() {
    buildIndexMap();
    buildSymmetryTables();
    buildJumps();
    buildSubJumps();
    build_or_load_PDB(jumps);
    memset(pegTypeGoalCnt, 0, sizeof pegTypeGoalCnt);
    pegTypeGoalCnt[pegType[CENTER]] = 1;
}

bool solve(Board start, std::atomic<bool>& cancel) {
    trans.clear(); path.clear(); bestPath.clear();

    array<Board,8> initSym{};
    for(int s=0;s<8;++s){
        Board t=0;
        for(int i=0;i<HOLE_CNT;++i)
            if(start>>i & 1ULL) t |= 1ULL << toSym[s][i];
        initSym[s]=t;
    }
    Node root{ start, initSym, min8(initSym), -1, 0 };

    int thres = heur_combined(start);
    while(true){
        if (cancel.load()) return false;
        nextThreshold = INT_MAX;
		cerr<<"Doing thre:"<< thres<<endl;
        if (dfs(root, thres, cancel)) return true;
        if (nextThreshold == INT_MAX || nextThreshold >= 19) break;
        thres = nextThreshold;
    }
    return false;
}

/*-------------------------------------------
               FOR LOCAL TESTING
-------------------------------------------*/

/*--------- 7. I/O 与主函数 ----------*/
Board parseBoard(istream &in){
    /* 输入 7×7 字符网格: . 空, o 有子, X 无洞
     * 亦支持单行 33 字符 */
    string line; Board b=0;
    vector<char> cells;
    while(in>>line){
        if(line.empty()) continue;
        if(line.size()==7) cells.insert(cells.end(),line.begin(),line.end());
        else if(line.size()==33){ cells.assign(line.begin(),line.end()); break; }
    }
    int idx=0;
    for(int x=0;x<7;++x)for(int y=0;y<7;++y){
        if(xy2idx[x][y]==-1) continue;
        char c=cells[idx++];
        if(c=='o'||c=='O'||c=='1') setPeg(b,xy2idx[x][y]);
    }
    return b;
}

/* 默认开局：中心空，其余有子 */
Board defaultStart(){
    Board b=(1ULL<<HOLE_CNT)-1;
    clrPeg(b,CENTER); return b;
}
/*
int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    buildIndexMap();
    buildSymmetryTables();
    buildJumps();
    buildSubJumps();
    build_or_load_PDB(jumps);

    memset(pegTypeGoalCnt, 0, sizeof pegTypeGoalCnt);
    pegTypeGoalCnt[pegType[CENTER]] = 1;

    Board start = (argc > 1) ?
        [&]() { ifstream fin(argv[1]); return parseBoard(fin); }() :
        defaultStart();

    auto t0 = chrono::high_resolution_clock::now();
    bool ok = solve(start);
    auto t1 = chrono::high_resolution_clock::now();
    double ms = chrono::duration<double, milli>(t1 - t0).count();

    if (!ok) { cerr << "Unsolvable!\n"; return 0; }

    cout << "Solved in " << bestPath.size() << " jumps, "
        << goalMoves << " moves, "
        << ms / 1000 << " sec\n";
    return 0;
}
*/