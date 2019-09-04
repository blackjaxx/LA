//使用 string::erase 从指定偏移位置或迭代器指定的位置开始截短字符串
#include <string> 
#include <algorithm> 
#include <iostream> 

int main () 
{ 
    using namespace std; 

    string sampleStr ("Hello String! Wake up to a beautiful day!"); 
    cout << "The original sample string is: " << endl; 
    cout << sampleStr << endl << endl; 

    // Delete characters given position and count 
    cout << "Truncating the second sentence: " << endl; 
    sampleStr.erase (13, 28);
    //本在给定偏移位置和字符数的情况下删除指定数目的字符
    cout << sampleStr << endl << endl; 

    // Find character 'S' using find() algorithm 
    string::iterator iCharS = find (sampleStr.begin (), 
    sampleStr.end (), 'S'); 

    // If character found, 'erase' to deletes a character 
    cout << "Erasing character 'S' from the sample string:" << endl; 
    if (iCharS != sampleStr.end ()) 
        sampleStr.erase (iCharS); 

    cout << sampleStr << endl << endl; 

    // Erase a range of characters using an overloaded version of erase() 
    cout << "Erasing a range between begin() and end(): " << endl; 
    sampleStr.erase (sampleStr.begin (), sampleStr.end ());
    //范围是由 string 的成员函数 begin()和 end ()指定的，它包含字符串的所有内容，因此
    //对该范围调用 erase() 将清除 string 对象的全部内容。注意，string 类还提供了 clear() 函数，该函数清除
    //全部内容并重置 string 对象

        // Verify the length after the erase() operation above
        if (sampleStr.length() == 0)
            cout
        << "The string is empty" << endl;

    return 0; 
} 
