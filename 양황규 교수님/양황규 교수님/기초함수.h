#pragma once

#include "include.h"
#include "플레이함수.h"

/*
기초함수
randSetting() = 선공을 정하는 함수
doGame() =  main의 역할을 하며 게임의 진행을 총괄하는 함수
*/
void randSetting();
void doGame();

/*
초기 랜덤값 세팅
*/

void randSetting() {
	int playerA, playerB; // 플레이어 변수
	playerA = rand() % 100 + 1;
	playerB = rand() % 100 + 1;
	printf("Player 1 :%d\n", playerA);
	printf("Player 2 :%d\n", playerB);

	if (playerA > playerB) {
		turn = 1;
		printf("playerA가 선으로 시작한다.");
	}
	else {
		turn = 0;
		printf("playerB가 선으로 시작한다.");
	}
	printf("\n엔터를 입력하면 게임을 시작합니다.");
	getchar();
}



void doGame() {
	int i;
	char j;
	char valChar;
	int valInt;
	bool loopFlag = true;
	printf("Player%d의 턴\n", (turn == 1) ? 1 : 2);

	if (turnCount <= 1) {
		do {
			printf("좌표 입력( x: 1~20, y: a~t ) : ");
			scanf_s("%d %c", &i, &j);

			loopFlag = checkingField(j - 96, i, turn, matrix);
			turn = !turn;
		} while (loopFlag);
		turnCount++;

	}

	//2턴 째 부터
	else {
		do {
			int inputType;
			printf("숫자 입력 1) \n문자 입력 2)  \n입력:  ");
			scanf_s("%d", &inputType);

			if (inputType == 1) {
				printf("좌표 입력( 1~20) : ");
				scanf_s("%d", &valInt);
				loopFlag = checkingField2(valInt, turn, matrix);
			}
			else if (inputType == 2) {
				getchar();
				printf("좌표 입력( a~t ) : ");
				scanf_s("%c", &valChar);
				getchar();
				loopFlag = checkingField2(valChar, turn, matrix);
			}

			/*
			아스키 1 - 49
			아스키 a - 97
			*/




			turn = !turn;
		} while (loopFlag);
		turnCount++;
	}
}