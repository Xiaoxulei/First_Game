#include"game.h"

//��ʼ������
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

//��ӡ����
void DispalyBoard(char board[ROW][COL], int row, int col) 
{
	
	int i=0;
	for (; i < row; i++)
	{
		//��ӡ����
		printf(" %c | %c | %c \n",board[row][0],board[row][1],board[row][2]);
		if (i < row - 1)
			printf("----|----|----\n");
	}
}