#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 3
#define COL 3

void game();
void menu();
//��ʼ������
void InitBoard(char board[ROW][COL], int row, int col);

//��ӡ����
void DispalyBoard(char board[ROW][COL], int row, int col);

//�������
void PlayerMove(char board[ROW][COL], int row, int col);

//��������
void ComputerMove(char board[ROW][COL], int row, int col);

//�ж���Ӯ
char Judge_Win(char board[ROW][COL], int row, int col);

//�ж������Ƿ�����
int Judge_Full(char board[ROW][COL], int row, int col);