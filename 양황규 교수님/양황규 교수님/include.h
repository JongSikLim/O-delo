#pragma once
#include <cstdio>
#include <cstdlib>
#include <ctime>

#define COL 22
#define M_SIZE 22


/*
matrix 변수 = 게임을 하는 판 20 X 20 행렬로 이루어져 있다.
Player 변수 = 플레이어를 담고있는 변수
turnCount 변수 = 턴 수를 카운트 하는 변수
turn 변수 = 누구의 턴인지 알려주는 변수
*/

int matrix[M_SIZE][M_SIZE] = { 0 };
int turnCount = 0;
bool turn; //true는 P1 false는 P2

/*
필드 규칙
0 : 아무것도 놓아져 있지 않는 초기상태를 의미한다.
1 : Player1 돌을 놓은 자리를 의미한다.
2 : Player2 돌을 놓은 자리를 의미한다.
11 : Player1이 돌이 놓은 자리의 가로 세로 라인을 의미한다. (놓아진 부분은 제외)
22 : Player2이 돌이 놓은 자리의 가로 세로 라인을 의미한다. (놓아진 부분은 제외)
*/