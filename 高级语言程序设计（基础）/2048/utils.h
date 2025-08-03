#pragma once
#ifndef UTILS_H
#define UTILS_H

void wait_for_enter(); // 等待用户按回车键
void print_menu();     // 打印菜单
void print_help();     // 打印游戏规则
void print_exit();     // 打印退出信息
void print_interface(int board[4][4], int score, int step); // 打印游戏界面
void print_random();  //在一个空的方格中随机生成一个新的数字方格

#endif