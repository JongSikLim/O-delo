#pragma once
#include <cstdio>
#include <cstdlib>
#include <ctime>

#define COL 22
#define M_SIZE 22


/*
matrix ���� = ������ �ϴ� �� 20 X 20 ��ķ� �̷���� �ִ�.
Player ���� = �÷��̾ ����ִ� ����
turnCount ���� = �� ���� ī��Ʈ �ϴ� ����
turn ���� = ������ ������ �˷��ִ� ����
*/

int matrix[M_SIZE][M_SIZE] = { 0 };
int turnCount = 0;
bool turn; //true�� P1 false�� P2

/*
�ʵ� ��Ģ
0 : �ƹ��͵� ������ ���� �ʴ� �ʱ���¸� �ǹ��Ѵ�.
1 : Player1 ���� ���� �ڸ��� �ǹ��Ѵ�.
2 : Player2 ���� ���� �ڸ��� �ǹ��Ѵ�.
11 : Player1�� ���� ���� �ڸ��� ���� ���� ������ �ǹ��Ѵ�. (������ �κ��� ����)
22 : Player2�� ���� ���� �ڸ��� ���� ���� ������ �ǹ��Ѵ�. (������ �κ��� ����)
*/