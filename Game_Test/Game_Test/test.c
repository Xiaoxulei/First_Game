#include"game.h"
void menu();
int main()
{

	menu();
}
void game()
{
	char Board[ROW][COL] = { 0 };
	//初始化
	InitBoard(Board, ROW, COL);
	//打印棋盘
	DispalyBoard(Board, ROW, COL);
}
//菜单
void menu() {
	printf("---welcome to my game---\n");
	printf("--------请选择----------\n");
	printf("--------1.开始游戏------\n");
	printf("--------0.退出----------\n");
	int input = -1;
	do {
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("开始游戏\n");
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