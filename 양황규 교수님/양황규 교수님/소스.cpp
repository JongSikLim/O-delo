#include <cstdio>
#include <cstdlib>
#include <ctime>
#include "출력함수.h"
#include "기초함수.h"

#define COL 22
#define M_SIZE 22


/*

-commit log
좌표 설정은 구현완료 하였고 턴 넘기는 것도 구현을 마쳤다.
게임 방식을 다시 적용해야한다.
두번째 턴부터는 좌표값 하나만을 입력받기 때문이다.

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
	printf("게임을 종료합니다.\n");

	return 0;
}

