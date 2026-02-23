/*2253744 林觉凯 软工*/
#include "mine_sweeper.h"
/***************************************************************************
  函数名称：Print_specification()
  功    能：打印4选项中的各项特殊输入说明
  输入参数：无
  返 回 值：无
  说    明：无
***************************************************************************/
void Print_specification()
{
	cout << "特殊输入说明：& - 游戏已运行时间(单字符即可，不需要加坐标)" << endl;
	cout << "              ! - 标记该坐标为雷(例：!E3)" << endl;
	cout << "              # - 取消标记      (例：#E3)" << endl;
	cout << "请输入（坐标必须先行后列，严格区分大小写，例：G1/Af，按Q/q退出）：";
}
/***************************************************************************
  函数名称：Print_InitArray_1()
  功    能：打印3.4选项游戏刚开始的雷盘
  输入参数：无
  返 回 值：无
  说    明：一开始的雷盘都是“X”
***************************************************************************/
void Print_InitArray_1()
{
	for (int i = 1; i < 10; i++)
	{
		char alph = 64;
		cout << char(alph + i) << " |";
		cout << "X X X X X X X X X" << endl;
	}
	cout << endl << endl;
}
/***************************************************************************
  函数名称：Print_InitArray_2()
  功    能：打印3.4选项游戏刚开始的雷盘
  输入参数：无
  返 回 值：无
  说    明：一开始的雷盘都是“X”
***************************************************************************/
void Print_InitArray_2()
{
	for (int i = 1; i < 17; i++)
	{
		char alph = 64;
		cout << (char)(alph + i) << " |";
		cout << "X X X X X X X X X X X X X X X X" << endl;
	}
	cout << endl << endl;
}
/***************************************************************************
  函数名称：Print_InitArray_3()
  功    能：打印3.4选项游戏刚开始的雷盘
  输入参数：无
  返 回 值：无
  说    明：一开始的雷盘都是“X”
***************************************************************************/
void Print_InitArray_3()
{
	for (int i = 1; i < 17; i++)
	{
		char alph = 64;
		cout << (char)(alph + i) << " |";
		cout << "X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X" << endl;
	}
	cout << endl << endl;
}
/***************************************************************************
  函数名称：Color_of_Inner(char ch)
  功    能：打印打开后每个点对应的雷数和该数字的颜色
  输入参数：char ch
  返 回 值：无
  说    明：雷数不同的数字颜色也是不一样的
***************************************************************************/
void Color_of_Inner(char ch)
{
	switch (ch)
	{
	case '0':
		cct_setcolor(14, 0);
		break;
	case '1':
		cct_setcolor(14, 1);
		break;
	case '2':
		cct_setcolor(14, 2);
		break;
	case '3':
		cct_setcolor(14, 3);
		break;
	case '4':
		cct_setcolor(14, 4);
		break;
	case '5':
		cct_setcolor(14, 5);
		break;
	case '6':
		cct_setcolor(14, 6);
		break;
	case '7':
		cct_setcolor(14, 7);
		break;
	case '8':
		cct_setcolor(14, 8);
		break;
	case 'X':
		cct_setcolor(0, 7);
		break;
	case '*':
		cct_setcolor(0, 7);
		break;
	}
	cout << ch;
	cct_setcolor(0, 7);
	cout << " ";
}
/***************************************************************************
  函数名称：Inner_difficulty_1(int choice)
  功    能：完成内部数组难度1部分（选项1-4）功能的主要函数
  输入参数：选项choice
  返 回 值：无
  说    明：调用内部数组中的其它函数，完成主要功能
***************************************************************************/
void Inner_difficulty_1(int choice)
{
	clock_t Startpoint, Endpoint;
	Startpoint = Endpoint = clock();
	char boomarr_1[11][11] = { 0 };		//真实的雷数组
	char cover_1[11][11] = { 0 };		//用于输出的覆盖数组
	char flag_1[11][11] = { 0 };		//判断某个点是否“打开”的数组
	char mark_1[11][11] = { 0 };		//标记为雷的数组
	int keydown1 = 0;
	int keydown2 = 0;
	cout << "内部数组：" << endl;
	cout << "  |1 2 3 4 5 6 7 8 9" << endl;
	cout << "--+--------------------" << endl;
	if (choice == 2 || choice == 3)
	{
		Print_InitArray_1();
		cout << "输入非雷位置的行列坐标（先行后列，严格区分大小写，例：G1/Af，按Q/q退出）：";
		Input_1(choice, keydown1, keydown2, flag_1, mark_1);
		if (keydown1 == 'q' || keydown1 == 'Q')
		{
			cout << endl;
			return;
		}
		cout << endl << endl;
	}
	if (choice == 4)
	{
		Print_InitArray_1();
		Print_specification();
		Input_1(choice, keydown1, keydown2, flag_1, mark_1);
		while (keydown1 == '&')
		{
			Endpoint = clock();
			cout << endl << "已运行时间：" << (double)(Endpoint - Startpoint) / CLOCKS_PER_SEC << "秒" << endl;
			Print_specification();
			Input_1(choice, keydown1, keydown2, flag_1, mark_1);
		}
		if (keydown1 == 'q' || keydown1 == 'Q')
		{
			cout << endl;
			return;
		}
		cout << endl << endl;
		while (mark_1[keydown1][keydown2] != 0)
		{
			cout << "当前数组：" << endl;
			cout << "  |1 2 3 4 5 6 7 8 9" << endl;
			cout << "--+--------------------" << endl;
			for (int i = 1; i < 10; i++)
			{
				char alph = 64;
				cout << (char)(alph + i) << " |";
				for (int j = 1; j < 10; j++)
				{
					if (mark_1[i][j] == 1)
					{
						cct_setcolor(4, 7);
						cout << 'X';
						cct_setcolor(0, 7);
						cout << " ";
					}
					else
						cout << 'X' << " ";
				}
				cout << endl;
			}
			cout << endl << endl;
			Print_specification();
			Input_1(choice, keydown1, keydown2, flag_1, mark_1);
			while (keydown1 == '&')
			{
				Endpoint = clock();
				cout << endl << "已运行时间：" << (double)(Endpoint - Startpoint) / CLOCKS_PER_SEC << "秒" << endl;
				Print_specification();
				Input_1(choice, keydown1, keydown2, flag_1, mark_1);
			}
			if (keydown1 == 'q' || keydown1 == 'Q')
			{
				cout << endl;
				return;
			}
			cout << endl << endl;
		}
	}
	Reset_markarr_1(mark_1);
	Initarr_1(boomarr_1, keydown1, keydown2, choice);
	if (choice == 1)
		Inner_Output_1(choice, boomarr_1, cover_1, mark_1);
	if (choice == 2)
	{
		Expand_map_1(boomarr_1, cover_1, flag_1, mark_1, keydown1, keydown2);
		Inner_Output_1(choice, boomarr_1, cover_1, mark_1);
	}
	if (choice == 3 || choice == 4)
	{
		Expand_map_1(boomarr_1, cover_1, flag_1, mark_1, keydown1, keydown2);
		Inner_Output_1(choice, boomarr_1, cover_1, mark_1);
		Inner_game_1(choice, boomarr_1, cover_1, flag_1, mark_1, keydown1, keydown2, Startpoint, Endpoint);
	}
}
/***************************************************************************
  函数名称：Inner_difficulty_2(int choice)
  功    能：完成内部数组难度2部分（选项1-4）功能的主要函数
  输入参数：选项choice
  返 回 值：无
  说    明：调用内部数组中的其它函数，完成主要功能
***************************************************************************/
void Inner_difficulty_2(int choice)
{
	clock_t Startpoint, Endpoint;
	Startpoint = Endpoint = clock();
	char boomarr_2[18][18] = { 0 };			//真实的雷数组
	char cover_2[18][18] = { 0 };			//用于输出的覆盖数组
	char flag_2[18][18] = { 0 };			//判断某个点是否“打开”的数组
	char mark_2[18][18] = { 0 };			//标记为雷的数组
	int keydown1 = 0;
	int keydown2 = 0;
	cout << "内部数组：" << endl;
	cout << "  |1 2 3 4 5 6 7 8 9 a b c d e f g" << endl;
	cout << "--+----------------------------------" << endl;
	if (choice == 2 || choice == 3)
	{
		Print_InitArray_2();
		cout << "输入非雷位置的行列坐标（先行后列，严格区分大小写，例：G1/Af，按Q/q退出）：";
		Input_2(choice, keydown1, keydown2, flag_2, mark_2);
		if (keydown1 == 'q' || keydown1 == 'Q')
		{
			cout << endl;
			return;
		}
		cout << endl << endl;
	}
	if (choice == 4)
	{
		Print_InitArray_2();
		Print_specification();
		Input_2(choice, keydown1, keydown2, flag_2, mark_2);
		while (keydown1 == '&')
		{
			Endpoint = clock();
			cout << endl << "已运行时间：" << (double)(Endpoint - Startpoint) / CLOCKS_PER_SEC << "秒" << endl;
			Print_specification();
			Input_2(choice, keydown1, keydown2, flag_2, mark_2);
		}
		if (keydown1 == 'q' || keydown1 == 'Q')
		{
			cout << endl;
			return;
		}
		cout << endl << endl;
		while (mark_2[keydown1][keydown2] != 0)
		{
			cout << "当前数组：" << endl;
			cout << "  |1 2 3 4 5 6 7 8 9 a b c d e f g" << endl;
			cout << "--+----------------------------------" << endl;
			for (int i = 1; i < 17; i++)
			{
				char alph = 64;
				cout << (char)(alph + i) << " |";
				for (int j = 1; j < 17; j++)
				{
					if (mark_2[i][j] == 1)
					{
						cct_setcolor(4, 7);
						cout << 'X';
						cct_setcolor(0, 7);
						cout << ' ';
					}
					else
						cout << 'X' << ' ';
				}
				cout << endl;
			}
			cout << endl << endl;
			Print_specification();
			Input_2(choice, keydown1, keydown2, flag_2, mark_2);
			while (keydown1 == '&')
			{
				Endpoint = clock();
				cout << endl << "已运行时间：" << (double)(Endpoint - Startpoint) / CLOCKS_PER_SEC << "秒" << endl;
				Print_specification();
				Input_2(choice, keydown1, keydown2, flag_2, mark_2);
			}
			if (keydown1 == 'q' || keydown1 == 'Q')
			{
				cout << endl;
				return;
			}
			cout << endl << endl;
		}
	}
	Reset_markarr_2(mark_2);
	Initarr_2(boomarr_2, keydown1, keydown2, choice);
	if (choice == 1)
		Inner_Output_2(choice, boomarr_2, cover_2, mark_2);
	if (choice == 2)
	{
		Expand_map_2(boomarr_2, cover_2, flag_2, mark_2, keydown1, keydown2);
		Inner_Output_2(choice, boomarr_2, cover_2, mark_2);
	}
	if (choice == 3 || choice == 4)
	{
		Expand_map_2(boomarr_2, cover_2, flag_2, mark_2, keydown1, keydown2);
		Inner_Output_2(choice, boomarr_2, cover_2, mark_2);
		Inner_game_2(choice, boomarr_2, cover_2, flag_2, mark_2, keydown1, keydown2, Startpoint, Endpoint);
	}
}
/***************************************************************************
  函数名称：Inner_difficulty_3(int choice)
  功    能：完成内部数组难度3部分（选项1-4）功能的主要函数
  输入参数：选项choice
  返 回 值：无
  说    明：调用内部数组中的其它函数，完成主要功能
***************************************************************************/
void Inner_difficulty_3(int choice)
{
	clock_t Startpoint, Endpoint;
	Startpoint = Endpoint = clock();
	char boomarr_3[18][32] = { 0 };			//真实的雷数组
	char cover_3[18][32] = { 0 };			//用于输出的覆盖数组	
	char flag_3[18][32] = { 0 };			//判断某个点是否“打开”的数组
	char mark_3[18][32] = { 0 };			//标记为雷的数组
	int keydown1 = 0;
	int keydown2 = 0;
	cout << "内部数组：" << endl;
	cout << "  |1 2 3 4 5 6 7 8 9 a b c d e f g h i j k l m n o p q r s t u" << endl;
	cout << "--+--------------------------------------------------------------" << endl;
	if (choice == 2 || choice == 3)
	{
		Print_InitArray_3();
		cout << "输入非雷位置的行列坐标（先行后列，严格区分大小写，例：G1/Af，按Q/q退出）：";
		Input_3(choice, keydown1, keydown2, flag_3, mark_3);
		if (keydown1 == 'q' || keydown1 == 'Q')
		{
			cout << endl;
			return;
		}
		cout << endl << endl;
	}
	if (choice == 4)
	{
		Print_InitArray_3();
		Print_specification();
		Input_3(choice, keydown1, keydown2, flag_3, mark_3);
		while (keydown1 == '&')
		{
			Endpoint = clock();
			cout << endl << "已运行时间：" << (double)(Endpoint - Startpoint) / CLOCKS_PER_SEC << "秒" << endl;
			Print_specification();
			Input_3(choice, keydown1, keydown2, flag_3, mark_3);
		}
		if (keydown1 == 'q' || keydown1 == 'Q')
		{
			cout << endl;
			return;
		}
		cout << endl << endl;
		while (mark_3[keydown1][keydown2] != 0)
		{
			cout << "当前数组：" << endl;
			cout << "  |1 2 3 4 5 6 7 8 9 a b c d e f g h i j k l m n o p q r s t u" << endl;
			cout << "--+--------------------------------------------------------------" << endl;
			for (int i = 1; i < 17; i++)
			{
				char alph = 64;
				cout << (char)(alph + i) << " |";
				for (int j = 1; j < 31; j++)
				{
					if (mark_3[i][j] == 1)
					{
						cct_setcolor(4, 7);
						cout << 'X';
						cct_setcolor(0, 7);
						cout << ' ';
					}
					else
						cout << 'X' << ' ';
				}
				cout << endl;
			}
			cout << endl << endl;
			Print_specification();
			Input_3(choice, keydown1, keydown2, flag_3, mark_3);
			while (keydown1 == '&')
			{
				Endpoint = clock();
				cout << endl << "已运行时间：" << (double)(Endpoint - Startpoint) / CLOCKS_PER_SEC << "秒" << endl;
				Print_specification();
				Input_3(choice, keydown1, keydown2, flag_3, mark_3);
			}
			if (keydown1 == 'q' || keydown1 == 'Q')
			{
				cout << endl;
				return;
			}
			cout << endl << endl;
		}
	}
	Reset_markarr_3(mark_3);
	Initarr_3(boomarr_3, keydown1, keydown2, choice);
	if (choice == 1)
		Inner_Output_3(choice, boomarr_3, cover_3, mark_3);
	if (choice == 2)
	{
		Expand_map_3(boomarr_3, cover_3, flag_3, mark_3, keydown1, keydown2);
		Inner_Output_3(choice, boomarr_3, cover_3, mark_3);
	}
	if (choice == 3 || choice == 4)
	{
		Expand_map_3(boomarr_3, cover_3, flag_3, mark_3, keydown1, keydown2);
		Inner_Output_3(choice, boomarr_3, cover_3, mark_3);
		Inner_game_3(choice, boomarr_3, cover_3, flag_3, mark_3, keydown1, keydown2, Startpoint, Endpoint);
	}
}
/***************************************************************************
  函数名称：Input_1(int choice, int& keydown1, int& keydown2, char flag_1[11][11], char mark_1[11][11])
  功    能：完成内部数组难度1部分输入功能的主要函数
  输入参数：int choice, int& keydown1, int& keydown2, char flag_1[11][11], char mark_1[11][11]
  返 回 值：无
  说    明：choice代表不同选项有着不同的输入规则（4的输入最多），输入后可能改变flag_1和mark_1（被标记后不会再被“打开”，故该位置的flag_1和mark_1会变化）
***************************************************************************/
void Input_1(int choice, int& keydown1, int& keydown2, char flag_1[11][11], char mark_1[11][11])
{
	while (1)
	{
		keydown1 = _getch();
		if (choice == 4)
		{
			if (keydown1 == '&')
			{
				putchar('&');
				return;
			}
			if (keydown1 == '!')
			{
				putchar('!');
				while (1)
				{
					keydown1 = _getch();
					if (keydown1 >= 'A' && keydown1 <= 'I')
					{
						cout << (char)(keydown1);
						keydown1 = keydown1 - 64;
						break;
					}
				}
				while (1)
				{
					keydown2 = _getch();
					if (keydown2 >= '1' && keydown2 <= '9')
					{
						cout << (char)(keydown2);
						keydown2 = keydown2 - 48;
						break;
					}
				}
				if (flag_1[keydown1][keydown2] == 0)
					mark_1[keydown1][keydown2] = 1;
				return;
			}
			if (keydown1 == '#')
			{
				putchar('#');
				while (1)
				{
					keydown1 = _getch();
					if (keydown1 >= 'A' && keydown1 <= 'I')
					{
						cout << (char)(keydown1);
						keydown1 = keydown1 - 64;
						break;
					}
				}
				while (1)
				{
					keydown2 = _getch();
					if (keydown2 >= '1' && keydown2 <= '9')
					{
						cout << (char)(keydown2);
						keydown2 = keydown2 - 48;
						break;
					}
				}
				if (flag_1[keydown1][keydown2] == 0 || flag_1[keydown1][keydown2] == 1 && mark_1[keydown1][keydown2] == 1)
					mark_1[keydown1][keydown2] = 2;
				return;
			}
		}
		if (keydown1 == 'q' || keydown1 == 'Q')
		{
			cout << (char)(keydown1);
			return;
		}
		if (keydown1 >= 'A' && keydown1 <= 'I')
		{
			cout << (char)(keydown1);
			keydown1 = keydown1 - 64;
			break;
		}
	}
	while (1)
	{
		keydown2 = _getch();
		if (keydown2 >= '1' && keydown2 <= '9')
		{
			cout << (char)(keydown2);
			keydown2 = keydown2 - 48;
			break;
		}
	}
	if (mark_1[keydown1][keydown2] == 2)
		mark_1[keydown1][keydown2] = 0;
}
/***************************************************************************
  函数名称：Input_2(int choice, int& keydown1, int& keydown2, char flag_2[18][18], char mark_2[18][18])
  功    能：完成内部数组难度2部分输入功能的主要函数
  输入参数：int choice, int& keydown1, int& keydown2, char flag_2[18][18], char mark_2[18][18]
  返 回 值：无
  说    明：choice代表不同选项有着不同的输入规则（4的输入最多），输入后可能改变flag_1和mark_1（被标记后不会再被“打开”，故该位置的flag_1和mark_1会变化）
***************************************************************************/
void Input_2(int choice, int& keydown1, int& keydown2, char flag_2[18][18], char mark_2[18][18])
{
	while (1)
	{
		keydown1 = _getch();
		if (choice == 4)
		{
			if (keydown1 == '&')
			{
				putchar('&');
				return;
			}
			if (keydown1 == '!')
			{
				putchar('!');
				while (1)
				{
					keydown1 = _getch();
					if (keydown1 >= 'A' && keydown1 <= 'P')
					{
						cout << (char)(keydown1);
						keydown1 = keydown1 - 64;
						break;
					}
				}
				while (1)
				{
					keydown2 = _getch();
					if (keydown2 >= '1' && keydown2 <= '9')
					{
						cout << (char)(keydown2);
						keydown2 = keydown2 - 48;
						break;
					}
					if (keydown2 >= 'a' && keydown2 <= 'g')
					{
						cout << (char)(keydown2);
						keydown2 = keydown2 - 87;
						break;
					}
				}
				if (flag_2[keydown1][keydown2] == 0)
					mark_2[keydown1][keydown2] = 1;
				return;
			}
			if (keydown1 == '#')
			{
				putchar('#');
				while (1)
				{
					keydown1 = _getch();
					if (keydown1 >= 'A' && keydown1 <= 'P')
					{
						cout << (char)(keydown1);
						keydown1 = keydown1 - 64;
						break;
					}
				}
				while (1)
				{
					keydown2 = _getch();
					if (keydown2 >= '1' && keydown2 <= '9')
					{
						cout << (char)(keydown2);
						keydown2 = keydown2 - 48;
						break;
					}
					if (keydown2 >= 'a' && keydown2 <= 'g')
					{
						cout << (char)(keydown2);
						keydown2 = keydown2 - 87;
						break;
					}
				}
				if (flag_2[keydown1][keydown2] == 0 || flag_2[keydown1][keydown2] == 1 && mark_2[keydown1][keydown2] == 1)
					mark_2[keydown1][keydown2] = 2;
				return;
			}
		}
		if (keydown1 == 'q' || keydown1 == 'Q')
		{
			cout << (char)(keydown1);
			return;
		}
		if (keydown1 >= 'A' && keydown1 <= 'P')
		{
			cout << (char)(keydown1);
			keydown1 = keydown1 - 64;
			break;
		}
	}
	while (1)
	{
		keydown2 = _getch();
		if (keydown2 >= '1' && keydown2 <= '9')
		{
			cout << (char)(keydown2);
			keydown2 = keydown2 - 48;
			break;
		}
		if (keydown2 >= 'a' && keydown2 <= 'g')
		{
			cout << (char)(keydown2);
			keydown2 = keydown2 - 87;
			break;
		}
	}
	if (mark_2[keydown1][keydown2] == 2)
		mark_2[keydown1][keydown2] = 0;
}
/***************************************************************************
  函数名称：Input_3(int choice, int& keydown1, int& keydown2, char flag_3[18][32], char mark_3[18][32])
  功    能：完成内部数组难度3部分输入功能的主要函数
  输入参数：int choice, int& keydown1, int& keydown2, char flag_3[18][32], char mark_3[18][32]
  返 回 值：无
  说    明：choice代表不同选项有着不同的输入规则（4的输入最多），输入后可能改变flag_1和mark_1（被标记后不会再被“打开”，故该位置的flag_1和mark_1会变化）
***************************************************************************/
void Input_3(int choice, int& keydown1, int& keydown2, char flag_3[18][32], char mark_3[18][32])
{
	while (1)
	{
		keydown1 = _getch();
		if (choice == 4)
		{
			if (keydown1 == '&')
			{
				putchar('&');
				return;
			}
			if (keydown1 == '!')
			{
				putchar('!');
				while (1)
				{
					keydown1 = _getch();
					if (keydown1 >= 'A' && keydown1 <= 'P')
					{
						cout << (char)(keydown1);
						keydown1 = keydown1 - 64;
						break;
					}
				}
				while (1)
				{
					keydown2 = _getch();
					if (keydown2 >= '1' && keydown2 <= '9')
					{
						cout << (char)(keydown2);
						keydown2 = keydown2 - 48;
						break;
					}
					if (keydown2 >= 'a' && keydown2 <= 'u')
					{
						cout << (char)(keydown2);
						keydown2 = keydown2 - 87;
						break;
					}
				}
				if (flag_3[keydown1][keydown2] == 0)
					mark_3[keydown1][keydown2] = 1;
				return;
			}
			if (keydown1 == '#')
			{
				putchar('#');
				while (1)
				{
					keydown1 = _getch();
					if (keydown1 >= 'A' && keydown1 <= 'P')
					{
						cout << (char)(keydown1);
						keydown1 = keydown1 - 64;
						break;
					}
				}
				while (1)
				{
					keydown2 = _getch();
					if (keydown2 >= '1' && keydown2 <= '9')
					{
						cout << (char)(keydown2);
						keydown2 = keydown2 - 48;
						break;
					}
					if (keydown2 >= 'a' && keydown2 <= 'u')
					{
						cout << (char)(keydown2);
						keydown2 = keydown2 - 87;
						break;
					}
				}
				if (flag_3[keydown1][keydown2] == 0 || flag_3[keydown1][keydown2] == 1 && mark_3[keydown1][keydown2] == 1)
					mark_3[keydown1][keydown2] = 2;
				return;
			}
		}
		if (keydown1 == 'q' || keydown1 == 'Q')
		{
			cout << (char)(keydown1);
			return;
		}
		if (keydown1 >= 'A' && keydown1 <= 'P')
		{
			cout << (char)(keydown1);
			keydown1 = keydown1 - 64;
			break;
		}
	}
	while (1)
	{
		keydown2 = _getch();
		if (keydown2 >= '1' && keydown2 <= '9')
		{
			cout << (char)(keydown2);
			keydown2 = keydown2 - 48;
			break;
		}
		if (keydown2 >= 'a' && keydown2 <= 'u')
		{
			cout << (char)(keydown2);
			keydown2 = keydown2 - 87;
			break;
		}
	}
	if (mark_3[keydown1][keydown2] == 2)
		mark_3[keydown1][keydown2] = 0;
}
/***************************************************************************
  函数名称：Inner_Output_1(int choice, char boomarr_1[11][11], char cover_1[11][11], char mark_1[11][11])
  功    能：完成内部数组难度1部分输出功能的主要函数
  输入参数：int choice, char boomarr_1[11][11], char cover_1[11][11], char mark_1[11][11]
  返 回 值：无
  说    明：输出需要注意到这个点是否被标记、是雷还是非雷
***************************************************************************/
void Inner_Output_1(int choice, char boomarr_1[11][11], char cover_1[11][11], char mark_1[11][11])
{
	if (choice == 1)
	{
		for (int i = 1; i < 10; i++)
		{
			int alph = 64;
			cout << (char)(alph + i) << " |";
			for (int j = 1; j < 10; j++)
				cout << boomarr_1[i][j] << " ";
			cout << endl;
		}
		cout << endl << endl;
	}
	if (choice == 2 || choice == 3 || choice == 4)
	{
		if (choice == 2)
			cout << "点开后的数组：" << endl;
		if (choice == 3 || choice == 4)
			cout << "当前数组：" << endl;
		cout << "  |1 2 3 4 5 6 7 8 9" << endl << "--+--------------------" << endl;
		for (int i = 1; i < 10; i++)
		{
			int alph = 64;
			cout << (char)(alph + i) << " |";
			for (int j = 1; j < 10; j++)
			{
				if (mark_1[i][j] == 1)
				{
					cct_setcolor(4, 7);
					cout << cover_1[i][j];
					cct_setcolor(0, 7);
					cout << " ";
				}
				else
					Color_of_Inner(cover_1[i][j]);
			}
			cout << endl;
		}
		cout << endl << endl;
	}
}
/***************************************************************************
  函数名称：Inner_Output_2(int choice, char boomarr_2[18][18],char cover_2[18][18], char mark_2[18][18])
  功    能：完成内部数组难度2部分输出功能的主要函数
  输入参数：int choice, char boomarr_2[18][18],char cover_2[18][18], char mark_2[18][18]
  返 回 值：无
  说    明：输出需要注意到这个点是否被标记、是雷还是非雷
***************************************************************************/
void Inner_Output_2(int choice, char boomarr_2[18][18],char cover_2[18][18], char mark_2[18][18])
{
	if (choice == 1)
	{
		for (int i = 1; i < 17; i++)
		{
			int alph = 64;
			cout << (char)(alph + i) << " |";
			for (int j = 1; j < 17; j++)
				cout << boomarr_2[i][j] << " ";
			cout << endl;
		}
		cout << endl << endl;
	}
	if (choice == 2 || choice == 3 || choice == 4)
	{
		if (choice == 2)
			cout << "点开后的数组：" << endl;
		if (choice == 3 || choice == 4)
			cout << "当前数组：" << endl;
		cout << "  |1 2 3 4 5 6 7 8 9 a b c d e f g" << endl << "--+---------------------------------" << endl;
		for (int i = 1; i < 17; i++)
		{
			int alph = 64;
			cout << (char)(alph + i) << " |";
			for (int j = 1; j < 17; j++)
			{
				if (mark_2[i][j] == 1)
				{
					cct_setcolor(4, 7);
					cout << cover_2[i][j];
					cct_setcolor(0, 7);
					cout << " ";
				}
				else
					Color_of_Inner(cover_2[i][j]);
			}
			cout << endl;
		}
		cout << endl << endl;
	}
}
/***************************************************************************
  函数名称：Inner_Output_3(int choice, char boomarr_3[18][32], char cover_3[18][32], char mark_3[18][32])
  功    能：完成内部数组难度3部分输出功能的主要函数
  输入参数：int choice, char boomarr_3[18][32], char cover_3[18][32], char mark_3[18][32]
  返 回 值：无
  说    明：输出需要注意到这个点是否被标记、是雷还是非雷
***************************************************************************/
void Inner_Output_3(int choice, char boomarr_3[18][32], char cover_3[18][32], char mark_3[18][32])
{
	if (choice == 1)
	{
		for (int i = 1; i < 17; i++)
		{
			int alph = 64;
			cout << (char)(alph + i) << " |";
			for (int j = 1; j < 31; j++)
				cout << boomarr_3[i][j] << " ";
			cout << endl;
		}
		cout << endl << endl;
	}
	if (choice == 2 || choice == 3 || choice == 4)
	{
		if (choice == 2)
			cout << "点开后的数组：" << endl;
		if (choice == 3 || choice == 4)
			cout << "当前数组：" << endl;
		cout << "  |1 2 3 4 5 6 7 8 9 a b c d e f g h i j k l m n o p q r s t u" << endl << "--+--------------------------------------------------------------" << endl;
		for (int i = 1; i < 17; i++)
		{
			int alph = 64;
			cout << (char)(alph + i) << " |";
			for (int j = 1; j < 31; j++)
			{
				if (mark_3[i][j] == 1)
				{
					cct_setcolor(4, 7);
					cout << cover_3[i][j];
					cct_setcolor(0, 7);
					cout << " ";
				}
				else
					Color_of_Inner(cover_3[i][j]);
			}
			cout << endl;
		}
		cout << endl << endl;
	}
}
/***************************************************************************
  函数名称：Inner_game_1(int choice, char boomarr_1[11][11], char cover_1[11][11], char flag_1[11][11], char mark_1[11][11], int keydown1, int keydown2, clock_t Startpoint, clock_t Endpoint)
  功    能：完成内部数组难度1部分3.4选项循环扫雷游戏功能的主要函数
  输入参数：int choice, char boomarr_1[11][11], char cover_1[11][11], char flag_1[11][11], char mark_1[11][11], int keydown1, int keydown2, clock_t Startpoint, clock_t Endpoint
  返 回 值：无
  说    明：无
***************************************************************************/
void Inner_game_1(int choice, char boomarr_1[11][11], char cover_1[11][11], char flag_1[11][11], char mark_1[11][11], int keydown1, int keydown2, clock_t Startpoint, clock_t Endpoint)
{
	while (boomarr_1[keydown1][keydown2] != '*' || mark_1[keydown1][keydown2] != 0)
	{
		if (choice == 3)
			cout << "输入非雷位置的行列坐标（先行后列，严格区分大小写，例：G1/Af，按Q/q退出）：";
		if (choice == 4)
			Print_specification();
		Input_1(choice, keydown1, keydown2, flag_1, mark_1);
		while (keydown1 == '&')
		{
			Endpoint = clock();
			cout << endl << "已运行时间：" << (double)(Endpoint - Startpoint) / CLOCKS_PER_SEC << "秒" << endl;
			Print_specification();
			Input_1(choice, keydown1, keydown2, flag_1, mark_1);
		}
		if (keydown1 == 'q' || keydown1 == 'Q')
		{
			cout << endl;
			return;
		}
		cout << endl << endl;
		Point_Operation_1(boomarr_1, cover_1, flag_1, mark_1, keydown1, keydown2);
		Inner_Output_1(choice, boomarr_1, cover_1, mark_1);
		bool Judge = Judge_win_1(boomarr_1, cover_1);
		if(Judge)
		{
			cout << "恭喜胜利，游戏结束" << endl;
			if (choice == 4)
			{
				Endpoint = clock();
				cout << "共用时:" << (double)(Endpoint - Startpoint) / CLOCKS_PER_SEC << "秒" << endl;
			}
			break;
		}
		if (cover_1[keydown1][keydown2] == '*')
		{
			cout << "你输了，游戏结束" << endl;
			if (choice == 4)
			{
				Endpoint = clock();
				cout << "共用时:" << (double)(Endpoint - Startpoint) / CLOCKS_PER_SEC << "秒" << endl;
			}
		}	
	}
}
/***************************************************************************
  函数名称：Inner_game_2(int choice, char boomarr_2[18][18], char cover_2[18][18], char flag_2[18][18], char mark_2[18][18], int keydown1, int keydown2, clock_t Startpoint, clock_t Endpoint)
  功    能：完成内部数组难度2部分3.4选项循环扫雷游戏功能的主要函数
  输入参数：int choice, char boomarr_2[18][18], char cover_2[18][18], char flag_2[18][18], char mark_2[18][18], int keydown1, int keydown2, clock_t Startpoint, clock_t Endpoint
  返 回 值：无
  说    明：无
***************************************************************************/
void Inner_game_2(int choice, char boomarr_2[18][18], char cover_2[18][18], char flag_2[18][18], char mark_2[18][18], int keydown1, int keydown2, clock_t Startpoint, clock_t Endpoint)
{
	while (boomarr_2[keydown1][keydown2] != '*' || mark_2[keydown1][keydown2] != 0)
	{
		if (choice == 3)
			cout << "输入非雷位置的行列坐标（先行后列，严格区分大小写，例：G1/Af，按Q/q退出）：";
		if (choice == 4)
			Print_specification();
		Input_2(choice, keydown1, keydown2, flag_2, mark_2);
		while (keydown1 == '&')
		{
			Endpoint = clock();
			cout << endl << "已运行时间：" << (double)(Endpoint - Startpoint) / CLOCKS_PER_SEC << "秒" << endl;
			Print_specification();
			Input_2(choice, keydown1, keydown2, flag_2, mark_2);
		}
		if (keydown1 == 'q' || keydown1 == 'Q')
		{
			cout << endl;
			return;
		}
		cout << endl << endl;
		Point_Operation_2(boomarr_2, cover_2, flag_2, mark_2, keydown1, keydown2);
		Inner_Output_2(choice, boomarr_2, cover_2, mark_2);
		bool Judge = Judge_win_2(boomarr_2, cover_2);
		if (Judge)
		{
			cout << "恭喜胜利，游戏结束" << endl;
			if (choice == 4)
			{
				Endpoint = clock();
				cout << "共用时:" << (double)(Endpoint - Startpoint) / CLOCKS_PER_SEC << "秒" << endl;
			}
			break;
		}
		if (cover_2[keydown1][keydown2] == '*')
		{
			cout << "你输了，游戏结束" << endl;
			if (choice == 4)
			{
				Endpoint = clock();
				cout << "共用时:" << (double)(Endpoint - Startpoint) / CLOCKS_PER_SEC << "秒" << endl;
			}
		}	
	}
}
/***************************************************************************
  函数名称：Inner_game_3(int choice, char boomarr_3[18][32], char cover_3[18][32], char flag_3[18][32], char mark_3[18][32], int keydown1, int keydown2, clock_t Startpoint, clock_t Endpoint)
  功    能：完成内部数组难度3部分3.4选项循环扫雷游戏功能的主要函数
  输入参数：int choice, char boomarr_3[18][32], char cover_3[18][32], char flag_3[18][32], char mark_3[18][32], int keydown1, int keydown2, clock_t Startpoint, clock_t Endpoint
  返 回 值：无
  说    明：无
***************************************************************************/
void Inner_game_3(int choice, char boomarr_3[18][32], char cover_3[18][32], char flag_3[18][32], char mark_3[18][32], int keydown1, int keydown2, clock_t Startpoint, clock_t Endpoint)
{
	while (boomarr_3[keydown1][keydown2] != '*' || mark_3[keydown1][keydown2] != 0)
	{
		if (choice == 3)
			cout << "输入非雷位置的行列坐标（先行后列，严格区分大小写，例：G1/Af，按Q/q退出）：";
		if (choice == 4)
			Print_specification();
		Input_3(choice, keydown1, keydown2, flag_3, mark_3);
		while (keydown1 == '&')
		{
			Endpoint = clock();
			cout << endl << "已运行时间：" << (double)(Endpoint - Startpoint) / CLOCKS_PER_SEC << "秒" << endl;
			Print_specification();
			Input_3(choice, keydown1, keydown2, flag_3, mark_3);
		}
		if (keydown1 == 'q' || keydown1 == 'Q')
		{
			cout << endl;
			return;
		}
		cout << endl << endl;
		Point_Operation_3(boomarr_3, cover_3, flag_3, mark_3, keydown1, keydown2);
		Inner_Output_3(choice, boomarr_3, cover_3, mark_3);
		bool Judge = Judge_win_3(boomarr_3, cover_3);
		if (Judge)
		{
			cout << "恭喜胜利，游戏结束" << endl;
			if (choice == 4)
			{
				Endpoint = clock();
				cout << "共用时:" << (double)(Endpoint - Startpoint) / CLOCKS_PER_SEC << "秒" << endl;
			}
			break;
		}
		if (cover_3[keydown1][keydown2] == '*') 
		{
			cout << "你输了，游戏结束" << endl;
			if (choice == 4)
			{
				Endpoint = clock();
				cout << "共用时:" << (double)(Endpoint - Startpoint) / CLOCKS_PER_SEC << "秒" << endl;
			}
		}	
	}
}