#pragma once
#ifndef GAME_FUNCTIONS_H
#define GAME_FUNCTIONS_H

#include <graphics.h>
#include "ChessBoard.h"
#include "RoundButton.h"

void begin();
void choice();
void play_game(int init[7][7]);
void rule();
void endgame();

#endif // GAME_FUNCTIONS_H