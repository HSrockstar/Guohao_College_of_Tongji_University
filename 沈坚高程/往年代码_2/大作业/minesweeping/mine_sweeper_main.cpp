/*2253744 林觉凯 软工*/
#include "mine_sweeper.h"
/***************************************************************************
  函数名称：main()
  功    能：实现整体游戏的流程框架，调用相对应部分的函数；调整字体、控制台大小
  输入参数：无
  返 回 值：0
  说    明：主函数
***************************************************************************/
int main()
{
	cct_setfontsize("新宋体", 24);
	cct_setcolor(0, 7);
	cct_setconsoleborder(100, 30, 100, 30);
	while (1)
	{
		int choice = Main_menu();
		if (choice == 0)
		{
			putchar('0');
			break;
		}
		if (choice == 1 || choice == 2 || choice == 3 || choice == 4)
		{
			cct_cls();
			int difficulty = Sub_menu();
			cct_cls();
			if (difficulty == 1)
				Inner_difficulty_1(choice);
			else if (difficulty == 2)
				Inner_difficulty_2(choice);
			else
				Inner_difficulty_3(choice);
		}
		if (choice == 5 || choice == 6 || choice == 7 || choice == 8 || choice == 9)
		{
			cct_cls();
			int difficulty = Sub_menu();
			cct_cls();
			if (difficulty == 1)
				Pseudographics_dfficulty_1(choice);
			else if (difficulty == 2)
				Pseudographics_dfficulty_2(choice);
			else
				Pseudographics_dfficulty_3(choice);
		}
		cct_setcolor(0, 7);
		if (choice == 5 || choice == 6)
			cct_gotoxy(0, 52);
		cout << "按回车键继续...";
		while (_getch() != '\r');
		cct_cls();
		cct_setfontsize("新宋体", 24);
		cct_setconsoleborder(100, 30, 100, 30);
	}
	cout << endl;
	return 0;
}