#pragma once
#ifndef GAME_H
#define GAME_H

extern int board[4][4]; // 4*4������
extern int score;       // ����
extern int step;        // ����
extern unsigned char choice;     // �û�ѡ��

void play_game(); // ��Ϸ������
void game_init(); // ��Ϸ��ʼ��
void game_update(unsigned char choice); // �����û����������Ϸ״̬
bool game_check_end(int board[4][4]); // �����Ϸ�Ƿ����
bool game_check_limit(int board[4][4],bool& sign_limit);//����Ƿ񵽴�2048
void move_up(int board[4][4], int& check, int& score);//ʵ�������ƶ�
void move_down(int board[4][4], int& check, int& score);
void move_left(int board[4][4], int& check, int& score);
void move_right(int board[4][4], int& check, int& score);
#endif
