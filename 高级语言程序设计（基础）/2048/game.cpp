//包括游戏实现的函数

#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "game.h"
#include "utils.h"
using namespace std;

int board[4][4];
int score;
int step;
unsigned char choice;

void play_game()
{
    bool sign_limit = true;
    game_init();
    print_interface(board, score, step);

    while (true)
    {
        choice = _getch();
        if (choice == 27)
        {
            break;
        }
        else
        {
            game_update(choice);
        }
        step++;
        print_random();
        print_interface(board, score, step);
        if (sign_limit)
        {
            if (game_check_limit(board, sign_limit))
            {
                break;
            }
            else
            {
                print_interface(board, score, step);
                continue;
            }
        }

        if (game_check_end(board))
        {
            cout << "已经失败啦，再接再厉吧！" << endl;
            wait_for_enter();
            break;
        }
    }
    print_exit();
}

void game_init()
{
    // 初始化棋盘、分数和步数
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            board[i][j] = 0;
        }
    }
    score = 0;
    step = 0;
    // 生成初始随机数
    print_random();
    print_random();
}

void game_update(unsigned char choice)
{
    int check = 0;
    while (!check)
    {
        if (choice == 224)
        {
            switch (_getch())
            {
            case 72:
                move_up(board,check,score);
                break;
            case 80:
                move_down(board,check, score);
                break;
            case 75:
                move_left(board, check, score);
                break;
            case 77:
                move_right(board, check, score);
                break;
            }
        }
    }
}

bool game_check_limit(int board[4][4],bool& sign_limit)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (board[i][j] == 2048)
            {
                sign_limit = false;
                cout << "您已到达2048,请问您是否继续？" << endl;
                cout << "如果您想退出，请按y；如果您想继续玩，请按n。" << endl;
                while (true)
                {
                    char ch = _getche();
                    if (ch == 'y')
                    {
                        return true;
                    }

                    else if (ch == 'n')
                    {
                        return false;
                    }

                    else
                    {
                        cout << "输入错误，请重新输入" << endl;
                        wait_for_enter();
                    }
                }
            }
        }
    }
    return false;
}

bool game_check_end(int board[4][4])
{
    for (int i = 0; i <= 3; i++)
    {
        for (int j = 0; j <= 3; j++)
        {
            if (board[i][j] == 0)
            {
                return false;
            }
        }
    }

    for (int i = 0; i <= 3; i++)
    {
        for (int j = 0; j <= 2; j++)
        {
            if (board[i][j] == board[i][j + 1])
            {
                return false;
            }
        }
    }
    
    for (int j = 0; j <= 3; j++)
    {
        for (int i = 0; i <= 2; i++)
        {
            if (board[i][j] == board[i+1][j])
            {
                return false;
            }
        }
    }

    return true;
}

void move_up(int board[4][4],int& check, int& score)
{
    for (int j = 0; j <= 3; j++)
    {
        for (int k = 2; k >= 0; k--)
        {
            for (int i = 0; i <= k; i++)
            {
                if (board[i][j] == 0 && board[i+1][j] != 0)
                {
                    board[i][j] = board[i+1][j];
                    board[i+1][j] = 0;
                    check++;
                }
            }
        }
    }

    for (int j = 0; j <= 3; j++)
    {
        for (int i = 0; i <= 2; i++)
        {
            if (board[i][j] == board[i+1][j] && board[i][j] != 0)
            {
                board[i][j] *= 2;
                board[i+1][j] = 0;
                check++;
                score += board[i][j];
            }
        }
    }

    for (int j = 0; j <= 3; j++)
    {
        for (int k = 2; k >= 0; k--)
        {
            for (int i = 0; i <= k; i++)
            {
                if (board[i][j] == 0 && board[i + 1][j] != 0)
                {
                    board[i][j] = board[i + 1][j];
                    board[i + 1][j] = 0;
                    check++;
                }
            }
        }
    }
}

void move_down(int board[4][4], int& check, int& score)
{
    for (int j = 0; j <= 3; j++)
    {
        for (int k = 1; k <= 3; k++)
        {
            for (int i = 3; i >= k; i--)
            {
                if (board[i][j] == 0 && board[i - 1][j] != 0)
                {
                    board[i][j] = board[i - 1][j];
                    board[i - 1][j] = 0;
                    check++;
                }
            }
        }
    }

    for (int j = 0; j <= 3; j++)
    {
        for (int i = 3; i >= 1; i--)
        {
            if (board[i][j] == board[i - 1][j] && board[i][j] != 0)
            {
                board[i][j] *= 2;
                board[i - 1][j] = 0;
                check++;
                score += board[i][j];
            }
        }
    }

    for (int j = 0; j <= 3; j++)
    {
        for (int k = 1; k <= 3; k++)
        {
            for (int i = 3; i >= k; i--)
            {
                if (board[i][j] == 0 && board[i - 1][j] != 0)
                {
                    board[i][j] = board[i - 1][j];
                    board[i - 1][j] = 0;
                    check++;
                }
            }
        }
    }
}

void move_left(int board[4][4], int& check, int& score)
{
    for (int i = 0; i <= 3; i++)
    {
        for (int k = 2; k >= 0; k--)
        {
            for (int j = 0; j <= k; j++)
            {
                if (board[i][j] == 0 && board[i][j + 1] != 0)
                {
                    board[i][j] = board[i][j + 1];
                    board[i][j + 1] = 0;
                    check++;
                }
            }
        }
    }

    for (int i = 0; i <= 3; i++)
    {
        for (int j = 0; j <= 2; j++)
        {
            if (board[i][j] == board[i][j + 1] && board[i][j] != 0)
            {
                board[i][j] *= 2;
                board[i][j + 1] = 0;
                check++;
                score += board[i][j];
            }
        }
    }

    for (int i = 0; i <= 3; i++)
    {
        for (int k = 2; k >= 0; k--)
        {
            for (int j = 0; j <= k; j++)
            {
                if (board[i][j] == 0 && board[i][j + 1] != 0)
                {
                    board[i][j] = board[i][j + 1];
                    board[i][j + 1] = 0;
                    check++;
                }
            }
        }
    }
}

void move_right(int board[4][4], int& check, int& score)
{
    for (int i = 0; i <= 3; i++)
    {
        for (int k = 1; k <= 3; k++)
        {
            for (int j = 3; j >= k; j--)
            {
                if (board[i][j] == 0 && board[i][j - 1] != 0)
                {
                    board[i][j] = board[i][j - 1];
                    board[i][j - 1] = 0;
                    check++;
                }
            }
        }
    }

    for (int i = 0; i <= 3; i++)
    {
        for (int j = 3; j >= 1; j--)
        {
            if (board[i][j] == board[i][j - 1] && board[i][j] != 0)
            {
                board[i][j] *= 2;
                board[i][j - 1] = 0;
                score += board[i][j];
                check++;
            }
        }
    }

    for (int i = 0; i <= 3; i++)
    {
        for (int k = 1; k <= 3; k++)
        {
            for (int j = 3; j >= k; j--)
            {
                if (board[i][j] == 0 && board[i][j - 1] != 0)
                {
                    board[i][j] = board[i][j - 1];
                    board[i][j - 1] = 0;
                    check++;
                }
            }
        }
    }
}