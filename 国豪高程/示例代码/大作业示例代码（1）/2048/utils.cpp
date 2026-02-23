//包括辅助作用的函数

#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <conio.h>
#include <cstdlib> 
#include <ctime>
#include "game.h"
#include "utils.h"
using namespace std;

void wait_for_enter()
{
    cout << endl << "按回车键继续";
    while (_getch() != '\r')
        ;
    cout << endl << endl;
}

void print_menu()
{
    system("CLS");
    HANDLE handle_out = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle_out, FOREGROUND_BLUE | FOREGROUND_GREEN);
    cout << "--------------------------------------------\n";
    cout << "********************************************\n";
    SetConsoleTextAttribute(handle_out, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "                   2048\n";
    cout << "                a.经典模式\n";
    cout << "                b.游戏规则\n";
    cout << "                c.退出游戏\n";
    SetConsoleTextAttribute(handle_out, FOREGROUND_BLUE | FOREGROUND_GREEN);
    cout << "********************************************\n";
    cout << "--------------------------------------------\n";
    SetConsoleTextAttribute(handle_out, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << "\n请输入你的选择(a-c):";
}

void print_help()
{
    system("CLS");
    HANDLE handle_out = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle_out, FOREGROUND_BLUE | FOREGROUND_GREEN);
    cout << "--------------------------------------------\n";
    cout << "********************************************\n\n";
    SetConsoleTextAttribute(handle_out, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "操作说明：\n\n";
    cout << "↓：下   ←：左  ↑：上  →：右  ESC键：退出\n\n";
    cout << "游戏介绍：\n\n";
    cout << "每次选择一个方向移动，移动时数字向该方向靠拢\n";
    cout << "相同数字可合并，移动后空格处会生成随机数字2/4\n";
    cout << "如果得到数字2048，则游戏胜利!\n";
    cout << "如果棋盘被数字填满，无法进行移动，则游戏失败!\n\n";
    SetConsoleTextAttribute(handle_out, FOREGROUND_BLUE | FOREGROUND_GREEN);
    cout << "********************************************\n";
    cout << "--------------------------------------------\n";
    SetConsoleTextAttribute(handle_out, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    wait_for_enter();
}

void print_exit()
{
    cout << "\n退出中";
    for (int i = 4; i > 0; --i)
    {
        Sleep(200);
        cout << ".";
    }
}

void print_interface(int board[4][4], int score, int step)
{
    system("CLS");
    HANDLE handle_out = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle_out, FOREGROUND_RED | FOREGROUND_GREEN);
    cout << "            --------------------------------------------\n";
    cout << "            分数：" << setw(6) << score << "              步数：" << setw(6) << step << endl;
    cout << "            --------------------------------------------\n";
    cout << "            ********************************************\n";
    SetConsoleTextAttribute(handle_out, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "                       |----|----|----|----|\n";

    for (int i = 0; i < 4; i++)
    {
        cout << "                       |";
        for (int j = 0; j < 4; j++)
        {
            if (board[i][j] != 0)
            {
                cout << setw(4) << board[i][j] << "|";
            }
            else
            {
                cout << "    |";
            }
        }
        cout << "\n                       |----|----|----|----|\n";
    }

    SetConsoleTextAttribute(handle_out, FOREGROUND_RED | FOREGROUND_GREEN);
    cout << "            ********************************************\n";
    cout << "            --------------------------------------------\n";
    cout << "            ↓：下   ←：左  ↑：上  →：右  ESC键：退出\n\n";
    SetConsoleTextAttribute(handle_out, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
}

void print_random()
{
    int empty[16][2] = { 0 };
    int empty_count = 0;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (board[i][j] == 0)
            {
                empty[empty_count][0] = i;
                empty[empty_count][1] = j;
                empty_count++;
            }
        }
    }

    if (empty_count > 0)
    {
        srand(static_cast<unsigned int>(time(0)));
        int r = rand() % empty_count;
        int x = empty[r][0];
        int y = empty[r][1];
        board[x][y] = (rand() % 2)* 2 + 2 ;
    }
}