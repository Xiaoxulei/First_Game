#include"game.h"

int main()
{
	srand((unsigned)time(NULL));//����������������������
	menu();
}
void game()
{
	char board[ROW][COL] = {0};
	//��ʼ������
	InitBoard(board, ROW, COL);
	//��ӡ����
	DispalyBoard(board, ROW, COL);
	int count = 0;
	while (1)
	{
//�������
		printf("�������\n");
		PlayerMove(board, ROW, COL);
		count++;
		////��ӡ����
		//DispalyBoard(board, ROW, COL);
		//�ж������Ƿ�����
		if (count > 2)
		{
			if (Judge_Win(board, ROW, COL) != 'c')
			{
				if (Judge_Win(board, ROW, COL) == 'n')
				{
					//��ӡ����
					DispalyBoard(board, ROW, COL);
					printf("ƽ��\n");
					break;
				}
				if (Judge_Win(board, ROW, COL) == '*')
				{
					//��ӡ����
					DispalyBoard(board, ROW, COL);
					printf("��ϲ���ʤ��!\n");
					break;
				}
			}
		}
//��������
		printf("��������\n");
		ComputerMove( board, ROW, COL);
		count++;
		//��ӡ����
		DispalyBoard(board, ROW, COL);
		//�ж���Ӯ
		if (count > 2)
		{
			if (Judge_Win(board, ROW, COL) != 'c')
			{
				if (Judge_Win(board, ROW, COL) == 'n')
				{
					//��ӡ����
					DispalyBoard(board, ROW, COL);
					printf("ƽ��\n");
					break;
				}
				if (Judge_Win(board, ROW, COL) == '#')
				{
					//��ӡ����
					DispalyBoard(board, ROW, COL);
					printf("���ź��������ˣ�\n");
					break;
				}
			}
		}
	}
}
//�˵�
void menu() {
	int input = -1;
	do {
	printf("---welcome to my game---\n");
	printf("--------��ѡ��----------\n");
	printf("--------1.��ʼ��Ϸ------\n");
	printf("--------0.�˳�----------\n");
	printf("------------------------\n");
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
}