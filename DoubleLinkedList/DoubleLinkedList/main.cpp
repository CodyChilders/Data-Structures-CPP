#include <iostream>
#include "DoubleLinkedList.h"

#define numberOfElements 25

inline void HoldPromptOpen()
{
	std::cin.get();
}

int main()
{
	DoubleLinkedList dll;
	for (int i = 0; i < numberOfElements; i++)
	{
		dll.Append(i);
	}
	std::cout << "Current list: ";
	std::cout << dll.ToString() << std::endl << std::endl;

	std::cout << "Removing the last 3 elements" << std::endl;
	for (int i = 0; i < 3; i++)
	{
		dll.RemoveLast();
	}
	std::cout << dll.ToString() << std::endl << std::endl;

	std::cout << "Adding 3 100's as the first element" << std::endl;
	for (int i = 0; i < 3; i++)
	{
		dll.AddAtFirst(100);
	}
	std::cout << dll.ToString() << std::endl << std::endl;

	std::cout << "Removing first element" << std::endl;
	dll.RemoveFirst();
	std::cout << dll.ToString() << std::endl << std::endl;

	std::cout << "Removing at index (1) 3 times" << std::endl;
	for (int i = 0; i < 3; i++)
	{
		dll.RemoveAt(1);
	}
	std::cout << dll.ToString() << std::endl << std::endl;

	//fix this operation
	std::cout << "Adding a -500 at indices 0, 5, (length - 1), and 9999 (should be skipped and not crash)" << std::endl;
	dll.InsertAt(0, -500);
	dll.InsertAt(5, -500);
	dll.InsertAt(dll.CurrentCapacity() - 1, -500);
	dll.InsertAt(9999, -500);
	std::cout << dll.ToString() << std::endl << std::endl;
	//

	
	std::cout << "Removing first instances of numbers -500, 15, and 999999" << std::endl;
	dll.RemoveFirstInstanceOf(-500);
	dll.RemoveFirstInstanceOf(15);
	dll.RemoveFirstInstanceOf(999999);
	std::cout << dll.ToString() << std::endl << std::endl;
	
	std::cout << "Printing the list backwards" << std::endl;
	std::cout << dll.BackwardsToString() << std::endl << std::endl;

	HoldPromptOpen();
}