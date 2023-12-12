#include"game.h"

//�����ʼ������
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i=0; i < col; i++)
	{
		for (j=0; j < row; j++)//û�г�ʼ��i��������û�б���ֵ
		{
			board[i][j] =' ';
		}
	}
}

//�����ӡ����
//void DispalyBoard(char board[ROW][COL], int row, int col) 
//{
//	int i=0;
//	for (i=0; i < row; i++)
//	{
//		//��ӡ����
//		printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
//		if (i < col-1) 
//		{
//			printf("---|---|---\n");
//		}	
//	}
//}




//�޸İ��ӡ����
void DispalyBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		//��ӡ����
		int j = 0;
		for (j = 0; j < col; j++) 
		{
			printf(" %c ", board[i][j]);
			if(j<col-1)
				printf("|");
		}
		printf("\n");
		//��ӡ�ָ�����
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

//�������
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
				printf("�����Ѿ���ռ�ã�������ѡ��\n");
			}

		}
		else
			printf("����Ƿ�������������\n");
	}
}

//��������
void ComputerMove(char board[ROW][COL], int row, int col) 
{
	/*printf("��������\n");*/
	while (1)
	{
		
		int x = 0;
		int y = 0;
		x = rand() % ROW;//x���0~2
		y = rand() % COL;//Y���0~2
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
	
}

//�ж���Ӯ
int Judge_Win(char board[ROW][COL]) 
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROW; i++)
	{
		if (board[i][0] == board[i][1] == board[i][2])
		{
			return 1;
			break;
		}
		if (board[0][i] == board[1][i] == board[i][i])
		{
			return 1;
		}
	}
	if (board[0][0] == board[1][1] == board[2][2])
	{
		return 1;
	}
	if (board[2][0] == board[1][1] == board[0][2])
	{
		return 1;
	}
	return 0;
}