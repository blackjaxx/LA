// --flawed string class definition

#include <iostream>
#ifndef STRNGBAD_H_
#define STRNGBAD_H_
class StringBad
{
private:
    char *str; //使用指针（而不是数组）来表示姓名，意味着类声明没有为字符串本身分配存储空间
    int len;
    static int num_strings; //静态类成员的特点是无论创建多少对象，程序都只创建一个静态类变量副本，类的所有对象共享一个静态成员

public:
    StringBad(const char *s); //ctor
    StringBad();
    ~StringBad();
    //friend function
    friend std::ostream &oeprator << (std::ostream & os, const StringBad &st); ///？？？？？？？？？？？？？？？？？？？？？？？？
};
#endif