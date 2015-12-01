#include <string>
#include <iostream>
#include "ArrayList.h"

//for leak checking
#ifdef _DEBUG
	#ifndef DBG_NEW
		#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
		#define new DBG_NEW
	#endif
#endif  // _DEBUG

#define AL ArrayList

#define startingMax 10

AL::ArrayList()
{
	currentMaxLoad = startingMax;
	currentIndexOfFirstOpen = 0;
	currentArray = new int[startingMax];
}

AL::~ArrayList()
{
	if (currentArray != nullptr)
		delete[] currentArray;
}

void AL::AddElement(int elem)
{
	//first check if we need to resize
	if (currentIndexOfFirstOpen == currentMaxLoad)
	{
		ResizeList();
	}
	//move the index one and add the element in
	currentArray[currentIndexOfFirstOpen++] = elem;
}

void AL::RemoveLast()
{
	currentIndexOfFirstOpen--;
}

void AL::ShrinkToFit()
{
	int* newArray = new int[currentIndexOfFirstOpen];
	for (int i = 0; i < currentIndexOfFirstOpen; i++)
	{
		newArray[i] = currentArray[i];
	}
	int* oldArray = currentArray;
	currentArray = newArray;
	delete[] oldArray;
	currentMaxLoad = currentIndexOfFirstOpen;
}

void AL::RemoveAtIndex(int index)
{
	for (int i = index; i < currentIndexOfFirstOpen; i++)
	{
		currentArray[i] = currentArray[i + 1];
	}
	currentIndexOfFirstOpen--;
}

int AL::Size()
{
	return currentIndexOfFirstOpen;
}

int AL::Capacity()
{
	return currentMaxLoad;
}

std::string AL::ToString()
{
	std::string returnVal = "";
	returnVal += "[ ";
	for (int i = 0; i < currentIndexOfFirstOpen; i++)
	{
		returnVal += std::to_string(currentArray[i]);
		returnVal += " ";
	}
	returnVal += "]";
	return returnVal;
}

void AL::ResizeList()
{
	int* oldArray = currentArray;
	int* newArray = new int[currentMaxLoad * 2];
	for (int i = 0; i <= currentIndexOfFirstOpen; i++)
	{
		newArray[i] = oldArray[i];
	}
	currentArray = newArray;
	currentMaxLoad *= 2;
	delete[] oldArray;
}

int AL::operator[](int idx) 
{ 
	return currentArray[idx]; 
}
