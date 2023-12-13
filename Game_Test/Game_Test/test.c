#include"game.h"

int main()
{
	srand((unsigned)time(NULL));//设置随机生成数的生成起点
	menu();
}
void game()
{
	char board[ROW][COL] = {0};
	//初始化数据
	InitBoard(board, ROW, COL);
	//打印棋盘
	DispalyBoard(board, ROW, COL);
	int count = 0;
	while (1)
	{
//玩家下棋
		printf("玩家下棋\n");
		PlayerMove(board, ROW, COL);
		count++;
		////打印棋盘
		//DispalyBoard(board, ROW, COL);
		//判断棋盘是否已满
		if (count > 2)
		{
			if (Judge_Win(board, ROW, COL) != 'c')
			{
				if (Judge_Win(board, ROW, COL) == 'n')
				{
					//打印棋盘
					DispalyBoard(board, ROW, COL);
					printf("平局\n");
					break;
				}
				if (Judge_Win(board, ROW, COL) == '*')
				{
					//打印棋盘
					DispalyBoard(board, ROW, COL);
					printf("恭喜你获胜了!\n");
					break;
				}
			}
		}
//电脑下棋
		printf("电脑下棋\n");
		ComputerMove( board, ROW, COL);
		count++;
		//打印棋盘
		DispalyBoard(board, ROW, COL);
		//判断输赢
		if (count > 2)
		{
			if (Judge_Win(board, ROW, COL) != 'c')
			{
				if (Judge_Win(board, ROW, COL) == 'n')
				{
					//打印棋盘
					DispalyBoard(board, ROW, COL);
					printf("平局\n");
					break;
				}
				if (Judge_Win(board, ROW, COL) == '#')
				{
					//打印棋盘
					DispalyBoard(board, ROW, COL);
					printf("很遗憾，你输了！\n");
					break;
				}
			}
		}
	}
}
//菜单
void menu() {
	int input = -1;
	do {
	printf("---welcome to my game---\n");
	printf("--------请选择----------\n");
	printf("--------1.开始游戏------\n");
	printf("--------0.退出----------\n");
	printf("------------------------\n");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			printf("--开始游戏--\n");
			game();
			break;
		case 0:
			printf("退出\n");
			break;
		default:
			printf("请重新选择\n");
			break;
		}
	} while (input);
}