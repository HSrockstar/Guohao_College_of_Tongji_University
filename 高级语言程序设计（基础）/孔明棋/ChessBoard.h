#pragma once
#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <graphics.h>

//�������������Լ���صĺ���
class ChessBoard
{
private:
    int board[7][7];
    int history[7][7];
    int step;

public:
    void reset(int init[7][7]);
    bool canMove() const;
    void draw(const IMAGE& img, int selected_x = -1, int selected_y = -1);
    void restoreHistory();
    bool move(int sx, int sy, int dx, int dy);
    int getCell(int i, int j) const;
    int countPieces() const;
};

#endif // CHESSBOARD_H