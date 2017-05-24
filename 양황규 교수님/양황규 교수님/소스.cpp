#include <cstdio>
#include <cstdlib>
#include <ctime>

/*
필드 규칙
0 : 아무것도 놓아져 있지 않는 초기상태를 의미한다.
1 : Player1 돌을 놓은 자리를 의미한다.
2 : Player2 돌을 놓은 자리를 의미한다.
11 : Player1이 돌이 놓은 자리의 가로 세로 라인을 의미한다. (놓아진 부분은 제외)
22 : Player2이 돌이 놓은 자리의 가로 세로 라인을 의미한다. (놓아진 부분은 제외)
*/


/*

-commit log
좌표 설정은 구현완료 하였고 턴 넘기는 것도 구현을 마쳤다.
게임 방식을 다시 적용해야한다.
두번째 턴부터는 좌표값 하나만을 입력받기 때문이다.

*/

/*
matrix 변수 = 게임을 하는 판 20 X 20 행렬로 이루어져 있다.
Player 변수 = 플레이어를 담고있는 변수
turnCount 변수 = 턴 수를 카운트 하는 변수
turn 변수 = 누구의 턴인지 알려주는 변수
*/

int matrix[22][22] = { 0 };
int turnCount = 0;
bool turn; //true는 P1 false는 P2

/*
	출력함수
	showMatrix() = 매트릭스 배열을 출력
	matrixBasic() =  아무것도 놓아져 있지 않는 구간을 출력
	matrixGo() = 돌이 놓아져 있는 구간을 출력
*/

void showMatrix();
void matrixBasic(int, int);
void matrixGo(int, int);


/*
	기초함수
	randSetting() = 선공을 정하는 함수
	doGame() =  main의 역할을 하며 게임의 진행을 총괄하는 함수
*/
void randSetting();
void doGame();

/*
	플레이 함수
	checkingField() = 양 플레이어의 첫번째 턴에서 실행되는 함수
	checkingField() = 2턴 이후 부터 실행되는 함수
	isOver() = 플레이가 끝났음을 확인해주는 함수
*/
bool checkingField(char, int, int turn);
bool checkingField2(int x, int turn);
bool isOver();
void specialRule();

int main() {
	srand((unsigned int)time(0));
	randSetting();
	while (isOver()) {
		system("cls");
		showMatrix();
		doGame();
	}
	printf("플레이 끝\n게임을 종료합니다.");
	return 0;
}



void doGame() {
	int i;
	char j;
	char valChar;
	int valInt;
	bool loopFlag = true;
	printf("Player%d의 턴", (turn == 1) ? 1 : 2);

	if (turnCount <= 1) {
		do {
			printf("좌표 입력( x: 1~20, y: a~t ) : ");
			scanf_s("%d %c", &i, &j);

			loopFlag = checkingField(j - 96, i, turn);
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
				loopFlag = checkingField2(valInt, turn);
			}
			else if (inputType == 2) {
				getchar();
				printf("좌표 입력( a~t ) : ");
				scanf_s("%c", &valChar);
				getchar();
				loopFlag = checkingField2(valChar, turn);
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

void specialRule() {
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

bool checkingField(char i, int j, int turn) {
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

bool checkingField2(int x, int turn) {

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


bool isOver() {
	int count = 0;
	for (int i = 1; i < 21; i++) {
		for (int j = 1; j < 21; j++)
			if (matrix[i][j] == 0) count++;
	}
	return (count == 0) ? false : true;
}






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











/*
출력 필드
*/


void showMatrix() {
	for (int i = 0; i < 21; i++) {

		//첫번째 줄에 좌표 출력하는 반복문
		if (i == 0)
			for (int l = 0; l <= 20; l++)
				//좌표출력 (숫자)
				(l == 0) ? printf(" ") : printf("%2d ", l);



		else {
			for (int j = 0; j < 21; j++) {
				if (matrix[i][j] == 0 || matrix[i][j] == 11 || matrix[i][j] == 22)
					matrixBasic(i, j);
				else
					matrixGo(i, j);
			}

		}

		//
		//줄바꿈
		printf("\n\n");

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