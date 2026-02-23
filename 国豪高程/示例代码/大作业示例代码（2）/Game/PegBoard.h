#ifndef PEGBOARD_H
#define PEGBOARD_H

#include "PegMove.h"
#include <atomic>

class PegBoard {
public:
    static const int BOARD_SIZE = 7;
    int board[BOARD_SIZE][BOARD_SIZE];
    PegBoard();
    void Reset();
    bool CanMove(int x, int y, int dx, int dy) const;
    bool Move(int x, int y, int dx, int dy, PegMove& move);
    void Undo(const PegMove& move);
    bool HasValidMove() const;
    int CountPegs() const;
    PegMove GetBestMove(std::atomic<bool>& cancel);
};

#endif // PEGBOARD_H