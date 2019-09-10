/*
    在程序清单 12.1 的 main( )中，如果添加下述代码行：

    cout << holiday; // error in absence of conversion operator 

将导致这样的编译错误：error: binary ‘<<’ : no operator found which takes a right-hand operand of type 
‘Date’ (or there is no acceptable conversion)。这种错误表明，cout 不知道如何解读 Date 实例，因为 Date
类不支持这样的运算符，即将 Date 对象的内容转换成 cout 能够接受的类型。
然而，cout 能够很好地显示 const char *：
    std::cout << "Hello world"; // const char* works! 
因此，要让 cout 能够显示 Date 对象，只需添加一个返回 const char*的运算符：

    operator const char*() 
    { 
        // operator implementation that returns a char* 
    } 
程序清单 12.2 提供了该转换运算符的简单实现

*/
//在 Date 类中实现转换运算符 const char*

#include <iostream> 
#include <sstream> // new include for ostringstream 
#include <string> 
using namespace std; 

class Date 
{ 
    private: 
        int day, month, year; 
        string dateInString; 

    public: 
        Date(int inMonth, int inDay, int inYear) : month(inMonth), day(inDay), year(inYear) {}; 

        operator const char*() 
            { 
                ostringstream formattedDate; // assists string construction
                //在转换为 const char*的运算符中，使用 std::ostringstream 将整型成员转换成了一个 std::string 对象
                formattedDate<< month << " / " << day << " / " << year;

                dateInString = formattedDate.str();
                //原本也可直接返回formattedDate.str(),但没有这样做,将其拷贝存储在私有成员Date::dateInString中
                //这是因为 formattedDate 是一个局部变量，将在运算符返回时被销毁，因此运算符返回时，通过 str( )
                //获得的指针将无效
                return dateInString.c_str();
            }
            //实现了将 Date 转换为 const char*的运算符
}; 

int main () 
{ 
    Date Holiday (12, 25, 2016); 

    cout << "Holiday is on: " << Holiday << endl;
    //可在 cout 语句中直接使用 Date 对象，因为 cout 能够理解 const char*
    //编译器自动将合适运算符(这里只有一个）的返回值提供给 cout，从而在屏幕上显示日期

        // string strHoliday (Holiday); // OK!
        // strHoliday = Date(11, 11, 2016); // also OK!

        return 0;
}

/*

//string strHoliday (holiday);
//strHoliday = Date(11, 11, 2016);

请注意，这样的赋值将导致隐式转换，即为了让赋值通过编译而不引发错误，编译器使
用了可用的转换运算符（这里为 const char*）。为了禁止隐式转换，可在运算符声明开头
使用关键字 explicit，如下所示：
    explicit operator const char*() 
    { 
        // conversion code here 
    }

应根据类的可能用法编写尽可能多的运算符。如果应用程序需要 Date 对象的整数表示，
可编写如下转换运算符：
    explicit operator int() 
    { 
         return day + month + year; 
    } 
    这样便可将 Date 对象当做整数使用：
    FuncTakesInt(static_cast<int>(Date(12, 25, 2016))); 
    本章后面的程序清单 12.8 还演示了用于字符串类的转换运算符。
    */
