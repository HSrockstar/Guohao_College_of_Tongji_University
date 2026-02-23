/*2253744 林觉凯 软工*/
#include "hanoi.h"
using namespace std;
/* ----------------------------------------------------------------------------------

     本文件功能：
	1、放main函数
	2、初始化屏幕
	3、调用菜单函数（hanoi_menu.cpp中）并返回选项
	4、根据选项调用菜单各项对应的执行函数（hanoi_multiple_solutions.cpp中）

     本文件要求：
	1、不允许定义全局变量（含外部全局和静态全局，const及#define不在限制范围内）
	2、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	3、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */

/***************************************************************************
  函数名称：main()
  功    能：主函数调用菜单各项对应的执行函数
  输入参数：无
  返 回 值：0
  说    明：程序的主体流程框架
***************************************************************************/
int main()
{
	/* demo中首先执行此句，将cmd窗口设置为40行x120列（缓冲区宽度120列，行数9000行，即cmd窗口右侧带有垂直滚动杆）*/
	cct_setconsoleborder(120, 40, 120, 9000);
	char choice;
	while (1)
	{
		choice = Hanoi_Menu();
		if (choice == '0')
		{
			cct_gotoxy(0, 37);
			return 0;
		}		
		cout << endl << endl;
		switch (choice)
		{
		case '1':
			Choice_1();
			cout << endl;
			break;
		case '2':
			Choice_2();
			cout << endl;
			break;
		case '3':
			Choice_3();
			cout << endl;
			break;
		case '4':
			Choice_4();
			cout << endl;
			break;
		case '5':
			Choice_5();
			break;
		case '6':
			Choice_6();
			break;
		case '7':
			Choice_7();
			break;
		case '8':
			Choice_8();
			break;
		case '9':
			Choice_9();
			break;
		}
		cct_setcolor(COLOR_BLACK, COLOR_WHITE);
		cct_setcursor(CURSOR_VISIBLE_NORMAL);
		while (1)
		{
			if (choice >= '1' && choice <= '3')
			{
				int x, y;
				cct_getxy(x, y);
				cct_gotoxy(0, y);
				cct_showstr(0, y, "按回车键继续", COLOR_BLACK, COLOR_WHITE, 1);
			}
			else
				cct_showstr(0, 38, "按回车键继续", COLOR_BLACK, COLOR_WHITE, 1);
			char ret = _getch();
			if (ret == '\r')
			{
				cct_cls();
				break;
			}
		}
	}
	return 0;
}