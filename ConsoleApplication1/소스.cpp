#include <thread>
#include <iostream>
#include <mutex>

int main()
{
	std::mutex mtx_lock;

	std::thread Threads1([&]()
	{
		for (int i = 0; i < 5; ++i)
		{
			mtx_lock.lock();
			std::cout << "Thread Num : " << i << std::endl;
			mtx_lock.unlock();
		}
	});


	std::thread Threads2;
	Threads2 = std::thread([&]()
	{
		for (int i = 10; i < 15; ++i)
		{
			mtx_lock.lock();
			std::cout << "Thread Num : " << i << std::endl;
			mtx_lock.unlock();
		}
	});

	std::thread Threads3 = std::thread([&](int nParam)
	{
		for (int i = 20; i < 25; ++i)
		{
			mtx_lock.lock();
			std::cout << "Thread Parameter : " << nParam << std::endl;
			mtx_lock.unlock();
		}
	}, 4);



	getchar();
	return 0;
}