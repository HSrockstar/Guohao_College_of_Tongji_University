#pragma once
#ifndef GAME_H
#define GAME_H

extern int board[4][4]; // 4*4的棋盘
extern int score;       // 分数
extern int step;        // 步数
extern unsigned char choice;     // 用户选择

void play_game(); // 游戏主函数
void game_init(); // 游戏初始化
void game_update(unsigned char choice); // 根据用户输入更新游戏状态
bool game_check_end(int board[4][4]); // 检查游戏是否结束
bool game_check_limit(int board[4][4],bool& sign_limit);//检查是否到达2048
void move_up(int board[4][4], int& check, int& score);//实现向上移动
void move_down(int board[4][4], int& check, int& score);
void move_left(int board[4][4], int& check, int& score);
void move_right(int board[4][4], int& check, int& score);
#endif
