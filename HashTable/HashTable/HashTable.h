#pragma once
#include <string>

class HashTable
{
public:
	HashTable();
	~HashTable();
	void AddString(std::string str);
	bool ContainsString(std::string);
	void PrintTable();
private:
	void ResizeTable();
	int GetIndex(std::string str);
	std::string* array;
	int currentLength;
	int currentLoad;
};
