#pragma once
#include <string>

class ArrayList
{
public:
	ArrayList();
	~ArrayList();
	void AddElement(int elem);
	void RemoveLast();
	void ShrinkToFit();
	void RemoveAtIndex(int index);
	int Size();
	int Capacity();
	std::string ToString();
	int operator[](int idx);
private:
	int* currentArray =  nullptr;
	int currentIndexOfFirstOpen;
	int currentMaxLoad;
	void ResizeList();
};
