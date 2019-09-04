/*
        C++程序员通常在.H 文件（头文件）中声明类和函数，并在.CPP 文件中定义函数，因此需要在.CPP
    文件中使用预处理器编译指令#include <header>来包含头文件。如果在头文件 class1.h 中声明了一个类，
    而这个类将 class2.h 中声明的类作为其成员，则需要在 class1.h 中包含 class2.h。如果设计非常复杂，
    即第二个类需要第一个类，则在 class2.h 中也需要包含 class1.h！
        然而，在预处理器看来，两个头文件彼此包含对方会导致递归问题。为了避免这种问题，可结合
    使用宏以及预处理器编译指令 #ifndef 和 #endif。

    包含<header2.h>的 head1.h 类似于下面这样：
    #ifndef HEADER1_H _//multiple inclusion guard:
    #define HEADER1_H_ // preprocessor will read this and following lines once 
    #include <header2.h>

        class Class1 
    { 
    // class members 
    }; 
    #endif // end of header1.h

    header2.h 与此类似，但宏定义不同，且包含的是<header1.h>

    #ifndef HEADER2_H_//multiple inclusion guard 
    #define HEADER2_H_ 
    #include <header1.h> 

    class Class2 
    { 
        // class members 
    }; 
    #endif // end of header2.h

    #ifndef 可读作 if-not-defined。这是一个条件处理命令，让预处理器仅在标识符未定义时
    才继续。
    #endif 告诉预处理器，条件处理指令到此结束

        预处理器首次处理 header1.h 并遇到#ifndef 后，发现宏 HEADER1_H_还未定义，因此继续
    处理。#ifndef 后面的第一行定义了宏 HEADER1_H_，确保预处理器再次处理该文件时，将在遇到包含
    #ifndef 的第一行时结束，因为其中的条件为 false。header2.h 与此类似。在 C++编程领域，这种简单的
    机制无疑是最常用的宏功能之一。
*/

//使用计算平方值、圆面积、最小值和最大值的宏函数

#include <iostream> 
#include<string> 
using namespace std; 

#define SQUARE(x) ((x) * (x)) 
#define PI 3.1416 
#define AREA_CIRCLE(r) (PI*(r)*(r)) 
#define MAX(a, b) (((a) > (b)) ? (a) : (b)) 
#define MIN(a, b) (((a) < (b)) ? (a) : (b)) 

int main() 
{ 
    cout << "Enter an integer: "; 
    int num = 0; 
    cin >> num; 

    cout << "SQUARE(" << num << ") = " << SQUARE(num) << endl; 
    cout << "Area of a circle with radius " << num << " is: "; 
    cout << AREA_CIRCLE(num) << endl; 

    cout << "Enter another integer: "; 
    int num2 = 0; 
    cin >> num2; 

    cout << "MIN(" << num << ", " << num2 << ") = "; 
    cout << MIN (num, num2) << endl; 

    cout << "MAX(" << num << ", " << num2 << ") = "; 
    cout << MAX (num, num2) << endl; 

    return 0; 
}
//一个宏可使用另一个宏
//为什么要使用括号
//原因在于宏的计算方式—预处理器支持的文本替换机制
//通过使用括号，让宏代码不受运算符优先级的影响，从而能够正确地计算面积

//编写程序后，立即单步执行以测试每条代码路径很不错，但对大型应用程序来说可能不现实。比
//较现实的做法是，插入检查语句，对表达式或变量的值进行验证
//assert 宏让您能够完成这项任务。要使用 assert 宏，需要包含 <assert.h>
/*
        
    #include <assert.h> 
    int main() 
    { 
        char* sayHello = new char [25]; 
        assert(sayHello != NULL); // throws a message if pointer is NULL 
        // other code 
        delete [] sayHello; 
        return 0; 
    }   
    
 */

/*
    注意！！！！！
    尽可能不要自己编写宏函数。
    尽可能使用 const 变量，而不是宏常量
    请牢记，宏并非类型安全的，预处理器不执行类型检查
    在宏函数的定义中，别忘了使用括号将每个变量括起。
    为了在头文件中避免多次包含，别忘了使用#ifndef、#define 和#endif。
    别忘了在代码中大量使用 assert( )，它们在发行版本中将被禁用，但对提高代码的质量很有帮助。
    
*/