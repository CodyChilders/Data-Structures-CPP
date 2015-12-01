#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <iostream>
#include <Windows.h>
#include "ArrayList.h"

#define DEBUG 1

#define numberOfElements 1000

void printCurrentListInfo(ArrayList& a)
{
	std::cout << std::endl;
	std::cout << "Number of elements: " << a.Size() << std::endl;
	std::cout << "Current capacity: " << a.Capacity() << std::endl;
	std::cout << "Current list: " << a.ToString() << std::endl;
	std::cout << std::endl;
}

int main()
{
#if _DEBUG
	_CrtDumpMemoryLeaks();
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	//Set up the list, show that it is populated
	ArrayList al;
	for (int i = 0; i < numberOfElements; i++)
	{
		al.AddElement(i);
	}
	printCurrentListInfo(al);
	
	std::cout << "Shrinking to fit" << std::endl;
	al.ShrinkToFit();
	printCurrentListInfo(al);

	std::cout << "Removing element at index 1" << std::endl;
	al.RemoveAtIndex(1);
	printCurrentListInfo(al);

	std::cout << "Checking array index operator" << std::endl;
	std::cout << "Value at index 0: " << al[0] << std::endl;
	std::cout << "Value at index 1: " << al[1] << std::endl;
	std::cout << "Value at index 2: " << al[2] << std::endl;
	std::cout << "Value at index 3: " << al[3] << std::endl;
	std::cout << std::endl;

	std::cout << "Removing last element" << std::endl;
	al.RemoveLast();
	printCurrentListInfo(al);
	
	std::cout << "Shrinking to fit" << std::endl;
	al.ShrinkToFit();
	printCurrentListInfo(al);

	Sleep(1000000); //hold the prompt open
}