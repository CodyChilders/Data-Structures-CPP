#include "DoubleLinkedList.h"

#define DLL DoubleLinkedList 

//for leak checking
#ifdef _DEBUG
	#ifndef DBG_NEW
		#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
		#define new DBG_NEW
	#endif
#endif  // _DEBUG

DLL::DoubleLinkedList()
{

}

DLL::~DoubleLinkedList()
{
	if (first == nullptr)
	{
		return;
	}
	Node* current = first;
	Node* previous;
	while (current != nullptr)
	{
		previous = current;
		current = current->next;
		delete previous;
	}
}

void DLL::Append(int data)
{
	Node* newData = new Node;
	newData->data = data;
	if (first == nullptr) //First thing going into the list
	{
		first = newData;
		last = newData;
	}
	else //Going in at the end of the list
	{
		last->next = newData;
		newData->previous = last;
		last = newData;
	}
	capacity++;
}

void DLL::AddAtFirst(int data)
{
	Node* newFirst = new Node;
	newFirst->data = data;
	if (first == nullptr)
	{
		first = last = newFirst;
	}
	else
	{
		newFirst->next = first;
		first->previous = newFirst;
		first = newFirst;
	}
	capacity++;
}

void DLL::InsertAt(int index, int data)
{
	if (index < 0 || index >= capacity)
		return;
	if (index == 0)
	{
		AddAtFirst(data);
	}
	else if (index == capacity - 1)
	{
		Append(data);
	}
	else
	{
		Node* nodeAtIndex = GetPointerToIndex(index);
		if (nodeAtIndex == nullptr)
			return;
		Node* newData = new Node;
		newData->data = data;
		//here, previous and next are defined relative to what they'll be at the end of this function
		Node* previous = nodeAtIndex->previous;
		Node* next = nodeAtIndex;
		if (previous != nullptr)
			previous->next = newData;
		if (next != nullptr)
			next->previous = newData;
		newData->previous = previous;
		newData->next = next;
		capacity++;
	}
}

void DLL::RemoveAt(int index)
{
	if (index < 0 || index >= capacity)
		return;
	//first and last introduce special cases, redirect to those methods if this is so
	if (index == 0)
	{
		RemoveFirst();
	}
	else if (index == capacity - 1)
	{
		RemoveLast();
	}
	else
	{
		Node* nodeAtIndex = GetPointerToIndex(index);
		if (nodeAtIndex == nullptr)
			return;
		Node* prev = nodeAtIndex->previous;
		Node* next = nodeAtIndex->next;
		if (prev != nullptr)
			prev->next = next;
		if (next != nullptr)
			next->previous = prev;
		delete nodeAtIndex;
		capacity--;
	}
}

void DLL::RemoveFirstInstanceOf(int val)
{
	if (first == nullptr)
		return;
	Node* nodeChecking;
	for (nodeChecking = first; nodeChecking != nullptr; nodeChecking = nodeChecking->next)
	{
		if (nodeChecking->data == val)
			break;
	}
	if (nodeChecking == nullptr)
		return;
	if (nodeChecking == first)
	{
		RemoveFirst();
	}
	else if (nodeChecking == last)
	{
		RemoveLast();
	}
	else
	{
		Node* previous = nodeChecking->previous;
		Node* next = nodeChecking->next;
		if (next != nullptr)
			next->previous = previous;
		if (previous != nullptr)
			previous->next = next;
		delete nodeChecking;
		capacity--;
	}
}

void DLL::RemoveFirst()
{
	if (first == nullptr)
		return;
	Node* oldFirst = first;
	first = first->next;
	first->previous = nullptr;
	delete oldFirst;
	capacity--;
}

void DLL::RemoveLast()
{
	if (last == nullptr)
		return;
	Node* oldLast = last;
	last = last->previous;
	last->next = nullptr;
	delete oldLast;
	capacity--;
}

int DLL::CurrentCapacity()
{
	return capacity;
}

std::string DLL::ToString()
{
	std::string returnVal = "[ ";
	Node* currentNode = first;
	while (currentNode != nullptr)
	{
		returnVal += std::to_string(currentNode->data);
		returnVal += " ";
		currentNode = currentNode->next;
	}
	returnVal += "]";
	return returnVal;
}

std::string DLL::BackwardsToString()
{
	std::string returnVal = "[ ";
	Node* currentNode = last;
	while (currentNode != nullptr)
	{
		returnVal += std::to_string(currentNode->data);
		returnVal += " ";
		currentNode = currentNode->previous;
	}
	returnVal += "]";
	return returnVal;
}

DLL::Node* DLL::GetPointerToIndex(int index)
{
	Node* desiredNode;
	int currentIndex = 0;
	desiredNode = first;
	while (currentIndex != index)
	{
		desiredNode = desiredNode->next;
		currentIndex++;
	}
	return desiredNode;
}