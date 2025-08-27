// UIManager.cpp
#include "UIManager.h"
#include <iostream>
#include <graphics.h>
#include <string>
#include <vector>
#include <cmath>
#include <assert.h>
using namespace std;

UIManager::UIManager() {
    // 启动窗口
    initgraph(BOARD_PIXEL, BOARD_PIXEL + 170);
    setbkcolor(RGB(242,242,242));
    cleardevice();
}

void UIManager::DrawBoard(const PegBoard& pegBoard, int selected_x, int selected_y, std::vector<std::pair<int,int>> hints, bool useAIHint, PegMove AIHint) {
    cleardevice();
    // 绘棋盘背景
    setfillcolor(WHITE); setlinecolor(RGB(180,180,180));
    fillroundrect(MARGIN-10, MARGIN-10, BOARD_PIXEL-MARGIN+10, BOARD_PIXEL-MARGIN+10, 30, 30);

    // 绘棋盘格和棋子
    for (int x = 0; x < PegBoard::BOARD_SIZE; ++x) {
        for (int y = 0; y < PegBoard::BOARD_SIZE; ++y) {
            int val = pegBoard.board[x][y];
            int px = MARGIN + y * CELL_SIZE;
            int py = MARGIN + x * CELL_SIZE;

            if (val == -1) continue; // not a placeable position

            // base
            setlinecolor(RGB(180, 180, 180));
            setfillcolor(RGB(224, 224, 224));
            fillcircle(px+CELL_SIZE/2, py+CELL_SIZE/2, CELL_SIZE/2-2);

            // select or hint highlights
            bool isSelect = (selected_x==x && selected_y==y);
            bool isHint = false;
            bool isAIHint_from = (useAIHint && AIHint.from_x == x && AIHint.from_y == y);
            bool isAIHint_jumped = (useAIHint && AIHint.jumped_x == x && AIHint.jumped_y == y);
            bool isAIHint_to = (useAIHint && AIHint.to_x == x && AIHint.to_y == y);

            for (auto& pr : hints)
                if (pr.first==x && pr.second==y) isHint = true;
            if (isSelect) {
                setfillcolor(RGB(255, 224, 0));
                fillcircle(px + CELL_SIZE / 2, py+CELL_SIZE/2, CELL_SIZE/2-8);
            } else if (isHint) {
                setfillcolor(RGB(140, 255, 140));
                fillcircle(px + CELL_SIZE / 2, py+CELL_SIZE/2, CELL_SIZE/2-12);
            }
            else if (isAIHint_from) {
                setlinecolor(RGB(255, 140, 0));
                setlinestyle(PS_SOLID, 4);
                circle(px + CELL_SIZE / 2, py + CELL_SIZE / 2, CELL_SIZE / 2 - 6);
            }
            else if (isAIHint_jumped) {
                setlinecolor(RGB(255, 69, 0));
                setlinestyle(PS_SOLID, 4);
                circle(px + CELL_SIZE / 2, py + CELL_SIZE / 2, CELL_SIZE / 2 - 10);
            }
            else if (isAIHint_to) {
                setlinecolor(RGB(50, 205, 50));
                setlinestyle(PS_SOLID, 4);
                circle(px + CELL_SIZE / 2, py + CELL_SIZE / 2, CELL_SIZE / 2 - 6);
            }


            assert(val == 1 || val == 0);
            
            if (val == 1) {
                const int RMAX = CELL_SIZE / 2 - 12;
                int cx = px + CELL_SIZE / 2;
                int cy = py + CELL_SIZE / 2;
                int R2 = RMAX * RMAX;
                COLORREF clrInner = RGB(42, 113, 181);
                COLORREF clrOuter = RGB(24, 48, 98);

                // 径向渐变
                for (int dy = -RMAX; dy <= RMAX; ++dy) {
                    for (int dx = -RMAX; dx <= RMAX; ++dx) {
                        int dist2 = dx * dx + dy * dy;
                        if (dist2 > R2) continue;
                        double t = sqrt((double)dist2) / RMAX;
                        // 非线性：让中间稍微突出、边缘过渡柔和
                        double fade = pow(t, 1.1);

                        // 三通道插值
                        int r = GetRValue(clrInner) + (GetRValue(clrOuter) - GetRValue(clrInner)) * fade;
                        int g = GetGValue(clrInner) + (GetGValue(clrOuter) - GetGValue(clrInner)) * fade;
                        int b = GetBValue(clrInner) + (GetBValue(clrOuter) - GetBValue(clrInner)) * fade;

                        putpixel(cx + dx, cy + dy, RGB(r, g, b));
                    }
                }

                // 镜面高光
                int HR = RMAX / 3;
                int hx = cx - HR / 2, hy = cy - HR / 2;
                int HR2 = HR * HR;
                for (int dy = -HR; dy <= HR; ++dy) {
                    for (int dx = -HR; dx <= HR; ++dx) {
                        if (dx * dx + dy * dy > HR2) continue;
                        int x2 = hx + dx, y2 = hy + dy;
                        COLORREF base = getpixel(x2, y2);
                        int lr = min(255, GetRValue(base) + (255 - GetRValue(base)) * 0.3);
                        int lg = min(255, GetGValue(base) + (255 - GetGValue(base)) * 0.3);
                        int lb = min(255, GetBValue(base) + (255 - GetBValue(base)) * 0.3);
                        putpixel(x2, y2, RGB(lr, lg, lb));
                    }
                }
            }
            if (val == 0) {
                setlinecolor(RGB(180, 180, 180));
                setfillcolor(RGB(250, 250, 250));
                fillcircle(px+CELL_SIZE/2, py+CELL_SIZE/2, CELL_SIZE/2-18);
                circle(px+CELL_SIZE/2, py+CELL_SIZE/2, CELL_SIZE/2-18);
            }
        }
    }
    if (useAIHint && AIHint.from_x != -1) {
        int fx = MARGIN + AIHint.from_y * CELL_SIZE + CELL_SIZE / 2;
        int fy = MARGIN + AIHint.from_x * CELL_SIZE + CELL_SIZE / 2;
        int tx = MARGIN + AIHint.to_y * CELL_SIZE + CELL_SIZE / 2;
        int ty = MARGIN + AIHint.to_x * CELL_SIZE + CELL_SIZE / 2;

        setlinecolor(RGB(255, 140, 0));
        setlinestyle(PS_SOLID, 3);
        line(fx, fy, tx, ty);
        double ang = atan2(ty - fy, tx - fx);
        const double AH = 10.0; 
        const double PI = acos(-1);
        const double AW = PI / 6;
        int ax1 = tx - AH * cos(ang - AW);
        int ay1 = ty - AH * sin(ang - AW);
        int ax2 = tx - AH * cos(ang + AW);
        int ay2 = ty - AH * sin(ang + AW);
        line(tx, ty, ax1, ay1);
        line(tx, ty, ax2, ay2);
    }

    // 绘制标题
    settextstyle(34, 0, _T("微软雅黑"));
    setbkmode(TRANSPARENT);
    settextcolor(RGB(255,255,255));
    outtextxy(MARGIN - 5, BOARD_PIXEL - 8 , _T("孔明棋"));
}

void UIManager::DrawButton(int x, int y, int w, int h, const wchar_t* text, bool highlight) {
    setfillcolor(highlight ? RGB(90,180,255) : RGB(210,210,210));
    solidroundrect(x, y, x+w, y+h, 16, 16);
    settextcolor(RGB(24,48,98));
    setbkmode(TRANSPARENT);
    settextstyle(24, 0, _T("微软雅黑"));
    int tw = textwidth(text);
    int th = textheight(text);
    outtextxy(x+(w-tw)/2, y+(h-th)/2, text);
}
bool UIManager::IsInButton(int mx, int my, int x, int y, int w, int h) {
    return mx>=x && mx<=x+w && my>=y && my<=y+h;
}

void DrawMultilineText(int x, int y, const std::wstring& text, int maxWidth, int lineHeight) {
    std::wstring line;
    std::vector<std::wstring> lines;
    for (size_t i = 0; i < text.length(); ++i) {
        line += text[i];
        if (textwidth(line.c_str()) > maxWidth) {
            line.pop_back();
            lines.push_back(line);
            line = text[i];
        }
    }
    if (!line.empty()) lines.push_back(line);

    for (size_t i = 0; i < lines.size(); ++i) {
        outtextxy(x, y + i * lineHeight, lines[i].c_str());
    }
}

void UIManager::DrawTips(const std::wstring& msg, int remain_pegs, bool showPegs, bool showWin, bool win) {
    // Display Tips Background
    setfillcolor(RGB(242, 242, 242));
    solidrectangle(0, BOARD_PIXEL + 50, BOARD_PIXEL, BOARD_PIXEL + 150);

    settextstyle(24, 0, _T("微软雅黑"));
    setbkmode(TRANSPARENT);

    // Main Tips 
    settextcolor(RGB(0, 120, 224));
    DrawMultilineText(MARGIN, BOARD_PIXEL + 70, msg, BOARD_PIXEL - MARGIN * 2, 30);  // 手动换行函数

    // 棋子计数
    if (showPegs) {
        wchar_t buf[32];
        swprintf(buf, 32, L"剩余棋子: %d", remain_pegs);
        settextcolor(RGB(20, 20, 20));
        outtextxy(MARGIN + 320, BOARD_PIXEL + 120, buf);
    }

    // 胜负弹窗
    if (showWin) {
        settextstyle(36, 0, _T("微软雅黑"));
        settextcolor(win ? RGB(0, 64, 128) : RGB(220, 60, 10));
        outtextxy(MARGIN + 120, BOARD_PIXEL + 76, win ? L"恭喜你，你赢了！" : L"你无路可逃！");
    }
}

PegMove UIManager::GetUserMove(const PegBoard& pegBoard, int& select_x, int& select_y, bool useAIHint, PegMove AIHint) {
    // 1. 先点选棋子，2. 再点目标格
    int stage = 0;
    int from_x = -1, from_y = -1;
    std::vector<std::pair<int,int>> hints;

    int btn_w = 100, btn_h = 40;
    int btn_ai_x = BOARD_PIXEL - 360, btn_ai_y = BOARD_PIXEL - 10;
    int btn_undo_x = BOARD_PIXEL - 240, btn_undo_y = BOARD_PIXEL - 10;
    int btn_restart_x = BOARD_PIXEL - 120, btn_restart_y = BOARD_PIXEL - 10;

    int mx = -1, my = -1;
    ExMessage m;
    BeginBatchDraw();
    #define in_ai_btn IsInButton(mx, my, btn_ai_x, btn_ai_y, btn_w, btn_h)
    #define in_undo_btn IsInButton(mx, my, btn_undo_x, btn_undo_y, btn_w, btn_h)
    #define in_restart_btn IsInButton(mx, my, btn_restart_x, btn_restart_y, btn_w, btn_h)

    while (true) {
        DrawButton(btn_ai_x, btn_ai_y, 100, 40, L"提示", in_ai_btn);
        DrawButton(btn_undo_x, btn_undo_y, 100, 40, L"撤销", in_undo_btn);
        DrawButton(btn_restart_x, btn_restart_y, 100, 40, L"重开", in_restart_btn);

        if (peekmessage(&m, EX_MOUSE)) {
            mx = m.x;
            my = m.y;
            if (m.message == WM_LBUTTONDOWN) {
                EndBatchDraw();
                
                if (in_undo_btn) return PegMove(-1, -1, -1, -1, -1, -1);
                if (in_restart_btn) return PegMove(-2, -2, -2, -2, -2, -2);
                if (in_ai_btn) return PegMove(-3, -3, -3, -3, -3, -3);

                int gx = (my-MARGIN)/CELL_SIZE, gy = (mx-MARGIN)/CELL_SIZE;
                if (gx<0||gy<0||gx>=PegBoard::BOARD_SIZE||gy>=PegBoard::BOARD_SIZE) continue;
                if (pegBoard.board[gx][gy]==-1) continue;

                if (stage==0 && pegBoard.board[gx][gy]==1) {
                    from_x = gx; from_y = gy; stage=1;
                    hints.clear();
                    int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
                    for (auto& d:dirs) {
                        int tx = gx+2*d[0], ty = gy+2*d[1];
                        if (pegBoard.CanMove(gx, gy, d[0], d[1]))
                            hints.push_back({tx, ty});
                    }
                    DrawBoard(pegBoard, from_x, from_y, hints, useAIHint, AIHint);
                } else if (stage==1) {
                    bool found = false;
                    for (auto& p:hints) {
                        if (p.first==gx && p.second==gy) found=true;
                    }
                    if (found) {
                        select_x = from_x; select_y = from_y;
                        int dx = (gx - from_x)/2, dy = (gy - from_y)/2;
                        return PegMove(from_x, from_y, gx, gy, from_x+dx, from_y+dy);
                    }
                    if (pegBoard.board[gx][gy]==1) {
                        from_x = gx; from_y = gy;
                        hints.clear();
                        int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
                        for (auto& d:dirs)
                            if (pegBoard.CanMove(gx, gy, d[0], d[1]))
                                hints.push_back({gx+2*d[0], gy+2*d[1]});
                        DrawBoard(pegBoard, from_x, from_y, hints, useAIHint, AIHint);
                    }
                }
            }
        }
        if (useAIHint && AIHint.from_x == -1) {
            DrawTips(L"失败！当前状态无法到达有效解空间。", pegBoard.CountPegs(), true);
        }
        else {
            DrawTips(L"", pegBoard.CountPegs(), true);
        }
        FlushBatchDraw();
        Sleep(10);
    }
    #undef in_undo_btn
    #undef in_restart_btn
}

int UIManager::DrawMenu() {
    cleardevice();
    setbkcolor(RGB(42, 113, 181));
    cleardevice();
    settextstyle(46, 0, _T("微软雅黑"));
    setbkmode(TRANSPARENT);
    settextcolor(WHITE);
    outtextxy(BOARD_PIXEL / 2 - 140, BOARD_PIXEL / 2 - 80, _T("Peg Solitaire 孔明棋"));

    int btn_w = 140, btn_h = 50;
    int btn_start_x = BOARD_PIXEL / 2 - 70, btn_start_y = BOARD_PIXEL / 2;
    int btn_rule_x = btn_start_x, btn_rule_y = btn_start_y + 70;

    int mx = -1, my = -1;
    ExMessage m;
    // 启用双缓冲 https://docs.easyx.cn/zh-cn/beginbatchdraw
    BeginBatchDraw();
    #define in_start_btn IsInButton(mx, my, btn_start_x, btn_start_y, btn_w, btn_h)
    #define in_rule_btn IsInButton(mx, my, btn_rule_x, btn_rule_y, btn_w, btn_h)
    while (true) {
        if (peekmessage(&m, EX_MOUSE)) {
            mx = m.x;
            my = m.y;
            if (m.message == WM_LBUTTONDOWN) {
                EndBatchDraw();
                if (in_start_btn) return 1;
                if (in_rule_btn)  return 2;
            }
        }
        cleardevice();
        settextstyle(46, 0, _T("微软雅黑"));
        setbkmode(TRANSPARENT);
        settextcolor(WHITE);
        outtextxy(BOARD_PIXEL / 2 - 140, BOARD_PIXEL / 2 - 80, _T("Peg Solitaire 孔明棋"));

        DrawButton(btn_start_x, btn_start_y, btn_w, btn_h, L"开始游戏", in_start_btn);
        DrawButton(btn_rule_x, btn_rule_y, btn_w, btn_h, L"游戏说明", in_rule_btn);

        FlushBatchDraw();
        Sleep(10);
    }
    #undef in_start_btn
    #undef in_rule_btn
}

void UIManager::WaitForClick() {
    settextstyle(20, 0, _T("微软雅黑"));
    settextcolor(RGB(100, 100, 100));
    setbkmode(TRANSPARENT);
    outtextxy(MARGIN, BOARD_PIXEL + 130, _T("按任意键或点击鼠标返回菜单..."));

    ExMessage m;
    while (true) {
        if (peekmessage(&m)) {
            if ((m.message == WM_KEYDOWN) || (m.message == WM_LBUTTONDOWN)) {
                break;
            }
        }
        Sleep(10);
    }
}