#include <stdio.h>
#include <thread>
#include <queue>
#include <condition_variable>
#include <mutex>

int main()
{
	std::mutex mutex;
	std::condition_variable condition;
	std::queue<int> q;
	bool exit = false;

	std::thread th([&]() {
		std::unique_lock<std::mutex> uniqueLock(mutex);
		while (!exit)
		{
			if (q.empty())
			{
				condition.wait(uniqueLock);
			}
			else
			{
				q.pop();
				std::this_thread::sleep_for(std::chrono::milliseconds(4000));
			}
		}
		});

	while (true)
	{
		char c = getchar();
		if (c == '1')
		{
			q.push(2);
			condition.notify_all();
		}
		else if(c == '0')
		{
			break;
		}
	}
	exit = true;
	th.join();

	return 0;
}
