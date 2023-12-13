#include"game.h"

//初版初始化数据
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i=0; i < col; i++)
	{
		for (j=0; j < row; j++)//没有初始化i导致数组没有被赋值
		{
			board[i][j] =' ';
		}
	}
}

//初版打印棋盘
//void DispalyBoard(char board[ROW][COL], int row, int col) 
//{
//	int i=0;
//	for (i=0; i < row; i++)
//	{
//		//打印数据
//		printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
//		if (i < col-1) 
//		{
//			printf("---|---|---\n");
//		}	
//	}
//}


//修改版打印棋盘
void DispalyBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		//打印数据
		int j = 0;
		for (j = 0; j < col; j++) 
		{
			printf(" %c ", board[i][j]);
			if(j<col-1)
				printf("|");
		}
		printf("\n");
		//打印分割数据
		if (i < col - 1)
		{
			int j = 0;
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1) 
				{
					printf("|");
				}
			}
				printf("\n");
		}
		
	}
}

//玩家下棋
void PlayerMove(char board[ROW][COL],int row,int col) 
{
	int x = 0;
	int y = 0;
	while (1)
	{
		scanf_s("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("坐标已经被占用，请重新选择\n");
			}

		}
		else
			printf("坐标非法，请重新输入\n");
	}
}

//电脑下棋
void ComputerMove(char board[ROW][COL], int row, int col) 
{
	/*printf("电脑下棋\n");*/
	while (1)
	{
		
		int x = 0;
		int y = 0;
		x = rand() % ROW;//x随机0~2
		y = rand() % COL;//Y随机0~2
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
	
}

//初版判断输赢
//int Judge_Win(char board[ROW][COL]) 
//{
//	int count = 0;
//	//判断棋盘是否已满
//	for (int i = 0; i < ROW; i++)
//	{
//		for (int j = 0; j < COL; j++)
//		{
//			if (board[i][j] == ' ')
//			{
//				count++;
//				break;
//			}
//		}
//	}	
//	if (count == 0)
//	{
//		return -1;
//	}
//	for (int i = 0; i < ROW; i++)
//	{
//		if (board[i][0] != ' ' && board[i][1] != ' ' && board[i][2] != ' ') 
//		{
//			if (board[i][0] == board[i][1]&& board[i][0] == board[i][2])
//			{
//				return 1;
//			}
//		}
//		if (board[0][i] !=' '&& board[1][i] != ' '&& board[2 ][i] != ' ')
//		{
//			if (board[0][i] == board[1][i]&& board[0][i] == board[2][i])
//			{
//				return 1;
//			}
//		}
//	}
//	if(board[0][0]!=' '&& board[1][1]!=' '&& board[2][2]!=' ')
//	{
//		if (board[0][0] == board[1][1]&&board[0][0] == board[2][2])
//		{
//			return 1;
//		}
//	}
//	if (board[2][0] != ' ' && board[1][1] != ' ' && board[0][2])
//	{
//		if (board[2][0] == board[1][1]&& board[2][0] == board[0][2])
//		{
//			return 1;
//	    }
//	}
//	return 0;
//}

//判断棋盘时候已满
int Judge_Full(char board[ROW][COL],int row, int col)
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}

	//for (int i = 0; i < ROW; i++)
	//	for (int j = 0; j < COL; j++)
	//		if (board[i][j] == ' ')
	//			return 0;

	return 1;
}

char Judge_Win(char board[ROW][COL], int row, int col)
{
	//判断棋盘是否已满
	if (Judge_Full(board,row,col))
	{
		return 'n';
	}
	for(int i = 0; i < ROW; i++)
	{
		//判断行
		if (board[i][1] != ' ')
		{
			if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
			{
				return board[i][1];
			}
		}
		//判断列
		if (board[1][i] != ' ')
		{
			if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
			{
				return board[1][i];
			}
		}
	}
		//判断对角线
		if (board[1][1] != ' ')
		{
			//判断主对角线
			if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
			{
				return board[1][1];
			}
			//判断副对角线
			if (board[2][0] == board[1][1] && board[2][0] == board[0][2])
			{
				return board[1][1];
			}
		}	
		return 'c';
}