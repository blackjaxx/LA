//要拼接字符串，可使用运算符+=，也可使用成员函数 append()
/*

    string sampleStr1 ("Hello"); 
    string sampleStr2 (" String! "); 
    sampleStr1 += sampleStr2; // use std::string::operator+= 
// alternatively use std::string::append() 
    sampleStr1.append (sampleStr2); // (overloaded for char* too
*/

//使用加法赋值运算符（+=）或 append( )拼接字符串
#include <string>
#include<iostream>
using namespace std;

int main()
{
    string sampleStr1("Hello");
    string sampleStr2(" String!");

    // Concatenate
    sampleStr1 += sampleStr2;
    cout << sampleStr1 << endl<< endl;

    string sampleStr3(" Fun is not needing to use pointers!");
    sampleStr1.append(sampleStr3);
    cout << sampleStr1 << endl<< endl;

    const char* constCStyleString = " You however still can!";
    sampleStr1.append(constCStyleString);
    cout << sampleStr1 << endl;

    return 0;
}
//append 函数有多个重载版本，能够接受另一个 string 对象（如第 15 行所示），还能接受一个 C风格字符串