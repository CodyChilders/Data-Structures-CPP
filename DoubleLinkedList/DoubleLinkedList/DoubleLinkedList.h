#pragma once
#include <string>

class DoubleLinkedList
{
public:
	struct Node
	{
		int data;
		Node* previous = nullptr;
		Node* next = nullptr;
	};
	DoubleLinkedList();
	~DoubleLinkedList();
	void Append(int data);
	void AddAtFirst(int data);
	void InsertAt(int index, int data);
	void RemoveAt(int index);
	void RemoveFirstInstanceOf(int val);
	void RemoveFirst();
	void RemoveLast();
	int CurrentCapacity();
	std::string ToString();
	std::string BackwardsToString();

private:
	Node* first = nullptr;
	Node* last = nullptr;
	int capacity = 0;

	Node* GetPointerToIndex(int index);
};