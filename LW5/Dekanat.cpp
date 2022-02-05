#pragma once
#include "Dekanat.h"

std::ostream& operator<<(std::ostream& os, const Dekanat& el)
{
	os << "\n\tDekanat has: " << el.employee_cnt << " employees with productivity " << el.productivity 
		<< ". Opening at " << el.hours.opening_time << " and close at " << el.hours.closing_time;
	return os;
}
