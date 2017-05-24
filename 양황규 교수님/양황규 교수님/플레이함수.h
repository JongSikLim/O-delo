#pragma once

#include "include.h"

/*
�÷��� �Լ�
checkingField() = �� �÷��̾��� ù��° �Ͽ��� ����Ǵ� �Լ�
checkingField() = 2�� ���� ���� ����Ǵ� �Լ�
isOver() = �÷��̰� �������� Ȯ�����ִ� �Լ�

*/
bool checkingField(char, int, int turn, int[][COL]);
bool checkingField2(int x, int turn, int[][COL]);
bool isOver(int[][COL]);
void specialRule(int[][COL]);
void point(int[][COL]);



bool checkingField(char i, int j, int turn, int matrix[][COL]) {
//P1 �� ��
if (turn == 1) {
	if (matrix[i][j] == 2 || matrix[i][j] == 22)
		return true;

	else {
		//���ο��� ǥ��
		for (int x = 1; x < 21; x++)
			matrix[x][j] = 11;
		for (int x = 1; x < 21; x++)
			matrix[i][x] = 11;
		//��ǥ���� ǥ��
		matrix[i][j] = 1;
		//�ùٸ� ������ ������ ��� return false
		return false;
	}
}
//P2 �� ��
else {
	if (matrix[i][j] == 1 || matrix[i][j] == 11)
		return true;
	else {
		for (int x = 1; x < 21; x++)
			matrix[x][j] = 22;
		for (int x = 1; x < 21; x++)
			matrix[i][x] = 22;

		matrix[i][j] = 2;

		return false;
	}
}
}

bool checkingField2(int x, int turn, int matrix[][COL]) {

	/*
	turn 1~20 �� ������ǥ 1 ~ 20 �̹Ƿ� ��� �� �İ��� �������� ������ �����.
	turn a~t(97~116) �� ������ǥ�̹Ƿ� ��� �� �� ���� �������� ������ �����.
	*/
	printf("Player%d�� ��\n", (turn == 1) ? 1 : 2);
	//P1�� ��
	if (turn == 1) {
		//printf("x�ǰ��� : %d\n\n", x);
		if (1 <= x && x <= 20) {
			for (int i = 1; i <= 20; i++) {
				if (matrix[i][x] == 2) return true;
			}
			for (int i = 1; i <= 20; i++) {
				//�������� ���� ��´�.
				if (matrix[i][x] == 11) matrix[i][x] = 1;
				//������ ������ P1�� �������� ����
				else matrix[i][x] = 11;
			}
		}
		else if (97 <= x && x <= 116) {
			for (int i = 1; i <= 20; i++) {
				if (matrix[x - 96][i] == 2)return true;
			}
			for (int i = 1; i <= 20; i++) {
				//�������� ���� ��´�.
				/*
				x-96 -> �迭�� ���� ���߱� ����.
				*/
				if (matrix[x - 96][i] == 11) matrix[x - 96][i] = 1;
				//������ ������ P1�� �������� ����
				else matrix[x - 96][i] = 11;

			}

		}
	}
	//P2�� ��
	else {
		if (1 <= x && x <= 20) {
			for (int i = 1; i <= 20; i++) {
				if (matrix[i][x] == 1) return true;
			}
			for (int i = 1; i <= 20; i++) {
				//�������� ���� ��´�.
				if (matrix[i][x] == 22) matrix[i][x] = 2;
				//������ ������ P1�� �������� ����
				else matrix[i][x] = 22;
			}
		}
		else if (97 <= x && x <= 116) {
			for (int i = 1; i <= 20; i++) {
				if (matrix[i][x] == 1) return true;
			}
			for (int i = 1; i <= 20; i++) {
				//�������� ���� ��´�.
				/*
				x-96 -> �迭�� ���� ���߱� ����.
				*/
				if (matrix[x - 96][i] == 22) matrix[x - 96][i] = 2;
				//������ ������ P1�� �������� ����
				else matrix[x - 96][i] = 22;
			}
		}
	}
	return false;
}

void specialRule(int matrix[][COL]) {
	for (int i = 2; i <= 19; i++) {
		for (int j = 2; j <= 19; j++) {
			//P1 specialRule  ����
			if (matrix[i][j] == 1 &&
				matrix[i - 1][j - 1] == 2 && //�»�
				matrix[i - 1][j + 1] == 2 && //���
				matrix[i + 1][j - 1] == 2 &&//����
				matrix[i + 1][j + 1] == 2) //����
				matrix[i][j] = 2;

			//P2 specialRule  ����
			if (matrix[i][j] == 2 &&
				matrix[i - 1][j - 1] == 1 && //�»�
				matrix[i - 1][j + 1] == 1 && //���
				matrix[i + 1][j - 1] == 1 &&//����
				matrix[i + 1][j + 1] == 1) //����
				matrix[i][j] = 1;
		}

	}

}

bool isOver(int matrix[][COL]) {
	int count = 0;
	for (int i = 1; i < 21; i++) {
		for (int j = 1; j < 21; j++)
			if (matrix[i][j] == 0) count++;
	}
	return (count == 0) ? false : true;
}

void point(int matrix[][COL]) {
	int p1_Point = 0;
	int p2_Point = 0;

	for (int i = 1; i <= 20; i++) {
		for (int j = 1; j <= 20; j++) {
			if (matrix[i][j] == 1) p1_Point++;
			else if (matrix[i][j] == 2) p2_Point++;
		}
	}

	printf("Player1�� ����: %d\n", p1_Point);
	printf("Player2�� ����: %d\n\n", p2_Point);


	printf("Player%d�� �¸�!!\n", (p1_Point > p2_Point) ? 1:2);

}

