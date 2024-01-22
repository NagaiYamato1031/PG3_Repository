#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

typedef void (*pFunc)(int);

void SetTimeout(int sleepTime) {
	int sleepDivision = sleepTime * 1000 / 4;
	Sleep(sleepDivision);
	printf(".");
	Sleep(sleepDivision);
	printf(".");
	Sleep(sleepDivision);
	printf(".\n");
	Sleep(sleepDivision);
}

// 丁半を返す
void CheckGambling(pFunc p, int num) {
	int rnd = rand() % 2;

	p(3);

	if (rnd == num) {
		printf("正解\n\n");
	}
	else {
		printf("不正解\n\n");
	}
}

void DiceGame() {
	printf("0 : 丁, 1 : 半\n->");

	int num = 0;
	scanf_s("%d", &num);

	pFunc p = SetTimeout;
	CheckGambling(p, num);
}

int main() {
	srand(time(nullptr));

	DiceGame();

	return 0;
}
