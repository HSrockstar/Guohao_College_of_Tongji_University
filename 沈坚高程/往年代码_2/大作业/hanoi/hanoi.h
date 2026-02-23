/*2253744 林觉凯 软工*/
#pragma once

/* ------------------------------------------------------------------------------------------------------

     本文件功能：
	1、为了保证 hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp 能相互访问函数的函数声明
	2、一个以上的cpp中用到的宏定义（#define）或全局只读（const）变量，个数不限
	3、可以参考 cmd_console_tools.h 的写法（认真阅读并体会）
   ------------------------------------------------------------------------------------------------------ */
#include <iostream>
#include <iomanip>
#include <conio.h>
#include "cmd_console_tools.h"
#include "Windows.h"
#define Time 500
#define Base_X 1
#define Base_Y 15
#define Base_Distance 33
#define A_Base_Middle 12
#define B_Base_Middle 45
#define C_Base_Middle 78
#define Column_Height 12
char Hanoi_Menu();
void Choice_1();
void Choice_2();
void Choice_3();
void Choice_4();
void Choice_5();
void Choice_6();
void Choice_7();
void Choice_8();
void Choice_9();