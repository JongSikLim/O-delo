#pragma once

#include "include.h"

/*
����Լ�
showMatrix() = ��Ʈ���� �迭�� ���
matrixBasic() =  �ƹ��͵� ������ ���� �ʴ� ������ ���
matrixGo() = ���� ������ �ִ� ������ ���
*/

void showMatrix(int[][COL]);
void matrixBasic(int, int);
void matrixGo(int, int);


/*
��� �ʵ�
*/


void showMatrix(int matrix[][COL]) {
	for (int i = 0; i < 21; i++) {

		//ù��° �ٿ� ��ǥ ����ϴ� �ݺ���
		if (i == 0)
			for (int l = 0; l <= 20; l++)
				//��ǥ��� (����)
				(l == 0) ? printf(" ") : printf("%2d ", l);
		
		else {
			for (int j = 0; j < 21; j++) {
				//������ ������ ���� ��
				if (matrix[i][j] == 0 || matrix[i][j] == 11 || matrix[i][j] == 22)
					matrixBasic(i, j);
				//������ ������ ���� ��
				else
					matrixGo(i, j);
			}

		}

		//
		//�ٹٲ�
		printf("\n");

	}
}

//��ǥ�� �ƹ��͵� ������ ���� �ʴ� ��� ����Ǵ� �Լ� MatrixBasic
void matrixBasic(int i, int j) {
	if (j == 0) printf("%c ", i + 96); // ��ǥ��� (���ĺ�_
	else if (i == 1 && j == 1) printf("�� ");
	else if (i == 1 && j == 20) printf("��");
	else if (i == 20 && j == 1) printf("�� ");
	else if (i == 20 && j == 20) printf("��");
	else if (i == 1) printf("�� ");
	else if (j == 1) printf("�� ");
	else if (i == 20) printf("�� ");
	else if (j == 20) printf("��");
	else printf("�� ");
}
//��ǥ�� ���� ������ �ִ� ��쿡 ����Ǵ� �Լ� matrixGo
void matrixGo(int i, int j) {
	if (matrix[i][j] == 1) printf("�� ");
	if (matrix[i][j] == 2) printf("�� ");
	if (matrix[i][j] == 11)printf("�� ");
	if (matrix[i][j] == 22)printf("�� ");
}