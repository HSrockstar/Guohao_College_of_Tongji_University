#ifndef CORE_H
#define CORE_H

void init_board(int board[4][4]);
void add_random_tile(int board[4][4]);
bool can_move(int board[4][4]);
bool move_left(int board[4][4], int& score);
bool move_right(int board[4][4], int& score);
bool move_up(int board[4][4], int& score);
bool move_down(int board[4][4], int& score);

#endif