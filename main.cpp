#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

typedef void (*pFunc)(int);

void SetTimeout(int sleepTime) {
	Sleep(sleepTime * 1000);
	Sleep(sleepTime);
}

// 丁半を返す
void CheckGambling(pFunc p, int num) {
	int rnd = rand() % 2;
	printf("さぁ果たしてあっているのか...？\n");

	p(3);

	if (rnd == num) {
		printf("正解！さすがです！！！\n\n");
	}
	else {
		printf("不正解！残念...\n\n");
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
