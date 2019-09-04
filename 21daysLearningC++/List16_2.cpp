//两种访问 STL string 字符元素的方式：运算符[]和迭代器
#include <string>
#include<iostream>
using namespace std;

int main()
{
    string stlString("Hello String");

    cout << "Display elements in string using array-syntax: " << endl;
   
    for (size_t charCounter = 0;charCounter < stlString.length();++charCounter)
    {
        cout << "Character [" << charCounter << "] is: ";
        cout << stlString[charCounter] << endl;
    }
    cout << endl;
    //使用 std::string 类实现的下标运算符（[]）以类似数组的语法显示 string中的字符

    cout << "Display elements in string using iterators: " << endl;
    int charOffset = 0;
    //为显示的时候做元素用
    //Character [0] is: H
    //Character[1] is : e
    //Character[2] is : l
    string::const_iterator charLocator;
    for (auto charLocator = stlString.cbegin();charLocator != stlString.cend();++charLocator)
        //要避免第 22 行中繁琐的迭代器声明，可使用关键字 auto 让编译器根据 std::string::cbegin()的返回值推断 charLocator 的类型
        {
            cout << "Character [" << charOffset++ << "] is: ";
            cout << *charLocator << endl;
    }
    cout << endl;

    cout << "The char* representation of the string is: ";
    cout << stlString.c_str() << endl;
    //c_str()是什么注意一下

    return 0;
}
//迭代器很重要，因为很多 string 成员函数都以迭代器的方式返回其结果
//确保不超出 string 的边界很重要，即读取字符时，提供的偏移量不能大于 string 的长度