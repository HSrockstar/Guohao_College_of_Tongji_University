//�����������õĺ���

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
    cout << endl << "���س�������";
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
    cout << "                a.����ģʽ\n";
    cout << "                b.��Ϸ����\n";
    cout << "                c.�˳���Ϸ\n";
    SetConsoleTextAttribute(handle_out, FOREGROUND_BLUE | FOREGROUND_GREEN);
    cout << "********************************************\n";
    cout << "--------------------------------------------\n";
    SetConsoleTextAttribute(handle_out, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << "\n���������ѡ��(a-c):";
}

void print_help()
{
    system("CLS");
    HANDLE handle_out = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle_out, FOREGROUND_BLUE | FOREGROUND_GREEN);
    cout << "--------------------------------------------\n";
    cout << "********************************************\n\n";
    SetConsoleTextAttribute(handle_out, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "����˵����\n\n";
    cout << "������   ������  ������  ������  ESC�����˳�\n\n";
    cout << "��Ϸ���ܣ�\n\n";
    cout << "ÿ��ѡ��һ�������ƶ����ƶ�ʱ������÷���£\n";
    cout << "��ͬ���ֿɺϲ����ƶ���ո񴦻������������2/4\n";
    cout << "����õ�����2048������Ϸʤ��!\n";
    cout << "������̱������������޷������ƶ�������Ϸʧ��!\n\n";
    SetConsoleTextAttribute(handle_out, FOREGROUND_BLUE | FOREGROUND_GREEN);
    cout << "********************************************\n";
    cout << "--------------------------------------------\n";
    SetConsoleTextAttribute(handle_out, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    wait_for_enter();
}

void print_exit()
{
    cout << "\n�˳���";
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
    cout << "            ������" << setw(6) << score << "              ������" << setw(6) << step << endl;
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
    cout << "            ������   ������  ������  ������  ESC�����˳�\n\n";
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