#pragma once
#include "Node.h"
#include "exceptions.h"

class LinkedList
{
private:
	int cur_size = 0;
	Node* head = nullptr, 
		* tail = nullptr;

public:
	bool push_back(Dekanat el);
	Dekanat pop_back();

	bool push_front(Dekanat el);
	Dekanat pop_front();

	Dekanat get(int index);
	int size();

	void print();

};
