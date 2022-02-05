#pragma once
#include <iostream>
struct hours_of_work
{
    int opening_time;
    int closing_time;
};

struct Dekanat
{
    int employee_cnt;
    hours_of_work hours;
    int productivity;
};

std::ostream& operator << (std::ostream& os, const Dekanat &el);
