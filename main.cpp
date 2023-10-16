#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <functional>

typedef void (*pFunc)(int);

// 丁半を返す
void CheckGambling(int num) {
	std::function<bool(int)> check = [](int i) {return rand() % 2 == i; };

	printf("さぁ果たしてあっているのか...？\n");
	Sleep(3 * 1000);
	
	if (check(num)) {
		printf("正解！さすがです！！！\n\n");
	}
	else {
		printf("不正解！残念...\n\n");
	}
}

void DiceGame(pFunc p) {
	printf("0 : 丁, 1 : 半\n->");

	std::function<int()> scan = []() {int num = 0; scanf_s("%d", &num); return num; };
	int num = scan();

	p(num);
}

int main() {
	srand(time(nullptr));

	pFunc p = CheckGambling;
	DiceGame(p);

	return 0;
}
