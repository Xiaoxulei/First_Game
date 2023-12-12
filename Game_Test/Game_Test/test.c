#include"game.h"

int main()
{
		menu();
}
void game()
{
	srand((unsigned)time(NULL));
	char board[ROW][COL] = { 0 };
	//初始化数据
	InitBoard(board, ROW, COL);
	//打印棋盘
	DispalyBoard(board, ROW, COL);
	while (1)
	{
		//玩家下棋
		PlayerMove(board, ROW, COL);
		//打印棋盘
		/*DispalyBoard(board, ROW, COL);*/
		//判断输赢
		if (Judge_Win(board) == -1)
		{
			DispalyBoard(board, ROW, COL);
			printf("棋盘已满，游戏结束\n");
			break;
		}
		if (Judge_Win(board) == 1)
		{
			//打印棋盘
			DispalyBoard(board, ROW, COL);
			printf("恭喜你获胜了\n");
			break;
		}
		Judge_Win(board);
		//电脑下棋
		ComputerMove( board, ROW, COL);
		//打印棋盘
		DispalyBoard(board, ROW, COL);
		//判断输赢
		if (Judge_Win(board) == -1)
		{
			//打印棋盘
			DispalyBoard(board, ROW, COL);
			printf("棋盘已满,游戏结束\n");
			break;
		}
		if (Judge_Win(board) == 1)
		{
			//打印棋盘
			DispalyBoard(board, ROW, COL);
			printf("很遗憾，你输了\n");
			break;
		}
	}
}
//菜单
int menu() {
	printf("---welcome to my game---\n");
	printf("--------请选择----------\n");
	printf("--------1.开始游戏------\n");
	printf("--------0.退出----------\n");
	printf("------------------------\n");
	int input = -1;
	do {
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
	return 0;
}