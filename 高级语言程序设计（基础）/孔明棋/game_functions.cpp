#include "game_functions.h"
#include <tchar.h>
#include <conio.h>
#include <mmsystem.h>
#include <windows.h>

#pragma comment(lib, "winmm.lib")

const int cell_size = 70;
const int offset_x = 267;
const int offset_y = 116;

//加载页面和BGM
void begin()
{
    initgraph(955, 651);
    BeginBatchDraw();

    IMAGE loading;
    loadimage(&loading, _T("loading.jpg"), 955, 651, 1);
    putimage(0, 0, &loading);
    FlushBatchDraw();
    Sleep(500);

    mciSendString(_T("open bgm.mp3 alias BGM"), NULL, 0, NULL);
    mciSendString(_T("play BGM repeat"), NULL, 0, NULL);
}

//菜单页面
void choice()
{
    RoundButton ch_title =
    { 327, 125, 627, 225, 0, 0,
        RGB(0, 0, 0), RGB(0, 0, 0),
        RGB(0, 0, 0), RGB(0, 0, 0),
        WHITE, _T("孔明棋"), 100, _T("仿宋")
    };

    RoundButton en_title =
    { 345, 245, 605, 305, 0, 0,
        RGB(0, 0, 0), RGB(0, 0, 0),
        RGB(0, 0, 0), RGB(0, 0, 0),
        WHITE, _T("Peg Solitaire"), 60, _T("Times New Roman")
    };

    RoundButton choice1 =
    { 50, 360, 305, 430, 20, 20,
        RGB(0, 0, 0), RGB(180, 230, 250),
        RGB(0, 0, 0), RGB(120, 218, 218),
        BLACK, _T("经典模式"), 60, _T("楷体")
    };

    RoundButton choice2 =
    { 350, 360, 605, 430, 20, 20,
        RGB(0, 0, 0), RGB(180, 230, 250),
        RGB(0, 0, 0), RGB(120, 218, 218),
        BLACK, _T("残局模式"), 60, _T("楷体")
    };

    RoundButton choice3 =
    { 650, 360, 905, 430, 20, 20,
        RGB(0, 0, 0), RGB(180, 230, 250),
        RGB(0, 0, 0), RGB(120, 218, 218),
        BLACK, _T("游戏规则"), 60, _T("楷体")
    };

    RoundButton choice4 =
    { 350, 465, 605, 535, 20, 20,
        RGB(0, 0, 0), RGB(180, 230, 250),
        RGB(0, 0, 0), RGB(120, 218, 218),
        BLACK, _T("退出游戏"), 60, _T("楷体")
    };

    IMAGE background;
    loadimage(&background, _T("background.jpg"), 955, 651, 1);

    while (true)
    {
        cleardevice();
        putimage(0, 0, &background);

        POINT pt;
        GetCursorPos(&pt);
        ScreenToClient(GetHWnd(), &pt);

        ch_title.draw(pt.x, pt.y);
        en_title.draw(pt.x, pt.y);
        choice1.draw(pt.x, pt.y);
        choice2.draw(pt.x, pt.y);
        choice3.draw(pt.x, pt.y);
        choice4.draw(pt.x, pt.y);
        FlushBatchDraw();

        if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
        {
            if (choice1.isClicked(pt.x, pt.y))
            {
                int init[7][7] =
                {
                    {-1, -1, 1, 1, 1, -1, -1},
                    {-1, -1, 1, 1, 1, -1, -1},
                    { 1,  1, 1, 1, 1,  1,  1},
                    { 1,  1, 1, 0, 1,  1,  1},
                    { 1,  1, 1, 1, 1,  1,  1},
                    {-1, -1, 1, 1, 1, -1, -1},
                    {-1, -1, 1, 1, 1, -1, -1}
                };
                play_game(init);
            }

            else if (choice2.isClicked(pt.x, pt.y))
            {
                Sleep(50);
                endgame();
            }
            else if (choice3.isClicked(pt.x, pt.y))
            {
                rule();
            }
            else if (choice4.isClicked(pt.x, pt.y))
            {
                exit(0);
            }
        }
        Sleep(16);
    }
}

//游戏规则页面
void rule()
{
    RoundButton back =
    { 10, 10, 250, 80, 20, 20,
        RGB(0, 0, 0), RGB(180, 230, 250),
        RGB(0, 0, 0), RGB(120, 218, 218),
        BLACK, _T("返回菜单"), 50, _T("楷体")
    };

    IMAGE rule;
    loadimage(&rule, _T("rule.jpg"), 955, 651, 1);

    while (true)
    {
        putimage(0, 0, &rule);
        POINT pt;
        GetCursorPos(&pt);
        ScreenToClient(GetHWnd(), &pt);

        back.draw(pt.x, pt.y);
        FlushBatchDraw();

        if (((GetAsyncKeyState(VK_LBUTTON) & 0x8000) && back.isClicked(pt.x, pt.y)) || GetAsyncKeyState(VK_ESCAPE))
        {
            break;
        }
        Sleep(16);
    }
}

//游戏主体
void play_game(int init[7][7])
{
    ChessBoard cb;
    cb.reset(init);

    IMAGE classic;
    loadimage(&classic, _T("classic.jpg"), 955, 651, 1);

    RoundButton back =
    { 10, 10, 130, 60, 20, 20,
        RGB(0, 0, 0), RGB(180, 230, 250),
        RGB(0, 0, 0), RGB(120, 218, 218),
        BLACK, _T("返回菜单"), 30, _T("楷体")
    };

    RoundButton inition =
    { 10, 80, 130, 130, 20, 20,
        RGB(0, 0, 0), RGB(180, 230, 250),
        RGB(0, 0, 0), RGB(120, 218, 218),
        BLACK, _T("复原"), 30, _T("楷体")
    };

    RoundButton revoke =
    { 10, 150, 130, 200, 20, 20,
        RGB(0, 0, 0), RGB(180, 230, 250),
        RGB(0, 0, 0), RGB(120, 218, 218),
        BLACK, _T("撤销"), 30, _T("楷体")
    };

    int selected_x = -1, selected_y = -1;
    cb.draw(classic, selected_x, selected_y);

    while (true)
    {
        POINT pt;
        GetCursorPos(&pt);
        ScreenToClient(GetHWnd(), &pt);

        back.draw(pt.x, pt.y);
        inition.draw(pt.x, pt.y);
        revoke.draw(pt.x, pt.y);
        FlushBatchDraw();

        if (MouseHit())
        {
            MOUSEMSG msg = GetMouseMsg();
            if (msg.uMsg == WM_LBUTTONDOWN)
            {
                int j = (msg.x - offset_x + cell_size / 2) / cell_size;
                int i = (msg.y - offset_y + cell_size / 2) / cell_size;

                if (i >= 0 && i < 7 && j >= 0 && j < 7 && cb.getCell(i, j) != -1)
                {
                    if (selected_x == -1 && cb.getCell(i, j) == 1)
                    {
                        selected_x = j;
                        selected_y = i;
                    }
                    else
                    {
                        int dx = j;
                        int dy = i;

                        if ((abs(dx - selected_x) == 2 && dy == selected_y) ||
                            (abs(dy - selected_y) == 2 && dx == selected_x))
                        {
                            cb.move(selected_x, selected_y, dx, dy);
                        }

                        selected_x = selected_y = -1;
                    }
                    cb.draw(classic, selected_x, selected_y);
                }
            }
        }

        if (((GetAsyncKeyState(VK_LBUTTON) & 0x8000) && back.isClicked(pt.x, pt.y)) || GetAsyncKeyState(VK_ESCAPE))
        {
            break;
        }

        if ((GetAsyncKeyState(VK_LBUTTON) & 0x8000) && revoke.isClicked(pt.x, pt.y))
        {
            cb.restoreHistory();
            selected_x = selected_y = -1;
            cb.draw(classic, selected_x, selected_y);
        }

        if ((GetAsyncKeyState(VK_LBUTTON) & 0x8000) && inition.isClicked(pt.x, pt.y))
        {
            cb.reset(init);
            selected_x = selected_y = -1;
            cb.draw(classic, selected_x, selected_y);
        }

        int count = cb.countPieces();

        if (count == 1)
        {
            IMAGE happyend;
            loadimage(&happyend, _T("happyend.jpg"), 955, 651, 1);
            cleardevice();
            putimage(0, 0, &happyend);
            FlushBatchDraw();
            Sleep(2000);

            cb.reset(init);
            cb.draw(classic, selected_x, selected_y);
        }
        else if (!cb.canMove())
        {
            IMAGE badend;
            loadimage(&badend, _T("badend.jpg"), 955, 651, 1);
            cleardevice();
            putimage(0, 0, &badend);
            FlushBatchDraw();
            Sleep(2000);

            cb.reset(init);
            cb.draw(classic, selected_x, selected_y);
        }
    }
}

//残局页面
void endgame()
{
    RoundButton back =
    { 10, 10, 250, 80, 20, 20,
        RGB(0, 0, 0), RGB(180, 230, 250),
        RGB(0, 0, 0), RGB(120, 218, 218),
        BLACK, _T("返回菜单"), 50, _T("楷体")
    };

    RoundButton moon =
    { 350, 150, 605, 220, 20, 20,
        RGB(0, 0, 0), RGB(180, 230, 250),
 RGB(0, 0, 0), RGB(120, 218, 218),
        BLACK, _T("moon"), 50, _T("楷体")
    };

    RoundButton sun =
    { 350, 290, 605, 360, 20, 20,
        RGB(0, 0, 0), RGB(180, 230, 250),
        RGB(0, 0, 0), RGB(120, 218, 218),
        BLACK, _T("sun"), 50, _T("楷体")
    };

    RoundButton earth =
    { 350, 430, 605, 500, 20, 20,
        RGB(0, 0, 0), RGB(180, 230, 250),
        RGB(0, 0, 0), RGB(120, 218, 218),
        BLACK, _T("earth"), 50, _T("楷体")
    };

    IMAGE endgame;
    loadimage(&endgame, _T("endgame.jpg"), 955, 651, 1);

    while (true)
    {
        cleardevice();
        putimage(0, 0, &endgame);

        POINT pt;
        GetCursorPos(&pt);
        ScreenToClient(GetHWnd(), &pt);

        back.draw(pt.x, pt.y);
        moon.draw(pt.x, pt.y);
        sun.draw(pt.x, pt.y);
        earth.draw(pt.x, pt.y);
        FlushBatchDraw();

        if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
        {
            if (moon.isClicked(pt.x, pt.y))
            {
                int init[7][7] =
                {
                    {-1, -1, 0, 0, 0, -1, -1},
                    {-1, -1, 1, 1, 0, -1, -1},
                    {0, 0, 0, 0, 1, 1, 0},
                    {0, 0, 0, 1, 0, 0, 1},
                    {0, 0, 0, 0, 1, 1, 0},
                    {-1, -1, 0, 0, 0, -1, -1},
                    {-1, -1, 0, 0, 0, -1, -1}
                };
                play_game(init);
            }

            else if (sun.isClicked(pt.x, pt.y))
            {
                int init[7][7] =
                {
                    {-1, -1,  0,  0,  0, -1, -1},
                    {-1, -1,  0,  0,  0, -1, -1},
                    { 0,  0,  1,  1,  1,  0,  0},
                    { 0,  1,  1,  1,  1,  1,  0},
                    { 0,  0,  1,  1,  1,  0,  0},
                    {-1, -1,  0,  0,  0, -1, -1},
                    {-1, -1,  0,  0,  0, -1, -1}
                };
                play_game(init);
            }
            else if (earth.isClicked(pt.x, pt.y))
            {
                int init[7][7] =
                {
                    {-1, -1, 0, 0, 0, -1, -1},
                    {-1, -1, 0, 0, 0, -1, -1},
                    {0, 0, 1, 0, 1, 0, 0},
                    {0, 1, 0, 1, 0, 1, 0},
                    {0, 0, 1, 1, 1, 0, 0},
                    {-1, -1, 0, 1, 0, -1, -1},
                    {-1, -1, 0, 1, 0, -1, -1}
                };
                play_game(init);
            }

            else if ((GetAsyncKeyState(VK_LBUTTON) & 0x8000) && back.isClicked(pt.x, pt.y))
            {
                break;
            }
        }
        Sleep(16);
    }
}