#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <iostream>
//#include <cstdlib>
#include <ctime>
#include "RingBuffer.h"

#define capacity 25

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
	_CrtDumpMemoryLeaks();
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
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

	std::cin.get(); //hold window open
}