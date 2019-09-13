// vegnews.cpp -- using new and delete with classes
// compile with strngbad.cpp
#include <iostream>
using std::cout;
#include "strngbad.h"

void callme1(StringBad &); // pass by reference
void callme2(StringBad);   // pass by value

int main()
{
    using std::endl;
    {
        cout << "Starting an inner block.\n";
        StringBad headline1("Celery Stalks at Midnight");
        StringBad headline2("Lettuce Prey");
        StringBad sports("Spinach Leaves Bowl for Dollars");
        cout << "headline1: " << headline1 << endl;
        cout << "headline2: " << headline2 << endl;
        cout << "sports: " << sports << endl;
        callme1(headline1);
        cout << "headline1: " << headline1 << endl;
        callme2(headline2);
        cout << "headline2: " << headline2 << endl;
        cout << "Initialize one object to another:\n";
        StringBad sailor = sports;
        //StringBad sailor = StringBad(sports);
        //sports类型为StringBad ,StringBad(const StringBad &)
        //使用一个对象初始化另一个对象时，编译器将生成上述复制构造函数
        cout << "sailor: " << sailor << endl;
        cout << "Assign one object to another:\n";
        StringBad knot;
        knot = headline1;
        cout << "knot: " << knot << endl;
        cout << "Exiting the block.\n";
    }
    cout << "End of main()\n";
    // std::cin.get();
    return 0;
}

void callme1(StringBad &rsb)
{
    cout << "String passed by reference:\n";
    cout << "    \"" << rsb << "\"\n";
}

void callme2(StringBad sb)
{
    cout << "String passed by value:\n";
    cout << "    \"" << sb << "\"\n";
}

/*

c++自动提供了下列成员函数

默认构造函数
默认析构函数
复制构造函数
赋值运算符
地址运算符

如果没有定义的话，自动提供以上5个

在c++11中，默认还提供了移动构造函数和移动赋值运算符


*/

/*
默认构造函数

klunk::klunk(){ } //implicit default constructor
编译器提供一个不接受任何参数，也不执行任何操作的构造函数，因为创建对象时一定会调用构造函数
klunk lunk;
默认构造函数使lunk类似于常规自动变量，它的值在初始化之前是未知的
如果希望在创建对象时不显式初始化，则需要显式定义构造函数，构造函数通常没有任何参数，通常设置特定的值
klunk::klunk()
{
    klunk_ct = 0;
    ...
}
注意一点，带参数的构造函数也可以时默认构造函数，只要所有参数都有默认值
但只能有一个构造函数，否则会引起歧义

*/

/*
复制构造函数

复制构造函数用于将一个对象赋值到新创建的对象中，用于初始化过程中
class_name(const Class_name &)
接受一个指向类对象常量引用作为参数
关于复制构造函数只需知道两点：
1.何时调用
2.有何功能
新建对象并初始化为同类现有对象时候（显示初始化）
程序生成对象副本时，编译器使用复制构造函数
函数按值传递对象或返回对象时，都将使用复制构造函数，编译器生成临时对象时
还有一种情况，默认的复制构造函数逐个复制非静态成员（浅复制），复制的是成员的值
*/

/*
如果使用类中包含了使用new初始化的指针成员，应当定义一个复制构造函数，以复制指向的数据，而不是指针，这类被称为深度复制，复制的另一种形式（成员复制或浅复制）
只是复制指针值，浅复制仅复制指针信息，不会复制指针所引用的结构
*/