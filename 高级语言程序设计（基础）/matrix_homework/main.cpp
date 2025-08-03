#include <iostream>
#include <conio.h>
#include <opencv2/opencv.hpp>
#include "matrix_operations.h"

using namespace cv;
using namespace std;

char ch;
char choice;

int main()
{
    while (true)
    {
        //进入新的循环，清屏，呼出菜单  
        system("cls");
        menu();

        //退出机制  
        if (choice == '0')
        {
            cout << "\n确定退出吗?如果确定退出请按Y或y" << endl;
            cin >> ch;
            if (ch == 'y' || ch == 'Y')
                break;
            else
                continue;
        }

        switch (choice)
        {
        case '1':
            matriplus();
            break;
        case '2':
            nummulti();
            break;
        case '3':
            matritrans();
            break;
        case '4':
            matrimulti();
            break;
        case '5':
            hadamulti();
            break;
        case '6':
            conv();
            break;
        case '7':
            demo();
            break;
        case '8':
            OUST();
            break;
        default:
            cout << "\n输入错误，请重新输入";
            cin.clear();
            cin.ignore(9223372036854775807, '\n');
            wait_for_enter();
            break;
        }
    }
    return 0;
}