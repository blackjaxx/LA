//函数和c风格字符串
//字符串做参数传递函数
//1.char数组
//2.引号阔起的字符串常量
//3.设置为字符串地址的char指针

// strgfun.cpp -- functions with a string argument
#include <iostream>
unsigned int c_in_str(const char *str, char ch);  //不需要处理负数且不修改原始字符串
int main()
{
    using namespace std;
    char mmm[15] = "minimum"; // string in an array
                              // some systems require preceding char with static to
                              // enable array initialization
    //c风格字符串与常规char数组之间的重要区别是字符串有内置的结束字符
    char *wail = "ululate"; // wail points to string

    unsigned int ms = c_in_str(mmm, 'm');
    unsigned int us = c_in_str(wail, 'u');
    cout << ms << " m characters in " << mmm << endl;
    cout << us << " u characters in " << wail << endl;
    // cin.get();
    return 0;
}

// this function counts the number of ch characters
// in the string str
unsigned int c_in_str(const char *str, char ch)
{
    unsigned int count = 0;

    while (*str) // quit when *str is '\0'
    {
        if (*str == ch)
            count++;
        str++; // move pointer to next char
    }
    return count;
}
