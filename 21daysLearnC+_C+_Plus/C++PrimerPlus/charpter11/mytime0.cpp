//implementing Time methods
#include <iostream>
#include "mytime0.h"

//constructor
Time::Time()
{
    hours = minutes = 0;
}

//constructor2
Time::Time(int h,int m)
{
    hours = h;
    minutes = m;
}

void Time::AddMin(int m)
{
    minutes += m;
    hours += minutes /60;
    minutes %= 60;
}

void Time::AddHr(int h)
{
    hours += h;
}