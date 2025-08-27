#include "GameController.h"
#include <windows.h>
#include <iostream>
#include <chrono>
#include <thread>
#include <atomic>
using namespace std;

void GameController::Run() {
    ui.DrawMenu();
    ui.DrawTips(L"正在预处理AI提示功能，请稍等...", 0, false);
    bool playing = true;
    bool useAIHint = false;
    PegMove AIHint;
    while (playing) {
        int opt=ui.DrawMenu();
        if (opt == 0) return;
        if (opt == 2) {
            ui.DrawTips(L"规则：点选棋子后选择移动方向，跳过相邻棋子后落在空格，该棋子被移除。", 0, false);
            ui.WaitForClick();
            continue;
        }
        pegBoard.Reset();
        while (true) {
            ui.DrawBoard(pegBoard, -1, -1, {}, useAIHint, AIHint);
            ui.DrawTips(L"", pegBoard.CountPegs(), true);
            if (!pegBoard.HasValidMove()) {
                bool win = (pegBoard.CountPegs() ==1 && pegBoard.board[3][3] == 1);
                ui.DrawTips(L"", pegBoard.CountPegs(), true, true, win);
                ui.WaitForClick();
                break;
            }
            int sx = -1, sy = -1;
            PegMove move = ui.GetUserMove(pegBoard, sx, sy, useAIHint, AIHint);
            if (move.from_x == -1) {
                // 撤销
                useAIHint = false;
                if (!history.empty()) {
                    pegBoard.Undo(history.top());
                    history.pop();
                    continue;
                }
            } else if (move.from_x == -2) {
                // 重开
                useAIHint = false;
                while (!history.empty()) {
                    pegBoard.Undo(history.top());
                    history.pop();
                }
                continue;
            } else if (move.from_x == -3) {
                // use AI Hint
                useAIHint = true;
                AIHint = PegMove();

                std::atomic<bool> done(false), cancel(false);
                PegMove result;
                auto t0 = std::chrono::steady_clock::now();

                std::thread worker([&]() {
                    result = pegBoard.GetBestMove(cancel);
                    done = true;
                    });

                while (!done.load()) {
                    if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) cancel = true;
                    wchar_t buf[128];
                    double total = std::chrono::duration<double>(
                        std::chrono::steady_clock::now() - t0
                    ).count();
                    swprintf(buf, 128, L"计算中…已耗时 %.1f 秒，按 ESC 取消", total);
                    ui.DrawTips(buf, pegBoard.CountPegs(), true);
                    Sleep(100);
                }

                worker.join();

                if (cancel.load()) {
                    ui.DrawTips(L"提示已取消", pegBoard.CountPegs(), true);
                }
                else {
                    AIHint = result;
                    wchar_t buf[128];
                    double total = std::chrono::duration<double>(
                        std::chrono::steady_clock::now() - t0
                    ).count();
                    swprintf(buf, 128, L"计算完成：用时 %.1f 秒", total);
                    ui.DrawTips(buf, pegBoard.CountPegs(), true);
                }
                continue;
            } else {
                useAIHint = false;
                int dx = (move.to_x - move.from_x) / 2;
                int dy = (move.to_y - move.from_y) / 2;
                PegMove realMove;
                if (pegBoard.Move(move.from_x, move.from_y, dx, dy, realMove)) {
                    history.push(realMove);
                } else {
                    ui.DrawTips(L"非法移动", pegBoard.CountPegs(), true);
                }
            }
        }
    }
}