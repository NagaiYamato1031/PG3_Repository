#include <stdio.h>
#include <thread>
#include <queue>
#include <condition_variable>
#include <mutex>

#include <functional>

#include <sstream>
#include <fstream>
#include <string>
#include <array>

#define MAP_SIZE 16

void GetCSVFile(std::array<std::array<int, MAP_SIZE>, MAP_SIZE>& data_)
{
	std::stringstream ss;
	std::ifstream file;
	file.open("csv.txt");
	// 開けなかったら
	if (!file.is_open())
	{
		return;
	}
	ss << file.rdbuf();

	file.close();

	std::string line;
	int i = 0, j = 0;
	while (std::getline(ss, line))
	{
		std::istringstream line_stream(line);

		std::string word;
		for (size_t index = 0; index < MAP_SIZE; index++)
		{
			std::getline(line_stream, word, ',');
			data_[i][j] = std::stoi(word.c_str());
			j++;
			if (MAP_SIZE <= j)
			{
				i++;
				j = 0;
			}
		}
	}
}

int main()
{
	std::array<std::array<int, MAP_SIZE>, MAP_SIZE> mapData_{ 0 };

	std::function<void(void)> PrintMap = [&mapData_](){
		for (size_t i = 0; i < MAP_SIZE; i++)
		{
			for (size_t j = 0; j < MAP_SIZE; j++)
			{
				printf(" %d", mapData_[i][j]);
			}
			printf("\n");
		}
	};

	std::mutex mutex;
	std::condition_variable condition;
	bool exit = false;

	PrintMap();

	std::thread th([&]() {
		std::unique_lock<std::mutex> uniqueLock(mutex);
		while (!exit)
		{
			condition.wait(uniqueLock);
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			GetCSVFile(mapData_);
			system("cls");

			PrintMap();
		}
		});

	while (true)
	{
		condition.notify_all();
	}
	exit = true;
	th.join();

	return 0;
}

//int main()
//{
//	std::mutex mutex;
//	std::condition_variable condition;
//	std::queue<int> q;
//	bool exit = false;
//
//	std::thread th([&]() {
//		std::unique_lock<std::mutex> uniqueLock(mutex);
//		while (!exit)
//		{
//			if (q.empty())
//			{
//				condition.wait(uniqueLock);
//				printf("wait:%d\n", q.size());
//			}
//			else
//			{
//				printf("pop:%d\n", q.size());
//				q.pop();
//				std::this_thread::sleep_for(std::chrono::milliseconds(200));
//			}
//		}
//		printf("thread end\n");
//		});
//
//	printf("start\n");
//	while (true)
//	{
//		char c = getchar();
//		if (c == '1')
//		{
//			q.push(2);
//			condition.notify_all();
//			printf("notify\n");
//		}
//		else if (!q.empty())
//		{
//			condition.notify_all();
//			printf("notify\n");
//		}
//		else if(c == '0')
//		{
//			printf("main end\n");
//			break;
//		}
//		else
//		{
//			printf("\r");
//		}
//	}
//	exit = true;
//	th.join();
//
//	return 0;
//}
