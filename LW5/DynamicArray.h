#pragma once
#include <string>
#include "Dekanat.h"

#define N 8

class DynamicArray
{
private:
	Dekanat* array = new Dekanat[N + 1];
	int cur_size = 0;
	int max_size = N;
	int head = 0, 
		tail = 0;

public:
	bool push_back(Dekanat el);
	Dekanat pop_back();

	bool push_front(Dekanat el);
	Dekanat pop_front();

	Dekanat get(int index);
	int size();

	void print();

private:
	bool resize(int new_size);

};

class EmptyArrayException
{
public:
	EmptyArrayException();
	EmptyArrayException(std::string _text);
	std::string what();

private:
	std::string text;
};


