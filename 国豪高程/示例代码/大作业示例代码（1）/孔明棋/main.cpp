#include <iostream>
#include <tchar.h>
#include <graphics.h>
#include <conio.h>
#include <mmsystem.h>
#include "ChessBoard.h"
#include "RoundButton.h"
#include "game_functions.h"

#pragma comment(lib, "winmm.lib")

using namespace std;

void begin();
void choice();
void play_game(int init[7][7]);
void rule();
void endgame();

int main()
{
    begin();
    choice();
    EndBatchDraw();
    closegraph();
    return 0;
}