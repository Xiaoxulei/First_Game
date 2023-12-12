#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 3
#define COL 3

void game();
void menu();
//≥ı ºªØ∆Â≈Ã
void InitBoard(char board[ROW][COL], int row, int col);

//¥Ú”°∆Â≈Ã
void DispalyBoard(char board[ROW][COL], int row, int col);

//ÕÊº“œ¬∆Â
void PlayerMove(char board[ROW][COL], int row, int col);

//µÁƒ‘œ¬∆Â
void ComputerMove(char board[ROW][COL], int row, int col);

//≈–∂œ ‰”Æ
int Judge_Win(char board[ROW][COL]);

//≈–∂œ ‰”Æ