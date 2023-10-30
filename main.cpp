#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

typedef void (*pFunc)(int, int);

// 丁半を返す
void CheckGambling(int num, int sleepTime) {
	int rnd = rand() % 2;
	printf("さぁ果たしてあっているのか...？\n");
	Sleep(sleepTime);
	if (rnd == num) {
		printf("正解！さすがです！！！\n\n");
	}
	else {
		printf("不正解！残念...\n\n");
	}
}

void DiceGame(pFunc p) {
	printf("0 : 丁, 1 : 半\n->");

	int num = 0;
	scanf_s("%d", &num);

	p(num, 3000);
}

int main() {
	srand(time(nullptr));

	pFunc p = CheckGambling;
	DiceGame(p);

	return 0;
}
