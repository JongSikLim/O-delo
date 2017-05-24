#pragma once

#include "include.h"
#include "�÷����Լ�.h"

/*
�����Լ�
randSetting() = ������ ���ϴ� �Լ�
doGame() =  main�� ������ �ϸ� ������ ������ �Ѱ��ϴ� �Լ�
*/
void randSetting();
void doGame();

/*
�ʱ� ������ ����
*/

void randSetting() {
	int playerA, playerB; // �÷��̾� ����
	playerA = rand() % 100 + 1;
	playerB = rand() % 100 + 1;
	printf("Player 1 :%d\n", playerA);
	printf("Player 2 :%d\n", playerB);

	if (playerA > playerB) {
		turn = 1;
		printf("playerA�� ������ �����Ѵ�.");
	}
	else {
		turn = 0;
		printf("playerB�� ������ �����Ѵ�.");
	}
	printf("\n���͸� �Է��ϸ� ������ �����մϴ�.");
	getchar();
}



void doGame() {
	int i;
	char j;
	char valChar;
	int valInt;
	bool loopFlag = true;
	printf("Player%d�� ��\n", (turn == 1) ? 1 : 2);

	if (turnCount <= 1) {
		do {
			printf("��ǥ �Է�( x: 1~20, y: a~t ) : ");
			scanf_s("%d %c", &i, &j);

			loopFlag = checkingField(j - 96, i, turn, matrix);
			turn = !turn;
		} while (loopFlag);
		turnCount++;

	}

	//2�� ° ����
	else {
		do {
			int inputType;
			printf("���� �Է� 1) \n���� �Է� 2)  \n�Է�:  ");
			scanf_s("%d", &inputType);

			if (inputType == 1) {
				printf("��ǥ �Է�( 1~20) : ");
				scanf_s("%d", &valInt);
				loopFlag = checkingField2(valInt, turn, matrix);
			}
			else if (inputType == 2) {
				getchar();
				printf("��ǥ �Է�( a~t ) : ");
				scanf_s("%c", &valChar);
				getchar();
				loopFlag = checkingField2(valChar, turn, matrix);
			}

			/*
			�ƽ�Ű 1 - 49
			�ƽ�Ű a - 97
			*/




			turn = !turn;
		} while (loopFlag);
		turnCount++;
	}
}