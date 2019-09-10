//运算符声明看起来与函数声明极其相似：
//return_type operator operator_symbol(... parameter list...);
//其中 operator_symbol 是程序员可定义的几种运算符类型之一。可以是+（加）、&&（逻辑 AND）等。编译器可根据操作数区分运算符
/*          
    显然，方法 1 优于方法 2。基于运算符的机制更容易使用，也更直观。通过在 Date 类中实现运算
符<，将可以像下面这样对两个 Date 实例进行比较
    if(date1 < date2) 
    { 
        // Do something 
    } 
    else 
    { 
        // Do something else 
    }

*/

/*
    单目运算符只对一个操作数进行操作。实现为全局函数或静态成员函数的单目运算符
的典型定义如下：
    return_type operator operator_type (parameter_type) 
    { 
    // ... implementation 
    }

    作为类成员（非静态函数）的单目运算符没有参数，因为它们使用的唯一参数是当前类实例（*this），
如下所示：
    return_type operator operator_type () 
    { 
     // ... implementation 
    }

    要在类声明中编写单目前缀递增运算符（++），可采用如下语法：
    // Unary increment operator (prefix) 
    Date& operator ++ () 
    { 
    // operator implementation code 
    return *this; 
    } 
    后缀递增运算符（++）的返回类型不同，且有一个输入参数（但并非总是使用它）：
    Date operator ++ (int) 
    { 
    // Store a copy of the current state of the object, before incrementing day 
    Date copy (*this); 
    // increment implementation code 
    // Return state before increment (because, postfix) 
    return copy; 
    } 
    前缀和后缀递减运算符的声明语法与递增运算符类似，只是将声明中的++替换成了--。程序清单 12.1
是一个简单的 Date 类，让您能够使用运算符++对日期进行递增。

*/

//处理日、月、年的日历类，可对日期执行递增和递减操作

#include <iostream>
using namespace std;

class Date
{
  private:
    int day, month, year;

  public:
    Date(int inMonth, int inDay, int inYear) : month(inMonth), day(inDay), year(inYear){};
    Date &operator++() // prefix increment
    {
        ++day;
        return *this;
    }

    Date &operator--() // prefix decrement
    {
        --day;
        return *this;
    }

    void DisplayDate()
    {
        cout << month << " / " << day << " / " << year << endl;
    }
};

int main()
{
    Date holiday(12, 25, 2016); // Dec 25, 2016

    cout << "The date object is initialized to: ";
    holiday.DisplayDate();

    ++holiday; // move date ahead by a day
    cout << "Date after prefix-increment is: ";
    holiday.DisplayDate();

    --holiday; // move date backwards by a day
    cout << "Date after a prefix-decrement is: ";
    holiday.DisplayDate();

    return 0;
}

/*
// 要支持后缀递增和递减运算符，只需在 Date 类中添加如下代码
// postfix differs from prefix operator in return-type and parameters
Date operator++(int) // postfix increment
{
    Date copy(month, day, year);
    ++day;
    return copy; // copy of instance before increment returned
}
Date operator--(int) // postfix decrement
{
    Date copy(month, day, year);
    --day;
    return copy; // copy of instance before decrement returned
}
//在上述后缀运算符的实现中，首先复制了当前对象，再将对当前对象执行递增或递减运算，最后返回复制的对象
//换句话说，如果只想执行递增运算，可使用++ object，也可使用 object ++，但应选择前者，这样避免创建一个未被使用的临时拷贝
*/