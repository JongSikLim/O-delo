#include <cstdio>
#include <cstdlib>
#include <ctime>

/*
�ʵ� ��Ģ
0 : �ƹ��͵� ������ ���� �ʴ� �ʱ���¸� �ǹ��Ѵ�.
1 : Player1 ���� ���� �ڸ��� �ǹ��Ѵ�.
2 : Player2 ���� ���� �ڸ��� �ǹ��Ѵ�.
11 : Player1�� ���� ���� �ڸ��� ���� ���� ������ �ǹ��Ѵ�. (������ �κ��� ����)
22 : Player2�� ���� ���� �ڸ��� ���� ���� ������ �ǹ��Ѵ�. (������ �κ��� ����)
*/


/*

-commit log
��ǥ ������ �����Ϸ� �Ͽ��� �� �ѱ�� �͵� ������ ���ƴ�.
���� ����� �ٽ� �����ؾ��Ѵ�.
�ι�° �Ϻ��ʹ� ��ǥ�� �ϳ����� �Է¹ޱ� �����̴�.

*/

/*
matrix ���� = ������ �ϴ� �� 20 X 20 ��ķ� �̷���� �ִ�.
Player ���� = �÷��̾ ����ִ� ����
turnCount ���� = �� ���� ī��Ʈ �ϴ� ����
turn ���� = ������ ������ �˷��ִ� ����
*/

int matrix[22][22] = { 0 };
int turnCount = 0;
bool turn; //true�� P1 false�� P2

/*
	����Լ�
	showMatrix() = ��Ʈ���� �迭�� ���
	matrixBasic() =  �ƹ��͵� ������ ���� �ʴ� ������ ���
	matrixGo() = ���� ������ �ִ� ������ ���
*/

void showMatrix();
void matrixBasic(int, int);
void matrixGo(int, int);


/*
	�����Լ�
	randSetting() = ������ ���ϴ� �Լ�
	doGame() =  main�� ������ �ϸ� ������ ������ �Ѱ��ϴ� �Լ�
*/
void randSetting();
void doGame();

/*
	�÷��� �Լ�
	checkingField() = �� �÷��̾��� ù��° �Ͽ��� ����Ǵ� �Լ�
	checkingField() = 2�� ���� ���� ����Ǵ� �Լ�
	isOver() = �÷��̰� �������� Ȯ�����ִ� �Լ�
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
	printf("�÷��� ��\n������ �����մϴ�.");
	return 0;
}



void doGame() {
	int i;
	char j;
	char valChar;
	int valInt;
	bool loopFlag = true;
	printf("Player%d�� ��", (turn == 1) ? 1 : 2);

	if (turnCount <= 1) {
		do {
			printf("��ǥ �Է�( x: 1~20, y: a~t ) : ");
			scanf_s("%d %c", &i, &j);

			loopFlag = checkingField(j - 96, i, turn);
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
				loopFlag = checkingField2(valInt, turn);
			}
			else if (inputType == 2) {
				getchar();
				printf("��ǥ �Է�( a~t ) : ");
				scanf_s("%c", &valChar);
				getchar();
				loopFlag = checkingField2(valChar, turn);
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

void specialRule() {
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

bool checkingField(char i, int j, int turn) {
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

bool checkingField2(int x, int turn) {

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


bool isOver() {
	int count = 0;
	for (int i = 1; i < 21; i++) {
		for (int j = 1; j < 21; j++)
			if (matrix[i][j] == 0) count++;
	}
	return (count == 0) ? false : true;
}






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











/*
��� �ʵ�
*/


void showMatrix() {
	for (int i = 0; i < 21; i++) {

		//ù��° �ٿ� ��ǥ ����ϴ� �ݺ���
		if (i == 0)
			for (int l = 0; l <= 20; l++)
				//��ǥ��� (����)
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
		//�ٹٲ�
		printf("\n\n");

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