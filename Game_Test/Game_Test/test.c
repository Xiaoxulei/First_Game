#include"game.h"
void menu();
int main()
{

	menu();
}
void game()
{
	char board[ROW][COL] = { 0 };
	//��ʼ������
	InitBoard(board, ROW, COL);
	//��ӡ����
	DispalyBoard(board, ROW, COL);
}
//�˵�
void menu() {
	printf("---welcome to my game---\n");
	printf("--------��ѡ��----------\n");
	printf("--------1.��ʼ��Ϸ------\n");
	printf("--------0.�˳�----------\n");
	int input = -1;
	do {
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			printf("��ʼ��Ϸ\n");
			game();
			break;
		case 0:
			printf("�˳�\n");
			break;
		default:
			printf("������ѡ��\n");
			break;
		}
	} while (input);
}