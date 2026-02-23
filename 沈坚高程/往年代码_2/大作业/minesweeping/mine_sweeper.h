/*2253744 林觉凯 软工*/
#pragma once
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <ctime>
#include "cmd_console_tools.h"
using namespace std;
/*三种难度的雷数*/
#define Boom_num_1 10
#define Boom_num_2 40
#define Boom_num_3 99
/*menu菜单有关的函数*/
int Main_menu();
int Sub_menu();
/*处理Inner_Array(内部数组)有关的函数*/
void Print_specification();
void Print_InitArray_1();
void Print_InitArray_2();
void Print_InitArray_3();
void Color_of_Inner(char ch);
void Inner_difficulty_1(int choice);
void Inner_difficulty_2(int choice);
void Inner_difficulty_3(int choice);
void Input_1(int choice, int& keydown1, int& keydown2, char flag_1[11][11], char mark_1[11][11]);
void Input_2(int choice, int& keydown1, int& keydown2, char flag_2[18][18], char mark_2[18][18]);
void Input_3(int choice, int& keydown1, int& keydown2, char flag_3[18][32], char mark_3[18][32]);
void Inner_Output_1(int choice, char boomarr_1[11][11], char cover_1[11][11], char mark_1[11][11]);
void Inner_Output_2(int choice, char boomarr_2[18][18], char cover_2[18][18], char mark_2[18][18]);
void Inner_Output_3(int choice, char boomarr_3[18][32], char cover_3[18][32], char mark_3[18][32]);
void Inner_game_1(int choice, char boomarr_1[11][11], char cover_1[11][11], char flag_1[11][11], char mark_1[11][11], int keydown1, int keydown2, clock_t Startpoint, clock_t Endpoint);
void Inner_game_2(int choice, char boomarr_2[18][18], char cover_2[18][18], char flag_2[18][18], char mark_2[18][18], int keydown1, int keydown2, clock_t Startpoint, clock_t Endpoint);
void Inner_game_3(int choice, char boomarr_3[18][32], char cover_3[18][32], char flag_3[18][32], char mark_3[18][32], int keydown1, int keydown2, clock_t Startpoint, clock_t Endpoint);
/*处理Pseudographics(伪图形)有关的函数*/
void Print_framework_1();
void Print_framework_2();
void Print_framework_3();
void Print_InitGraph_1();
void Print_InitGraph_2();
void Print_InitGraph_3();
void Color_of_Graph(char ch);
void Print_Leftboom(int Left_boom,int choice);
void Pseudographics_dfficulty_1(int choice);
void Pseudographics_dfficulty_2(int choice);
void Pseudographics_dfficulty_3(int choice);
void Print_markboom_map_1(char mark_1[11][11]);
void Print_markboom_map_2(char mark_1[18][18]);
void Print_markboom_map_3(char mark_1[18][32]);
void Graph_Output_1(int choice, char boomarr_1[11][11], char cover_1[11][11], char mark_1[11][11]);
void Graph_Output_2(int choice, char boomarr_2[18][18], char cover_2[18][18], char mark_2[18][18]);
void Graph_Output_3(int choice, char boomarr_3[18][32], char cover_3[18][32], char mark_3[18][32]);
void Mouse_Operation_1(int choice, int& keydown1, int& keydown2, char flag_1[11][11], char mark_1[11][11], int& Left_boom, int& Go_on);
void Mouse_Operation_2(int choice, int& keydown1, int& keydown2, char flag_2[18][18], char mark_2[18][18], int& Left_boom, int& Go_on);
void Mouse_Operation_3(int choice, int& keydown1, int& keydown2, char flag_3[18][32], char mark_3[18][32], int& Left_boom, int& Go_on);
void Graph_game_1(int choice, char boomarr_1[11][11], char cover_1[11][11], char flag_1[11][11], char mark_1[11][11], int keydown1, int keydown2, clock_t Startpoint, clock_t Endpoint, int& Left_boom);
void Graph_game_2(int choice, char boomarr_2[18][18], char cover_2[18][18], char flag_2[18][18], char mark_2[18][18], int keydown1, int keydown2, clock_t Startpoint, clock_t Endpoint, int& Left_boom);
void Graph_game_3(int choice, char boomarr_3[18][32], char cover_3[18][32], char flag_3[18][32], char mark_3[18][32], int keydown1, int keydown2, clock_t Startpoint, clock_t Endpoint, int& Left_boom);
/*Inner_Array(内部数组)和Pseudographics(伪图形)共用的函数*/
void Reset_markarr_1(char mark_1[11][11]);
void Reset_markarr_2(char mark_2[18][18]);
void Reset_markarr_3(char mark_3[18][32]);
void Initarr_1(char boomarr_1[11][11], int keydown1, int keydown2, int choice);
void Initarr_2(char boomarr_2[18][18], int keydown1, int keydown2, int choice);
void Initarr_3(char boomarr_3[18][32], int keydown1, int keydown2, int choice);
void Expand_map_1(char boomarr_1[11][11], char cover_1[11][11], char flag_1[11][11], char mark_1[11][11], int keydown1, int keydown2);
void Expand_map_2(char boomarr_2[18][18], char cover_2[18][18], char flag_2[18][18], char mark_2[18][18], int keydown1, int keydown2);
void Expand_map_3(char boomarr_3[18][32], char cover_3[18][32], char flag_3[18][32], char mark_3[18][32], int keydown1, int keydown2);
void Point_Operation_1(char boomarr_1[11][11], char cover_1[11][11], char flag_1[11][11], char mark_1[11][11], int& keydown1, int& keydown2);
void Point_Operation_2(char boomarr_2[18][18], char cover_2[18][18], char flag_2[18][18], char mark_2[18][18], int& keydown1, int& keydown2);
void Point_Operation_3(char boomarr_3[18][32], char cover_3[18][32], char flag_3[18][32], char mark_3[18][32], int& keydown1, int& keydown2);
bool Judge_win_1(char boomarr_1[11][11], char cover_1[11][11]);
bool Judge_win_2(char boomarr_2[18][18], char cover_2[18][18]);
bool Judge_win_3(char boomarr_3[18][32], char cover_3[18][32]);