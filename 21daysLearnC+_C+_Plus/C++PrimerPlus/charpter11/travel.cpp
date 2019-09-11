//函数和结构
//获得结构的地址，需要使用&
//按值传递结构有一缺点，当结构非常大，复制结构将增加内存要求，降低系统运行速度

//当结构比较小，按值传递结构非常合理

// travel.cpp -- using structures with functions
#include <iostream>
struct travel_time
{
    int hours;
    int mins;
};  //定义结构体
const int Mins_per_hr = 60;

travel_time sum(travel_time t1, travel_time t2);  //返回值类型为travel_time
void show_time(travel_time t);

int main()
{
    using namespace std;
    travel_time day1 = {5, 45}; // 5 hrs, 45 min
    travel_time day2 = {4, 55}; // 4 hrs, 55 min

    travel_time trip = sum(day1, day2);
    cout << "Two-day total: ";
    show_time(trip);

    travel_time day3 = {4, 32};
    cout << "Three-day total: ";
    show_time(sum(trip, day3));
    // cin.get();

    return 0;
}

travel_time sum(travel_time t1, travel_time t2)
{
    travel_time total;

    total.mins = (t1.mins + t2.mins) % Mins_per_hr;
    total.hours = t1.hours + t2.hours +
                  (t1.mins + t2.mins) / Mins_per_hr;
    return total;
}

void show_time(travel_time t)
{
    using namespace std;
    cout << t.hours << " hours, "
         << t.mins << " minutes\n";
}
