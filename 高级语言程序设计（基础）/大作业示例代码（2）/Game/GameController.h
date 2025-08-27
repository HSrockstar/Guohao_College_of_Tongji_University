#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "PegBoard.h"
#include "UIManager.h"
#include "PegMove.h"
#include <stack>

class GameController {
    PegBoard pegBoard;
    UIManager ui;
    std::stack<PegMove> history;
public:
    void Run();
};

#endif // GAMECONTROLLER_H