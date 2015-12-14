#include "RingBuffer.h"

#define defaultCapacity 10

RB::RingBuffer()
{
	buffer = new int[defaultCapacity];
	capacity = defaultCapacity;
	currentWriteIndex = 0;
	EmptyInitialBuffer();
}

RB::RingBuffer(int initialCapacity)
{
	buffer = new int[initialCapacity];
	capacity = initialCapacity;
	currentWriteIndex = 0;
	EmptyInitialBuffer();
}

RB::~RingBuffer()
{
	delete[] buffer;
}

void RB::Add(int value)
{
	buffer[currentWriteIndex++] = value;
	if (currentWriteIndex == capacity)
		currentWriteIndex = 0;
}

double RB::AverageContents()
{
	int sum = 0;
	for (int i = 0; i < capacity; i++)
	{
		sum += buffer[i];
	}
	double avg = static_cast<double>(sum) / static_cast<double>(capacity);
	return avg;
}

void RB::Resize(int newSize)
{
	if (newSize <= 0)
		return;
	delete[] buffer;
	buffer = new int[newSize];
	capacity = newSize;
	EmptyInitialBuffer();
}

std::string RB::ToString()
{
	std::string returnVal = "[ ";
	for (int i = 0; i < capacity; i++)
	{
		if (i == currentWriteIndex)
		{
			returnVal += "("; //parens denote which element the next write will be at
		}
		returnVal += std::to_string(buffer[i]);
		if (i == currentWriteIndex)
		{
			returnVal += ") ";
		}
		else
		{
			returnVal += " ";
		}
	}
	returnVal += "]";
	return returnVal;
}

void RB::EmptyInitialBuffer()
{
	for (int i = 0; i < capacity; i++)
	{
		buffer[i] = 0;
	}
}
