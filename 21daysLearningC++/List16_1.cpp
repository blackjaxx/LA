/*最常用的字符串函数包括：
        • 复制；
        • 连接；
        • 查找字符和子字符串；
        • 截短；
        • 使用标准模板库提供的算法实现字符串反转和大小写转换。
        要使用 STL string 类，必须包含头文件<string>。*/

//string 类提供了很多重载的构造函数，因此可以多种方式进行实例化和初始化
/*
    const char* constCStyleString = "Hello String!"; 
    std::string strFromConst (constCStyleString); 
    或：
    std::string strFromConst = constCStyleString; 
    上述代码与下面的代码类似：
    std::string str2 ("Hello String!"); 
    显然，实例化并初始化 string 对象时，无需关心字符串长度和内存分配细节。STL string 类的构造
    函数将自动完成这些工作。
    同样，可使用一个 string 对象来初始化另一个：
    std::string str2Copy (str2); 
    可让 string 的构造函数只接受输入字符串的前 n 个字符：
    // Initialize a string to the first 5 characters of another 
    std::string strPartialCopy (constCStyleString, 5); 
    还可这样初始化 string 对象，即使其包含指定数量的特定字符：
    // Initialize a string object to contain 10 'a's 
    std::string strRepeatChars (10, 'a');

*/
//实例化和复制 STL string 的方法

#include <string>
#include<iostream>
using namespace std;

int main()
{
    const char *constCStyleString = "Hello String!";
    cout << "Constant string is: " << constCStyleString << endl;
    //constCStyleString 是一个包含示例值的 C 风格字符串，它是第 37 行初始化的

    std::string strFromConst(constCStyleString); // constructor
    cout << "strFromConst is: " << strFromConst << endl;

    std::string str2("Hello String!");
    //使用 std::string 的构造函数进行复制非常简单
    std::string str2Copy(str2);
    cout << "str2Copy is: " << str2Copy << endl;

    // Initialize a string to the first 5 characters of another
    std::string strPartialCopy(constCStyleString, 5);
    cout << "strPartialCopy is: " << strPartialCopy << endl;

    // Initialize a string object to contain 10 'a's
    std::string strRepeatChars(10, 'a');
    cout << "strRepeatChars is: " << strRepeatChars << endl;

    return 0;
}