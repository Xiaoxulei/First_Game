#include"game.h"

int main()
{
		menu();
}
void game()
{
	srand((unsigned)time(NULL));
	char board[ROW][COL] = { 0 };
	//��ʼ������
	InitBoard(board, ROW, COL);
	//��ӡ����
	DispalyBoard(board, ROW, COL);
	while (1)
	{
		//�������
		PlayerMove(board, ROW, COL);
		//��ӡ����
		/*DispalyBoard(board, ROW, COL);*/
		//�ж���Ӯ
		if (Judge_Win(board) == -1)
		{
			DispalyBoard(board, ROW, COL);
			printf("������������Ϸ����\n");
			break;
		}
		if (Judge_Win(board) == 1)
		{
			//��ӡ����
			DispalyBoard(board, ROW, COL);
			printf("��ϲ���ʤ��\n");
			break;
		}
		Judge_Win(board);
		//��������
		ComputerMove( board, ROW, COL);
		//��ӡ����
		DispalyBoard(board, ROW, COL);
		//�ж���Ӯ
		if (Judge_Win(board) == -1)
		{
			//��ӡ����
			DispalyBoard(board, ROW, COL);
			printf("��������,��Ϸ����\n");
			break;
		}
		if (Judge_Win(board) == 1)
		{
			//��ӡ����
			DispalyBoard(board, ROW, COL);
			printf("���ź���������\n");
			break;
		}
	}
}
//�˵�
int menu() {
	printf("---welcome to my game---\n");
	printf("--------��ѡ��----------\n");
	printf("--------1.��ʼ��Ϸ------\n");
	printf("--------0.�˳�----------\n");
	printf("------------------------\n");
	int input = -1;
	do {
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			printf("--��ʼ��Ϸ--\n");
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
	return 0;
}