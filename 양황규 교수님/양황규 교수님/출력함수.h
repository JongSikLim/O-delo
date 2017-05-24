#pragma once

#include "include.h"

/*
출력함수
showMatrix() = 매트릭스 배열을 출력
matrixBasic() =  아무것도 놓아져 있지 않는 구간을 출력
matrixGo() = 돌이 놓아져 있는 구간을 출력
*/

void showMatrix(int[][COL]);
void matrixBasic(int, int);
void matrixGo(int, int);


/*
출력 필드
*/


void showMatrix(int matrix[][COL]) {
	for (int i = 0; i < 21; i++) {

		//첫번째 줄에 좌표 출력하는 반복문
		if (i == 0)
			for (int l = 0; l <= 20; l++)
				//좌표출력 (숫자)
				(l == 0) ? printf(" ") : printf("%2d ", l);
		
		else {
			for (int j = 0; j < 21; j++) {
				//영역의 주인이 없을 때
				if (matrix[i][j] == 0 || matrix[i][j] == 11 || matrix[i][j] == 22)
					matrixBasic(i, j);
				//영역의 주인이 있을 때
				else
					matrixGo(i, j);
			}

		}

		//
		//줄바꿈
		printf("\n");

	}
}

//좌표에 아무것도 놓아져 있지 않는 경우 실행되는 함수 MatrixBasic
void matrixBasic(int i, int j) {
	if (j == 0) printf("%c ", i + 96); // 좌표출력 (알파벳_
	else if (i == 1 && j == 1) printf("┌ ");
	else if (i == 1 && j == 20) printf("┐");
	else if (i == 20 && j == 1) printf("└ ");
	else if (i == 20 && j == 20) printf("┘");
	else if (i == 1) printf("┬ ");
	else if (j == 1) printf("├ ");
	else if (i == 20) printf("┴ ");
	else if (j == 20) printf("┤");
	else printf("┼ ");
}
//좌표에 돌이 놓아져 있는 경우에 실행되는 함수 matrixGo
void matrixGo(int i, int j) {
	if (matrix[i][j] == 1) printf("● ");
	if (matrix[i][j] == 2) printf("○ ");
	if (matrix[i][j] == 11)printf("■ ");
	if (matrix[i][j] == 22)printf("□ ");
}