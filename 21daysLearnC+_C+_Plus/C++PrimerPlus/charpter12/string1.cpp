// string1.cpp -- String class methods
#include <cstring>   // string.h for some
#include "string1.h" // includes <iostream>
using std::cin;
using std::cout;

// initializing static class member

int String::num_strings = 0;

// static method
int String::HowMany()
{
    return num_strings;
}

// class methods
String::String(const char *s) // construct String from C string
{
    len = std::strlen(s);    // set size
    str = new char[len + 1]; // allot storage
    std::strcpy(str, s);     // initialize pointer
    num_strings++;           // set object count
}

String::String() // default constructor
{
    len = 4;
    str = new char[1];
    //str = new char;两种写法分配的内存相同，但是下面这种和析构函数不兼容，缺[]
    str[0] = '\0'; // default string
    num_strings++;
}

String::String(const String &st)
{
    num_strings++;            // handle static member update
    len = st.len;             // same length
    str = new char[len + 1];  // allot space
    std::strcpy(str, st.str); // copy string to new location
}

String::~String() // necessary destructor
{
    --num_strings; // required
    delete[] str;  // required
}

// overloaded operator methods

// assign a String to a String
String &String::operator=(const String &st)
{
    if (this == &st)
        return *this;
    delete[] str;
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    return *this;
}

// assign a C string to a String
String &String::operator=(const char *s)
{
    delete[] str;
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    return *this;
}

// read-write char access for non-const String
char &String::operator[](int i) //重载中括号
{
    return str[i];
}

// read-only char access for const String
const char &String::operator[](int i) const
{
    return str[i];
}

// overloaded operator friends

bool operator<(const String &st1, const String &st2)
{
    return (std::strcmp(st1.str, st2.str) < 0); //按照字母排序，如果str1字母排序位于str2之前，返回一个负值
}

bool operator>(const String &st1, const String &st2)
{
    return st2 < st1;
}

bool operator==(const String &st1, const String &st2)
{
    return (std::strcmp(st1.str, st2.str) == 0);
}

// simple String output
ostream &operator<<(ostream &os, const String &st)
{
    os << st.str;
    return os;
}

// quick and dirty String input
istream &operator>>(istream &is, String &st)
{
    char temp[String::CINLIM];    //CINLIM为已定义常量
    is.get(temp, String::CINLIM); //如果输入的字符串多余80，丢弃多余字符，由于某种原因导致输入失败时，istream对象值为false
    if (is)
        st = temp;
    while (is && is.get() != '\n')
        continue;
    return is;
}

/*
c++11空指针
引入新关键字nullptr，表示空指针

而在c++98中
字面值0有两个含义，可能表示数字0，也可以表示空指针
有些程序员使用void(*) 0表示空指针，还有一些人使用NULL，这是一个表示空指针的语言宏
*/

/*
静态方法：
可以将成员函数声明为静态的（声明时候必须包含关键字static，但如果函数是独立的，则其中不能包含static）
因为不能通过对象调用静态成员函数，静态成员函数甚至不能使用this指针，如果静态成员函数是在公有部分声明的，则可以使用类名和作用域解析运算符调用它
static int HowMany()
{
    return num_string;
}
int count = String::HowMany();
其次静态成员函数不与特定的对象相关联，因此只能使用静态成员！！！

*/