//ֻ��main����

#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "game.h"
#include "utils.h"
using namespace std;

int main()
{
    char choice = '\0';
    SetConsoleTitle(TEXT("2048"));
    bool sign = true;
    while (sign)
    {
        print_menu();
        choice = _getche();
        switch (choice)
        {
        case 'a':
            play_game();
            break;
        case 'b':
            print_help();
            break;
        case 'c':
            print_exit();
            sign = false;
            break;
        default:
            cout << "\n�����������������" << endl;
            wait_for_enter();
        }
    }
    return 0;
}