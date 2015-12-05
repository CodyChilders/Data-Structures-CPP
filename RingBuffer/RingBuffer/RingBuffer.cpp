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
	float avg = static_cast<double>(sum) / static_cast<double>(capacity);
	return avg;
}

std::string RB::ToString()
{
	std::string returnVal = "[ ";
	for (int i = 0; i < capacity; i++)
	{
		if (i == currentWriteIndex)
		{
			returnVal += "(";
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
