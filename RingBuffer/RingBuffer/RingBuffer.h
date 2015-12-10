#pragma once
#include <string>
#define RB RingBuffer

class RingBuffer
{
public:
	RingBuffer();
	RingBuffer(int initialCapacity);
	~RingBuffer();
	void Add(int value);
	double AverageContents();
	void Resize(int newSize);
	std::string ToString();
private:
	int* buffer;
	int currentWriteIndex;
	int capacity;
	void EmptyInitialBuffer();
};