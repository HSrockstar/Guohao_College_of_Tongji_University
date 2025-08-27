#include <iostream>
#include <iomanip>
#include <conio.h>
#include <Windows.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include "core.h"
using namespace std;


// ----------------- core features -----------------

// Randomly generate small numbers, 2(90%) or 4(10%)
void add_random_tile(int board[4][4])
{
    vector<pair<int, int>> empties;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            if (board[i][j] == 0)
                empties.emplace_back(i, j);

    if (empties.empty()) return; // no empty cell

    pair<int,int> tmp = empties[rand() % empties.size()];
    int r = tmp.first, c = tmp.second;
    board[r][c] = (rand() % 10 < 9) ? 2 : 4;
}

// Initialize: Clear all and add two numbers.
void init_board(int board[4][4])
{
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            board[i][j] = 0;
    add_random_tile(board);
    add_random_tile(board);
}

// Check whether can move: any empty cell or two identical number adjacent
bool can_move(int b[4][4])
{
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
        {
            if (b[i][j] == 0) return true;
            if (j < 3 && b[i][j] == b[i][j + 1]) return true;
            if (i < 3 && b[i][j] == b[i + 1][j]) return true;
        }
    return false;
}

// move left: compress -> move -> compress
bool move_left(int b[4][4], int& score)
{
    bool moved = false;
    for (int i = 0; i < 4; ++i) // each row
    {
        vector<int> row;
        for (int j = 0; j < 4; ++j)
            if (b[i][j] != 0) row.push_back(b[i][j]);
        int origSize = row.size();
        // compress
        for (int k = 0; k + 1 < (int)row.size(); ++k)
        {
            if (row[k] == row[k + 1])
            {
                row[k] *= 2;
                score += row[k];
                row.erase(row.begin() + k + 1);
                moved = true;
            }// compress once, skip for next
        }
        // fill 0
        for (int j = 0; j < 4; ++j)
        {
            int v = (j < (int)row.size() ? row[j] : 0);
            if (b[i][j] != v) moved = true;
            b[i][j] = v;
        }
    }
    return moved;
}

bool move_right(int b[4][4], int& score)
{
    // reverse -> left -> reverse
    for (int i = 0; i < 4; ++i)
        reverse(b[i], b[i] + 4);
    bool moved = move_left(b, score);
    for (int i = 0; i < 4; ++i)
        reverse(b[i], b[i] + 4);
    return moved;
}

bool move_up(int b[4][4], int& score)
{
    // T -> left -> T
    int t[4][4];
    for (int i = 0; i < 4; ++i) for (int j = 0; j < 4; ++j) t[i][j] = b[j][i];
    bool moved = move_left(t, score);
    for (int i = 0; i < 4; ++i) for (int j = 0; j < 4; ++j) b[j][i] = t[i][j];
    return moved;
}

bool move_down(int b[4][4], int& score)
{
    // T -> right -> T
    int t[4][4];
    for (int i = 0; i < 4; ++i) for (int j = 0; j < 4; ++j) t[i][j] = b[j][i];
    bool moved = move_right(t, score);
    for (int i = 0; i < 4; ++i) for (int j = 0; j < 4; ++j) b[j][i] = t[i][j];
    return moved;
}

