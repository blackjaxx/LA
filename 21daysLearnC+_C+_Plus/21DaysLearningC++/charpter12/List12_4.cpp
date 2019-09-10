//重载双目运算符

//实现了双目加法运算符的日历类

#include <iostream> 
using namespace std; 

class Date 
{ 
    private: 
        int day, month, year; 
        string dateInString; 

    public: 
        Date(int inMonth, int inDay, int inYear) : month(inMonth), day(inDay), year(inYear) {}; 

        Date operator + (int daysToAdd) // binary addition 
        { 
            Date newDate (month, day + daysToAdd, year); 
            return newDate; 
        } 

        Date operator - (int daysToSub) // binary subtraction 
        { 
            return Date(month, day - daysToSub, year); 
        }
        //双目运算符+和-的实现，让您能够使用简单的加法和减法语法

        void DisplayDate()
        {
            cout << month << " / " << day << " / " << year << endl; 
        } 
}; 

int main() 
{ 
    Date Holiday (12, 25, 2016); 
    cout << "Holiday on: "; 
    Holiday.DisplayDate (); 

    Date PreviousHoliday (Holiday - 19); 
    cout << "Previous holiday on: "; 
    PreviousHoliday.DisplayDate(); 

    Date NextHoliday(Holiday + 6); 
    cout << "Next holiday on: "; 
    NextHoliday.DisplayDate (); 

    return 0; 
}

/*

    对字符串类来说，双目加法运算符也很有用。第 9 章分析了简单的字符串包装类 MyString，它提
供了内存管理、复制等功能，如程序清单 9.9 所示。但这个 MyString 类不支持使用如下简单语法将两
个字符串拼接起来

    MyString Hello("Hello "); 
    MyString World(" World"); 
    MyString HelloWorld(Hello + World); // error: operator+ not defined

    实现：
    MyString operator+ (const MyString& addThis) 
    { 
        MyString newString;

        if (addThis.buffer != NULL) 
        { 
            newString.buffer = new char[GetLength() + strlen(addThis.buffer) + 1]; 
            strcpy(newString.buffer, buffer); 
            strcat(newString.buffer, addThis.buffer); 
        }
        
        return newString; 
    }