//STL string 类提供了成员函数 find()，该函数有多个重载版本，可在给定 string 对象中查找字符或子字符串
/* 

// Find substring "day" in sampleStr, starting at position 0 
    size_t charPos = sampleStr.find ("day", 0); 
// Check if the substring was found, compare against string::npos 
    if (charPos != string::npos) 
        cout << "First instance of \"day\" was found at position " << charPos; 
    else 
        cout << "Substring not found." << endl; 

    */

//使用 string::find() 查找子字符串或字符
#include <string>
#include<iostream>
using namespace std;

int  main()
{
    string sampleStr("Good day String! Today is beautiful!");
    cout << "Sample string is:" << endl<< sampleStr<< endl<< endl;

    // Find substring "day" - find() returns position
    size_t charPos = sampleStr.find("day", 0);

    // Check if the substring was found...
    if (charPos != string::npos) 
        cout << "First instance \"day\" at pos. " << charPos << endl;
    else
        cout << "Substring not found." << endl;
    //演示了 find()函数的最简单用法，它判断在 string 中是否找到了特定子字符串。这是
    //通过将 find() 操作的结果与 std::string::npos（实际值为−1）进行比较实现的，std ::string::npos 表明没有找到要搜索的元素

    
    cout<< "Locating all instances of substring \"day\"" << endl;
    size_t subStrPos = sampleStr.find("day", 0);

    while (subStrPos != string::npos)
        {
            cout << "\"day\" found at position " << subStrPos << endl;

            // Make find() search forward from the next character onwards
            size_t searchOffset = subStrPos + 1;

            subStrPos = sampleStr.find("day", searchOffset);
        }
        return 0;
}