//要对字符串进行大小写转换，可使用算法 std::transform() ，它对集合中的每个元素执行一个用户指定的函数

//使用 std::transform()将 STL string 转换为大写

#include <string> 
#include <iostream> 
#include <algorithm> 
 
int main () 
{ 
    using namespace std; 

    cout << "Please enter a string for case-convertion:" << endl; 
    cout << "> "; 

    string inStr; 
    getline (cin, inStr); 
    cout << endl; 

    transform(inStr.begin(), inStr.end(), inStr.begin(), ::toupper); 
    //大写
    cout << "The string converted to upper case is: " << endl; 
    cout << inStr << endl << endl; 

    transform(inStr.begin(), inStr.end(), inStr.begin(), ::tolower); 
    //小写
    cout << "The string converted to lower case is: " << endl; 
    cout << inStr << endl << endl; 

    return 0;
}