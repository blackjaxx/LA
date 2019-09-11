// strgback.cpp -- a function that returns a pointer to char
#include <iostream>
char *buildstr(char c, int n); // prototype
int main()
{
    using namespace std;
    int times;
    char ch;

    cout << "Enter a character: ";
    cin >> ch;
    cout << "Enter an integer: ";
    cin >> times;
    char *ps = buildstr(ch, times);
    cout << ps << endl;
    delete[] ps;            // free memory
    ps = buildstr('+', 20); // reuse pointer
    cout << ps << "-DONE-" << ps << endl;
    delete[] ps; // free memory
    // cin.get();
    // cin.get();
    return 0;
}

// builds string made of n c characters
char *buildstr(char c, int n)
{
    char *pstr = new char[n + 1];//创建包含n个字符的字符串，需要能存储n+1个字符的空间，以便能存储空值字符
    pstr[n] = '\0'; // terminate string
    while (n-- > 0)  //从后向前进行填充
        pstr[n] = c; // fill rest of string
    return pstr;  //函数返回一个指针
}


//返回c风格字符串的函数
//函数无法返回字符串，但是可以返回字符串的地址