#include <cstdio>
#include <cstdlib>
#include <ctime>
#include "����Լ�.h"
#include "�����Լ�.h"

#define COL 22
#define M_SIZE 22


/*

-commit log
��ǥ ������ �����Ϸ� �Ͽ��� �� �ѱ�� �͵� ������ ���ƴ�.
���� ����� �ٽ� �����ؾ��Ѵ�.
�ι�° �Ϻ��ʹ� ��ǥ�� �ϳ����� �Է¹ޱ� �����̴�.

*/

int main() {
	srand((unsigned int)time(0));
	randSetting();
	
	while (isOver(matrix)) {
		system("cls");
		showMatrix(matrix);
		doGame();
	}

	point(matrix);
	printf("������ �����մϴ�.\n");

	return 0;
}

