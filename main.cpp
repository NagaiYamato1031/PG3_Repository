#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <functional>

typedef void (*pFunc)(int);

void SetTimeout(int sleepTime)
{
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
bool CheckGambling(pFunc p, int num) {
	std::function<bool(int)> check = [](int i) {return rand() % 2 == i; };

	p(3);

	if (check(num)) {
		printf("正解\n\n");
		return true;
	}
	else {
		printf("不正解\n\n");
		return false;
	}

}

void DiceGame() {
	std::function<int()> scan = []() {int num = 0; scanf_s("%d", &num); return num; };
	pFunc p = SetTimeout;
	do {
		printf("0 : 丁, 1 : 半\n->");
	} while (!CheckGambling(p, scan()));
}

int main() {
	srand(time(nullptr));

	DiceGame();

	return 0;
}
