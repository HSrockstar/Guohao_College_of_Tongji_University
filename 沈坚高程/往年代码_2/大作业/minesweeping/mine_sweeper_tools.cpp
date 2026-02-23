/*2253744 林觉凯 软工*/
#include "mine_sweeper.h"
/***************************************************************************
  函数名称：Reset_markarr_1(char mark_1[11][11])
  功    能：将mark_1数组重置（标记两次后为无标记）
  输入参数：char mark_1[11][11]
  返 回 值：无
  说    明：无
***************************************************************************/
void Reset_markarr_1(char mark_1[11][11])
{
	for (int i = 1; i < 10; i++)
		for (int j = 1; j < 10; j++)
			if (mark_1[i][j] == 2)
				mark_1[i][j] = 0;
}
/***************************************************************************
  函数名称：Reset_markarr_2(char mark_2[18][18])
  功    能：将mark_2数组重置（标记两次后为无标记）
  输入参数：char mark_2[18][18]
  返 回 值：无
  说    明：无
***************************************************************************/
void Reset_markarr_2(char mark_2[18][18])
{
	for (int i = 1; i < 17; i++)
		for (int j = 1; j < 17; j++)
			if (mark_2[i][j] == 2)
				mark_2[i][j] = 0;
}
/***************************************************************************
  函数名称：Reset_markarr_3(char mark_3[18][32])
  功    能：将mark_3数组重置（标记两次后为无标记）
  输入参数：char mark_3[18][32]
  返 回 值：无
  说    明：无
***************************************************************************/
void Reset_markarr_3(char mark_3[18][32])
{
	for (int i = 1; i < 17; i++)
		for (int j = 1; j < 31; j++)
			if (mark_3[i][j] == 2)
				mark_3[i][j] = 0;
}
/***************************************************************************
  函数名称：Initarr_1(char boomarr_1[11][11], int keydown1, int keydown2, int choice)
  功    能：初始化难度1雷和每个点周围的雷数
  输入参数：char boomarr_1[11][11], int keydown1, int keydown2, int choice
  返 回 值：无
  说    明：注意我们要求第一次输入的位置是0（自身非雷且周围八个位置无雷），所以传入参数还要有第一次输入的坐标
***************************************************************************/
void Initarr_1(char boomarr_1[11][11], int keydown1, int keydown2, int choice)
{
	srand((unsigned int)(time(0)));
	for (int boom_num = 0; boom_num < Boom_num_1;)
	{
		boom_num = 0;
		boomarr_1[rand() % 9 + 1][rand() % 9 + 1] = '*';
		if (choice == 2 || choice == 3 || choice == 4 || choice == 7 || choice == 8 || choice == 9)
		{
			for (int crosswise = keydown1 - 1; crosswise <= keydown1 + 1; crosswise++)
				for (int vertical = keydown2 - 1; vertical <= keydown2 + 1; vertical++)
					if (boomarr_1[crosswise][vertical] == '*')
						boomarr_1[crosswise][vertical] = 0;
		}
		for (int i = 1; i < 10; i++)
			for (int j = 1; j < 10; j++)
				if (boomarr_1[i][j] == '*')
					boom_num++;
	}
	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			int count_boom = 0;
			if (boomarr_1[i][j] != '*')
			{
				for (int crosswise = i - 1; crosswise <= i + 1; crosswise++)
					for (int vertical = j - 1; vertical <= j + 1; vertical++)
						if (boomarr_1[crosswise][vertical] == '*')
							count_boom++;
				boomarr_1[i][j] = count_boom + '0';
			}
		}
	}
}
/***************************************************************************
  函数名称：Initarr_2(char boomarr_2[18][18], int keydown1, int keydown2, int choice)
  功    能：初始化难度2雷和每个点周围的雷数
  输入参数：char boomarr_2[18][18], int keydown1, int keydown2, int choice
  返 回 值：无
  说    明：注意我们要求第一次输入的位置是0（自身非雷且周围八个位置无雷），所以传入参数还要有第一次输入的坐标
***************************************************************************/
void Initarr_2(char boomarr_2[18][18], int keydown1, int keydown2, int choice)
{
	srand((unsigned int)(time(0)));
	for (int boom_num = 0; boom_num < Boom_num_2;)
	{
		boom_num = 0;
		boomarr_2[rand() % 16 + 1][rand() % 16 + 1] = '*';
		if (choice == 2 || choice == 3 || choice == 4 || choice == 7 || choice == 8 || choice == 9)
		{
			for (int crosswise = keydown1 - 1; crosswise <= keydown1 + 1; crosswise++)
				for (int vertical = keydown2 - 1; vertical <= keydown2 + 1; vertical++)
					if (boomarr_2[crosswise][vertical] == '*')
						boomarr_2[crosswise][vertical] = 0;
		}
		for (int i = 1; i < 17; i++)
			for (int j = 1; j < 17; j++)
				if (boomarr_2[i][j] == '*')
					boom_num++;
	}
	for (int i = 1; i < 17; i++)
	{
		for (int j = 1; j < 17; j++)
		{
			int count_boom = 0;
			if (boomarr_2[i][j] != '*')
			{
				for (int crosswise = i - 1; crosswise <= i + 1; crosswise++)
					for (int vertical = j - 1; vertical <= j + 1; vertical++)
						if (boomarr_2[crosswise][vertical] == '*')
							count_boom++;
				boomarr_2[i][j] = count_boom + '0';
			}
		}
	}
}
/***************************************************************************
  函数名称：Initarr_3(char boomarr_3[18][32], int keydown1, int keydown2, int choice)
  功    能：初始化难度3雷和每个点周围的雷数
  输入参数：char boomarr_3[18][32], int keydown1, int keydown2, int choice
  返 回 值：无
  说    明：注意我们要求第一次输入的位置是0（自身非雷且周围八个位置无雷），所以传入参数还要有第一次输入的坐标
***************************************************************************/
void Initarr_3(char boomarr_3[18][32], int keydown1, int keydown2, int choice)
{
	srand((unsigned int)(time(0)));
	for (int boom_num = 0; boom_num < Boom_num_3;)
	{
		boom_num = 0;
		boomarr_3[rand() % 16 + 1][rand() % 30 + 1] = '*';
		if (choice == 2 || choice == 3 || choice == 4 || choice == 7 || choice == 8 || choice == 9)
		{
			for (int crosswise = keydown1 - 1; crosswise <= keydown1 + 1; crosswise++)
				for (int vertical = keydown2 - 1; vertical <= keydown2 + 1; vertical++)
					if (boomarr_3[crosswise][vertical] == '*')
						boomarr_3[crosswise][vertical] = 0;
		}
		for (int i = 1; i < 17; i++)
			for (int j = 1; j < 31; j++)
				if (boomarr_3[i][j] == '*')
					boom_num++;
	}
	for (int i = 1; i < 17; i++)
	{
		for (int j = 1; j < 31; j++)
		{
			int count_boom = 0;
			if (boomarr_3[i][j] != '*')
			{
				for (int crosswise = i - 1; crosswise <= i + 1; crosswise++)
					for (int vertical = j - 1; vertical <= j + 1; vertical++)
						if (boomarr_3[crosswise][vertical] == '*')
							count_boom++;
				boomarr_3[i][j] = count_boom + '0';
			}
		}
	}
}
/***************************************************************************
  函数名称：Judge_win_1(char boomarr_1[11][11], char cover_1[11][11])
  功    能：判断游戏难度1是否胜利
  输入参数：char boomarr_1[11][11], char cover_1[11][11]
  返 回 值：无
  说    明：如果所有的雷都显示出来，则表示胜利
***************************************************************************/
bool Judge_win_1(char boomarr_1[11][11], char cover_1[11][11])
{
	for (int i = 1; i < 10; i++)
		for (int j = 1; j < 10; j++)
			if (cover_1[i][j] == 'X')
				if (boomarr_1[i][j] != '*')
					return false;
	return true;
}
/***************************************************************************
  函数名称：Judge_win_2(char boomarr_2[18][18], char cover_2[18][18])
  功    能：判断游戏难度2是否胜利
  输入参数：char boomarr_2[18][18], char cover_2[18][18]
  返 回 值：无
  说    明：如果所有的雷都显示出来，则表示胜利
***************************************************************************/
bool Judge_win_2(char boomarr_2[18][18], char cover_2[18][18])
{
	for (int i = 1; i < 17; i++)
		for (int j = 1; j < 17; j++)
			if (cover_2[i][j] == 'X')
				if (boomarr_2[i][j] != '*')
					return false;
	return true;
}
/***************************************************************************
  函数名称：Judge_win_3(char boomarr_3[18][32], char cover_3[18][32])
  功    能：判断游戏难度3是否胜利
  输入参数：char boomarr_3[18][32], char cover_3[18][32]
  返 回 值：无
  说    明：如果所有的雷都显示出来，则表示胜利
***************************************************************************/
bool Judge_win_3(char boomarr_3[18][32], char cover_3[18][32])
{
	for (int i = 1; i < 17; i++)
		for (int j = 1; j < 31; j++)
			if (cover_3[i][j] == 'X')
				if (boomarr_3[i][j] != '*')
					return false;
	return true;
}
/***************************************************************************
  函数名称：Expand_map_1(char boomarr_1[11][11], char cover_1[11][11], char flag_1[11][11], char mark_1[11][11], int keydown1, int keydown2)
  功    能：完成难度1“打开”操作的函数
  输入参数：char boomarr_1[11][11], char cover_1[11][11], char flag_1[11][11], char mark_1[11][11], int keydown1, int keydown2
  返 回 值：无
  说    明：采用递归的方法，向被“打开”的周围八个点继续使用该函数，直到遇到递归的终止条件
***************************************************************************/
void Expand_map_1(char boomarr_1[11][11], char cover_1[11][11], char flag_1[11][11], char mark_1[11][11], int keydown1, int keydown2)
{
	for (int i = keydown1 - 1; i <= keydown1 + 1; i++)
	{
		for (int j = keydown2 - 1; j <= keydown2 + 1; j++)
		{
			if (flag_1[i][j] == 1)
			{
				if (mark_1[i][j] == 1)
					cover_1[i][j] = 'X';
				else
					cover_1[i][j] = boomarr_1[i][j];
				continue;
			}
			if (flag_1[i][j] == 0)
			{
				if (mark_1[i][j] == 1)
					cover_1[i][j] = 'X';
				else
					cover_1[i][j] = boomarr_1[i][j];
				flag_1[i][j] = 1;
			}
			if (boomarr_1[i][j] == '0')
				Expand_map_1(boomarr_1, cover_1, flag_1, mark_1, i, j);
		}
	}
	for (int i = 1; i < 10; i++)
		for (int j = 1; j < 10; j++)
			if (cover_1[i][j] == 0)
				cover_1[i][j] = 'X';
}
/***************************************************************************
  函数名称：Expand_map_2(char boomarr_2[18][18], char cover_2[18][18], char flag_2[18][18], char mark_2[18][18], int keydown1, int keydown2)
  功    能：完成难度2“打开”操作的函数
  输入参数：char boomarr_2[18][18], char cover_2[18][18], char flag_2[18][18], char mark_2[18][18], int keydown1, int keydown2
  返 回 值：无
  说    明：采用递归的方法，向被“打开”的周围八个点继续使用该函数，直到遇到递归的终止条件
***************************************************************************/
void Expand_map_2(char boomarr_2[18][18], char cover_2[18][18], char flag_2[18][18], char mark_2[18][18], int keydown1, int keydown2)
{
	for (int i = keydown1 - 1; i <= keydown1 + 1; i++)
	{
		for (int j = keydown2 - 1; j <= keydown2 + 1; j++)
		{
			if (flag_2[i][j] == 1)
			{
				if (mark_2[i][j] == 1)
					cover_2[i][j] = 'X';
				else
					cover_2[i][j] = boomarr_2[i][j];
				continue;
			}
			if (flag_2[i][j] == 0)
			{
				if (mark_2[i][j] == 1)
					cover_2[i][j] = 'X';
				else
					cover_2[i][j] = boomarr_2[i][j];
				flag_2[i][j] = 1;
			}
			if (boomarr_2[i][j] == '0')
				Expand_map_2(boomarr_2, cover_2, flag_2, mark_2, i, j);
		}
	}
	for (int i = 1; i < 17; i++)
		for (int j = 1; j < 17; j++)
			if (cover_2[i][j] == 0)
				cover_2[i][j] = 'X';
}
/***************************************************************************
  函数名称：Expand_map_3(char boomarr_3[18][32], char cover_3[18][32], char flag_3[18][32], char mark_3[18][32], int keydown1, int keydown2)
  功    能：完成难度3“打开”操作的函数
  输入参数：char boomarr_3[18][32], char cover_3[18][32], char flag_3[18][32], char mark_3[18][32], int keydown1, int keydown2
  返 回 值：无
  说    明：采用递归的方法，向被“打开”的周围八个点继续使用该函数，直到遇到递归的终止条件
***************************************************************************/
void Expand_map_3(char boomarr_3[18][32], char cover_3[18][32], char flag_3[18][32], char mark_3[18][32], int keydown1, int keydown2)
{
	for (int i = keydown1 - 1; i <= keydown1 + 1; i++)
	{
		for (int j = keydown2 - 1; j <= keydown2 + 1; j++)
		{
			if (flag_3[i][j] == 1)
			{
				if (mark_3[i][j] == 1)
					cover_3[i][j] = 'X';
				else
					cover_3[i][j] = boomarr_3[i][j];
				continue;
			}
			if (flag_3[i][j] == 0)
			{
				if (mark_3[i][j] == 1)
					cover_3[i][j] = 'X';
				else
					cover_3[i][j] = boomarr_3[i][j];
				flag_3[i][j] = 1;
			}
			if (boomarr_3[i][j] == '0')
				Expand_map_3(boomarr_3, cover_3, flag_3, mark_3, i, j);
		}
	}
	for (int i = 1; i < 17; i++)
		for (int j = 1; j < 31; j++)
			if (cover_3[i][j] == 0)
				cover_3[i][j] = 'X';
}
/***************************************************************************
  函数名称：Point_Operation_1(char boomarr_1[11][11], char cover_1[11][11], char flag_1[11][11], char mark_1[11][11], int& keydown1, int& keydown2)
  功    能：完成难度1对按下某点后的变化操作
  输入参数：char boomarr_1[11][11], char cover_1[11][11], char flag_1[11][11], char mark_1[11][11], int& keydown1, int& keydown2
  返 回 值：无
  说    明：分为好几种情况：是否继续打开，mark、flag和cover的变化
***************************************************************************/
void Point_Operation_1(char boomarr_1[11][11], char cover_1[11][11], char flag_1[11][11], char mark_1[11][11], int& keydown1, int& keydown2)
{
	if (boomarr_1[keydown1][keydown2] == '0' && mark_1[keydown1][keydown2] == 0)
	{
		Reset_markarr_1(mark_1);
		Expand_map_1(boomarr_1, cover_1, flag_1, mark_1, keydown1, keydown2);
	}
	else
	{
		if (mark_1[keydown1][keydown2] == 1)
		{
			cover_1[keydown1][keydown2] = 'X';
			flag_1[keydown1][keydown2] = 1;
		}
		else if (mark_1[keydown1][keydown2] == 2)
			cover_1[keydown1][keydown2] = cover_1[keydown1][keydown2];
		else
		{
			cover_1[keydown1][keydown2] = boomarr_1[keydown1][keydown2];
			flag_1[keydown1][keydown2] = 1;
		}
	}
}
/***************************************************************************
  函数名称：Point_Operation_2(char boomarr_2[18][18], char cover_2[18][18], char flag_2[18][18], char mark_2[18][18], int& keydown1, int& keydown2)
  功    能：完成难度2对按下某点后的变化操作
  输入参数：char boomarr_2[18][18], char cover_2[18][18], char flag_2[18][18], char mark_2[18][18], int& keydown1, int& keydown2
  返 回 值：无
  说    明：分为好几种情况：是否继续打开，mark、flag和cover的变化
***************************************************************************/
void Point_Operation_2(char boomarr_2[18][18], char cover_2[18][18], char flag_2[18][18], char mark_2[18][18], int& keydown1, int& keydown2)
{
	if (boomarr_2[keydown1][keydown2] == '0' && mark_2[keydown1][keydown2] == 0)
	{
		Reset_markarr_2(mark_2);
		Expand_map_2(boomarr_2, cover_2, flag_2, mark_2, keydown1, keydown2);
	}
	else
	{
		if (mark_2[keydown1][keydown2] == 1)
		{
			cover_2[keydown1][keydown2] = 'X';
			flag_2[keydown1][keydown2] = 1;
		}
		else if (mark_2[keydown1][keydown2] == 2)
			cover_2[keydown1][keydown2] = cover_2[keydown1][keydown2];
		else
		{
			cover_2[keydown1][keydown2] = boomarr_2[keydown1][keydown2];
			flag_2[keydown1][keydown2] = 1;
		}
	}
}
/***************************************************************************
  函数名称：Point_Operation_3(char boomarr_3[18][32], char cover_3[18][32], char flag_3[18][32], char mark_3[18][32], int& keydown1, int& keydown2)
  功    能：完成难度2对按下某点后的变化操作
  输入参数：char boomarr_3[18][32], char cover_3[18][32], char flag_3[18][32], char mark_3[18][32], int& keydown1, int& keydown2
  返 回 值：无
  说    明：分为好几种情况：是否继续打开，mark、flag和cover的变化
***************************************************************************/
void Point_Operation_3(char boomarr_3[18][32], char cover_3[18][32], char flag_3[18][32], char mark_3[18][32], int& keydown1, int& keydown2)
{
	if (boomarr_3[keydown1][keydown2] == '0' && mark_3[keydown1][keydown2] == 0)
	{
		Reset_markarr_3(mark_3);
		Expand_map_3(boomarr_3, cover_3, flag_3, mark_3, keydown1, keydown2);
	}
	else
	{
		if (mark_3[keydown1][keydown2] == 1)
		{
			cover_3[keydown1][keydown2] = 'X';
			flag_3[keydown1][keydown2] = 1;
		}
		else if (mark_3[keydown1][keydown2] == 2)
			cover_3[keydown1][keydown2] = cover_3[keydown1][keydown2];
		else
		{
			cover_3[keydown1][keydown2] = boomarr_3[keydown1][keydown2];
			flag_3[keydown1][keydown2] = 1;
		}
	}
}