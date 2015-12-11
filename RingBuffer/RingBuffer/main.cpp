#include <iostream>
#include <cstdlib>
#include <ctime>
#include "RingBuffer.h"

#define capacity 25

int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

int GetRand()
{
	int val = rand();
	bool sign = rand() % 2 == 0;
	if (sign)
		return val * -1;
	else
		return val;
}

int main()
{
	RB ringbuf(capacity);
	srand(time(NULL));
	for (int i = 0; i < 15; i++)
	{
		ringbuf.Add(GetRand());
	}
	std::cout << "Buffer with 15 elements: " << ringbuf.ToString() << std::endl;
	std::cout << "Average: " << ringbuf.AverageContents() << std::endl << std::endl;
	
	for (int i = 0; i < 10; i++)
	{
		ringbuf.Add(GetRand());
	}
	std::cout << "Buffer with 25 elements: " << ringbuf.ToString() << std::endl;
	std::cout << "Average: " << ringbuf.AverageContents() << std::endl << std::endl;

	for (int i = 0; i < 15; i++)
	{
		ringbuf.Add(GetRand());
	}
	std::cout << "Buffer had 15 more added: " << ringbuf.ToString() << std::endl;
	std::cout << "Average: " << ringbuf.AverageContents() << std::endl << std::endl;

	for (int i = 0; i < capacity; i++)
	{
		ringbuf.Add(GetRand());
	}
	std::cout << "Overwrote with random data - make sure it is still sensible: " << ringbuf.ToString() << std::endl;
	std::cout << "Average: " << ringbuf.AverageContents() << std::endl << std::endl;

	ringbuf.Resize(500);
	for (int i = 0; i < 1234; i++)
	{
		ringbuf.Add(GetRand());
	}
	std::cout << "Buffer resized to 500.  New average: " << ringbuf.AverageContents() << std::endl;
	std::cout << "Current buffer: " << ringbuf.ToString() << std::endl << std::endl;

	ringbuf.Resize(max(rand(), 600));
	int loopMax = rand();
	for (int i = 0; i < loopMax; i++)
	{
		ringbuf.Add(GetRand());
	}
	std::cout << "Resized buffer to a random size.  Current buffer: " << ringbuf.ToString() << std::endl;
	std::cout << "Average: " << ringbuf.AverageContents() << std::endl;

	std::cin.get(); //hold window open
}