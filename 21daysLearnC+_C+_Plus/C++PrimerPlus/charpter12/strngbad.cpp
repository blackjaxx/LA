// strngbad.cpp -- StringBad class methods
#include <cstring> // string.h for some
#include "strngbad.h"
using std::cout;

// initializing static class member
int StringBad::num_strings = 0; //不能在类声明中初始化静态成员变量
//但是有一种例外情况，当静态数据成员为整形或枚举型const时，可以在声明中初始化

// class methods

// construct StringBad from C string
StringBad::StringBad(const char *s) //初始化string对象
{
    len = std::strlen(s);    // set size
    str = new char[len + 1]; // allot storage  类成员str是指针，构造函数必须提供内存存储字符串
    std::strcpy(str, s);     // initialize pointer
    num_strings++;           // set object count
    cout << num_strings << ": \"" << str
         << "\" object created\n"; // For Your Information
}

StringBad::StringBad() // default constructor
{
    len = 4;
    str = new char[4];
    std::strcpy(str, "C++"); // default string 字符串保存在堆内存中，对象仅保存指针到哪里去查找字符串的信息
    num_strings++;
    cout << num_strings << ": \"" << str
         << "\" default object created\n"; // FYI
}

StringBad::~StringBad() // necessary destructor
{
    cout << "\"" << str << "\" object deleted, "; // FYI
    --num_strings;                                // required 析构函数中--
    cout << num_strings << " left\n";             // FYI
    delete[] str;                                 // required 删除对象可以释放对象本身占用内存，但不能自动释放属于对象成员指针指向的内存
}

std::ostream &operator<<(std::ostream &os, const StringBad &st)
{
    os << st.str;
    return os;
}
