#include"game.h"

//初始化数据
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (; i < row; i++)
	{
		for (; j < col; j++)
		{
			board[i][j] =' ';
		}
	}
}

//打印棋盘
void DispalyBoard(char board[ROW][COL], int row, int col) 
{
	
	int i=0;
	for (; i < row; i++)
	{
		//打印数据
		printf(" %c | %c | %c \n",board[row][0],board[row][1],board[row][2]);
		if (i < row - 1)
			printf("----|----|----\n");
	}
}