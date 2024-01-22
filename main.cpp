#include <stdio.h>
#include <functional>
#include <thread>

int main()
{
	std::function<void(int)> PrintNum = [](int num) {
		printf("thread %d\n", num);
	};

	std::thread th1(PrintNum, 1);
	th1.join();
	
	std::thread th2(PrintNum, 2);
	th2.join();

	std::thread th3(PrintNum, 3);
	th3.join();

	return 0;
}
