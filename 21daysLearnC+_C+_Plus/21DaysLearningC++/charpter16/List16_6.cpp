//有时需要反转字符串的内容。假设要判断用户输入的字符串是否为回文，方法之一是将其反转，
//再与原来的字符串进行比较。反转 STL string 很容易，只需使用泛型算法 std::reverse()
//string sampleStr ("Hello String! We will reverse you!");
//reverse(sampleStr.begin(), sampleStr.end());

//使用 std::reverse 反转 STL string

#include <string> 
#include <iostream> 
#include <algorithm> 

int main () 
{ 
    using namespace std; 

    string sampleStr ("Hello String! We will reverse you!"); 
    cout << "The original sample string is: " << endl; 
    cout << sampleStr << endl << endl; 

    reverse (sampleStr.begin (), sampleStr.end ()); 

    cout << "After applying the std::reverse algorithm: " << endl; 
    cout << sampleStr << endl; 

    return 0; 
}
//std::reverse()算法根据两个输入参数指定的边界反转边界内的内容。在这里，两个边界
//分别是 string 对象的开头和末尾，因此整个字符串都被反转。只要提供合适的输入参数，也可将字符串的一部分反转。注意，边界不能超过end()