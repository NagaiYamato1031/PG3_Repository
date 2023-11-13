#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <functional>

typedef bool (*pFunc)(int);

// 丁半を返す
bool CheckGambling(int num) {
	std::function<bool(int)> check = [](int i) {return rand() % 2 == i; };

	std::function<void(int)> SetTimeOut = [](int time) {
		printf("さぁ果たしてあっているのか...？\n");
		Sleep(time * 1000);
	};

	SetTimeOut(3);

	if (check(num)) {
		printf("正解！さすがです！！！\n\n");
		return true;
	}
	else {
		printf("不正解！残念...\n\n");
		return false;
	}

}

void DiceGame(pFunc p) {
	std::function<int()> scan = []() {int num = 0; scanf_s("%d", &num); return num; };
	do {
		printf("0 : 丁, 1 : 半\n->");
	} while (!p(scan()));
}

int main() {
	srand(time(nullptr));

	pFunc p = CheckGambling;
	DiceGame(p);

	return 0;
}
