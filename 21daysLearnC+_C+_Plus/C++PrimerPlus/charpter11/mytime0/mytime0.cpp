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

void Time::Reset(int h,int m)
{
    hours = h;
    minutes = m;
}

Time Time::Sum(const Time &t) const  
{
    Time sum;  //创建临时对象
    sum.minutes = minutes + t.minutes;
    sum.hours = hours + t.hours +sum.minutes / 60;
    sum.minutes %= 60;
    return sum;//返回值不可返回引用，因为临时对象在函数结束后被销毁，使用值返回意味着
}

void Time::Show() const
{
    std::cout << hours << "hours," << minutes << "minutes";
}
