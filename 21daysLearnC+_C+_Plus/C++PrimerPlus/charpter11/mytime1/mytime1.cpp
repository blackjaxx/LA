//implementing Time methods
#include <iostream>
#include "mytime1.h"

//constructor
Time::Time()
{
    hours = minutes = 0;
}

//constructor2
Time::Time(int h, int m)
{
    hours = h;
    minutes = m;
}

void Time::AddMin(int m)
{
    minutes += m;
    hours += minutes / 60;
    minutes %= 60;
}

void Time::AddHr(int h)
{
    hours += h;
}

void Time::Reset(int h, int m)
{
    hours = h;
    minutes = m;
}

Time Time::operator+(const Time &t) const
{
    Time sum; //创建临时对象
    sum.minutes = minutes + t.minutes;
    sum.hours = hours + t.hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum; //返回值不可返回引用，因为临时对象在函数结束后被销毁，使用值返回意味着
}

void Time::Show() const
{
    std::cout << hours << "hours," << minutes << "minutes";
}


//和Sum()一样，operator+()也是由Time对象调用的，他将第二个Time对象作为参数，返回一个Time对象
//total = coding.operator+(fixing)
//也可以使用运算符表示法
//total = coding + fixing

