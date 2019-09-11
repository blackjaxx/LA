//arrobj.cpp -- functions with array objects
#include <iostream>
#include <array>
#include <string>
const int Seasons = 4; //符号常量
const std::array<std::string, Seasons> Snames =
    {"Spring", "Summer", "Fall", "Winter"};  //对象包含4个string对象

void fill(std::array<double, Seasons> *pa); //expenses类型为array<double,4> 函数原型中必须指定这种类型
void show(std::array<double, Seasons> da);
int main()
{
    std::array<double, 4> expenses;  //使用一个array对象存储一年四个季度开支
    fill(&expenses);  //如果要修改array对象，需要传入引用（对象地址）
    show(expenses);   //如果显示内容可以直接传值
    // std::cin.get();
    // std::cin.get();
    return 0;
}

void fill(std::array<double, Seasons> *pa)  
{
    for (int i = 0; i < Seasons; i++)
    {
        std::cout << "Enter " << Snames[i] << " expenses: ";
        std::cin >> (*pa)[i];
    }
}

void show(std::array<double, Seasons> da)
{
    double total = 0.0;
    std::cout << "\nEXPENSES\n";
    for (int i = 0; i < Seasons; i++)
    {
        std::cout << Snames[i] << ": $" << da[i] << '\n';
        total += da[i];
    }
    std::cout << "Total: $" << total << '\n';
}
