#include <iostream>
#include "HashTable.h"
#include "StringOps.h"

#define HT HashTable
#define startingTableSize 5
#define resetLoad 0.5

HT::HashTable()
{
	currentLength = startingTableSize;
	currentLoad = 0;
	array = new std::string[startingTableSize];
}

HT::~HashTable()
{
	delete[] array;
}

void HT::AddString(std::string str)
{
	float futureCapacity = static_cast<float>(currentLoad + 1) / static_cast<float>(currentLength);
	if (futureCapacity >= resetLoad)
	{
		ResizeTable();
	}
	int index = GetIndex(str);
	//find the index that it actually goes in
	while (true)
	{
		if (array[index].compare(str) == 0)
		{
			//we found a match, this is already in the table.  No need to store a repeat
			break;
		}
		else if (array[index].compare("") != 0) //check if the index is empty
		{
			//the spot is taken, move to the next one
			index++;
			if (index == currentLength) //Reset the index to 0, we ran off the end of the table
				index = 0;
		}
		else //put it in the array, the spot is good
		{
			array[index] = str;
			currentLoad++;
			break;
		}
	}
}

bool HT::ContainsString(std::string str)
{
	int index = GetIndex(str);
	while (true)
	{
		if (array[index].compare(str) == 0)
		{
			return true;
		}
		else if (array[index].compare("") == 0)
		{
			return false;
		}
		else
		{
			index++;
			if (index == currentLength)
				index = 0;
		}
	}
}

void HT::ResizeTable()
{
	//set up for the new table
	int newLength = currentLength * 2;
	std::string* newTable = new std::string[newLength];
	//hold on to the numbers from the old table
	int oldLength = currentLength;
	std::string* oldTable = array;
	//set up the new table
	currentLength = newLength;
	array = newTable;
	//find all the old elements, put them in a new location
	for (int i = 0; i < oldLength; i++)
	{
		std::string stringHere = oldTable[i];
		if (stringHere.compare("") != 0)
		{
			AddString(stringHere);
		}
	}
	delete[] oldTable;
}

int HT::GetIndex(std::string str)
{
	int hashCode = GetHashCode(str);
	int code = hashCode % currentLength;
	return code;
}

void HT::PrintTable()
{
	for (int i = 0; i < currentLength; i++)
	{
		std::cout << i << ": " << array[i] << std::endl;
	}
}
