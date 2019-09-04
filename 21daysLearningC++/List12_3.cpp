//解除引用运算符（*）和成员选择运算符（->）在智能指针类编程中应用最广。智能指针是封装常
//规指针的类，旨在通过管理所有权和复制问题简化内存管理。在有些情况下，智能指针甚至能够提高应用程序的性能


//使用智能指针 std:: unique_prt 管理动态分配的 Date 对象

#include <iostream> 
#include <memory> // new include to use unique_ptr 
using namespace std; 

class Date 
{ 
    private: 
        int day, month, year; 
        string dateInString; 

    public: 
        Date(int inMonth, int inDay, int inYear) : month(inMonth), day(inDay), year(inYear) {}; 

        void DisplayDate() 
        { 
            cout << month << " / " << day << " / " << year << endl; 
        } 
}; 

int main() 
{ 
    unique_ptr<int> smartIntPtr(new int);
    //声明了一个指向 int 的智能指针，它演示了智能指针类 unique_ptr 的模板初始化语法
    *smartIntPtr = 42;
    //行使用了*smartIntPtr 来显示指向的 int 值

    // Use smart pointer type like an int*
    cout<< "Integer value is: " << *smartIntPtr << endl;

    unique_ptr<Date> smartHoliday (new Date(12, 25, 2016));
    //声明了一个指向 Date 对象的智能指针。这里的重点是模式，请暂时不要考虑细节
    cout << "The new instance of date contains: "; 
    
    // use smartHoliday just as you would a Date* 
    smartHoliday->DisplayDate();
    //使用了 smartHoliday->DisplayData()，就像这两个变量的类型分别是 int *和 Date *

        return 0;
}
//其中的秘诀在于，智能指针类 std::unique_ptr 实现了运算符*和->