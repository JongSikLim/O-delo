#pragma once

#include "include.h"

/*
플레이 함수
checkingField() = 양 플레이어의 첫번째 턴에서 실행되는 함수
checkingField() = 2턴 이후 부터 실행되는 함수
isOver() = 플레이가 끝났음을 확인해주는 함수

*/
bool checkingField(char, int, int turn, int[][COL]);
bool checkingField2(int x, int turn, int[][COL]);
bool isOver(int[][COL]);
void specialRule(int[][COL]);
void point(int[][COL]);



bool checkingField(char i, int j, int turn, int matrix[][COL]) {
//P1 의 턴
if (turn == 1) {
	if (matrix[i][j] == 2 || matrix[i][j] == 22)
		return true;

	else {
		//라인영역 표시
		for (int x = 1; x < 21; x++)
			matrix[x][j] = 11;
		for (int x = 1; x < 21; x++)
			matrix[i][x] = 11;
		//좌표영역 표시
		matrix[i][j] = 1;
		//올바른 영역에 놓앗을 경우 return false
		return false;
	}
}
//P2 의 턴
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
	turn 1~20 은 세로좌표 1 ~ 20 이므로 행렬 중 렬값을 기준으로 라인을 만든다.
	turn a~t(97~116) 는 가로좌표이므로 행렬 중 행 값을 기준으로 라인을 만든다.
	*/
	printf("Player%d의 턴\n", (turn == 1) ? 1 : 2);
	//P1의 턴
	if (turn == 1) {
		//printf("x의값은 : %d\n\n", x);
		if (1 <= x && x <= 20) {
			for (int i = 1; i <= 20; i++) {
				if (matrix[i][x] == 2) return true;
			}
			for (int i = 1; i <= 20; i++) {
				//교점에서 점을 찍는다.
				if (matrix[i][x] == 11) matrix[i][x] = 1;
				//나머지 라인을 P1의 영역으로 변경
				else matrix[i][x] = 11;
			}
		}
		else if (97 <= x && x <= 116) {
			for (int i = 1; i <= 20; i++) {
				if (matrix[x - 96][i] == 2)return true;
			}
			for (int i = 1; i <= 20; i++) {
				//교점에서 점을 찍는다.
				/*
				x-96 -> 배열의 방을 맞추기 위함.
				*/
				if (matrix[x - 96][i] == 11) matrix[x - 96][i] = 1;
				//나머지 라인을 P1의 영역으로 변경
				else matrix[x - 96][i] = 11;

			}

		}
	}
	//P2의 턴
	else {
		if (1 <= x && x <= 20) {
			for (int i = 1; i <= 20; i++) {
				if (matrix[i][x] == 1) return true;
			}
			for (int i = 1; i <= 20; i++) {
				//교점에서 점을 찍는다.
				if (matrix[i][x] == 22) matrix[i][x] = 2;
				//나머지 라인을 P1의 영역으로 변경
				else matrix[i][x] = 22;
			}
		}
		else if (97 <= x && x <= 116) {
			for (int i = 1; i <= 20; i++) {
				if (matrix[i][x] == 1) return true;
			}
			for (int i = 1; i <= 20; i++) {
				//교점에서 점을 찍는다.
				/*
				x-96 -> 배열의 방을 맞추기 위함.
				*/
				if (matrix[x - 96][i] == 22) matrix[x - 96][i] = 2;
				//나머지 라인을 P1의 영역으로 변경
				else matrix[x - 96][i] = 22;
			}
		}
	}
	return false;
}

void specialRule(int matrix[][COL]) {
	for (int i = 2; i <= 19; i++) {
		for (int j = 2; j <= 19; j++) {
			//P1 specialRule  적용
			if (matrix[i][j] == 1 &&
				matrix[i - 1][j - 1] == 2 && //좌상
				matrix[i - 1][j + 1] == 2 && //우상
				matrix[i + 1][j - 1] == 2 &&//좌하
				matrix[i + 1][j + 1] == 2) //우하
				matrix[i][j] = 2;

			//P2 specialRule  적용
			if (matrix[i][j] == 2 &&
				matrix[i - 1][j - 1] == 1 && //좌상
				matrix[i - 1][j + 1] == 1 && //우상
				matrix[i + 1][j - 1] == 1 &&//좌하
				matrix[i + 1][j + 1] == 1) //우하
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

	printf("Player1의 점수: %d\n", p1_Point);
	printf("Player2의 점수: %d\n\n", p2_Point);


	printf("Player%d의 승리!!\n", (p1_Point > p2_Point) ? 1:2);

}

