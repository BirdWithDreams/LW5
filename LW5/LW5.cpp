#include <iostream>
#include <exception>

#include "DynamicArray.h"
#include "LinkedList.h"

void set_random_dek(Dekanat& dek);

int main()
{
	Dekanat dek;
	LinkedList list;
	set_random_dek(dek);
	list.push_front(dek);
	list.print();

	set_random_dek(dek);
	list.push_front(dek);
	list.print();


	list.pop_front();
	list.print();

	list.pop_front();
	list.print();
    return 0;
}

void set_random_dek(Dekanat& dek)
{
	dek.employee_cnt = rand() % 10;
	dek.hours.opening_time = rand() % 4 + 7;
	dek.hours.closing_time = rand() % 4 + 17;
	dek.productivity = rand() % 10;
}
