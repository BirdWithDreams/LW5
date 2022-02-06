#include <iostream>
#include <ctime>

#include "DynamicArray.h"
#include "LinkedList.h"

void set_random_dek(Dekanat& dek);

int main()
{
	Dekanat dek;
	set_random_dek(dek);
	LinkedList list;
	DynamicArray array;

	clock_t array_time[6];
	clock_t list_time[6];
	
	array_time[0] = clock();
	for (int i = 0; i < 50000; i++)
		array.push_back(dek);


	array_time[1] = clock();
	for (int i = 0; i < 10000; i++)
		array.push_front(dek);

	array_time[2] = clock();
	for (int i = 0; i < 20000; i++)
		array.get(rand() % 10000);

	array_time[3] = clock();
	for (int i = 0; i < 5000; i++)
		array.pop_front();

	array_time[4] = clock();
	for (int i = 0; i < 5000; i++)
		array.pop_back();
	array_time[5] = clock();

	std::cout << "Tests of Dynamic Array:"
		"\n\tAdding 50 000 items to the end: " << array_time[1] - array_time[0] <<
		"\n\tAdding 10 000 items to the begining: " << array_time[2] - array_time[1] <<
		"\n\tGetting 20 000 random items: " << array_time[3] - array_time[2] <<
		"\n\tDeleting 5000 items from the begining: " << array_time[4] - array_time[3] <<
		"\n\tDeleting 5000 items from the end: " << array_time[5] - array_time[4] <<
		"\n\tFinal runtime: " << array_time[5] - array_time[0] << std::endl;


	list_time[0] = clock();
	for (int i = 0; i < 50000; i++)
		list.push_back(dek);


	list_time[1] = clock();
	for (int i = 0; i < 10000; i++)
		list.push_front(dek);

	list_time[2] = clock();
	for (int i = 0; i < 20000; i++)
		list.get(rand() % 10000);

	list_time[3] = clock();
	for (int i = 0; i < 5000; i++)
		list.pop_front();

	list_time[4] = clock();
	for (int i = 0; i < 5000; i++)
		list.pop_back();
	list_time[5] = clock();

	std::cout << "\nTests of Linked List:"
		"\n\tAdding 50 000 items to the end: " << list_time[1] - list_time[0] <<
		"\n\tAdding 10 000 items to the begining: " << list_time[2] - list_time[1] <<
		"\n\tGetting 20 000 random items: " << list_time[3] - list_time[2] <<
		"\n\tDeleting 5000 items from the begining: " << list_time[4] - list_time[3] <<
		"\n\tDeleting 5000 items from the end: " << list_time[5] - list_time[4] <<
		"\n\tFinal runtime: " << list_time[5] - list_time[0] << std::endl;

    return 0;
}

void set_random_dek(Dekanat& dek)
{
	dek.employee_cnt = rand() % 10;
	dek.hours.opening_time = rand() % 4 + 7;
	dek.hours.closing_time = rand() % 4 + 17;
	dek.productivity = rand() % 10;
}
