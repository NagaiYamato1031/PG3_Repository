#include <stdio.h>

#define NORMALWAGES 1072

int NormWages(int hour) {
	return NORMALWAGES * hour;
}

int RecWages(int hour, int preWages = 100) {
	int wages = preWages * 2 - 50;
	if (hour <= 0) {
		return 0;
	}
	return preWages + RecWages(hour - 1, wages);
}

int RecWagesPerHour(int hour, int preWages = 100) {
	int wages = preWages * 2 - 50;
	if (hour <= 0) {
		return 0;
	}
	else if (hour == 1) {
		return preWages;
	}
	return RecWagesPerHour(hour - 1, wages);

}


int main() {

	while (1) {

		int hour = 0;
		printf("\n働いた時間 :");
		scanf_s("%d", &hour);

		if (hour == -1) {
			break;
		}

		printf("一般的 合計 : %d\n", NormWages(hour));
		printf("一般的 時給 : %d\n", NORMALWAGES);
		printf("再帰的 合計 : %d\n", RecWages(hour));
		printf("再帰的 最終 : %d\n", RecWagesPerHour(hour));

	}

	return 0;
}
