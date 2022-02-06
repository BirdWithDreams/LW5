#pragma once
#include <iostream>
struct hours_of_work
{
    short opening_time;
    short closing_time;
};

struct Dekanat
{
    short employee_cnt;
    hours_of_work hours;
    short productivity;
};

std::ostream& operator << (std::ostream& os, const Dekanat &el);
