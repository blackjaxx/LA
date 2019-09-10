/*在14章中，您将学习：

• 预处理器简介；
• 关键字 #define 与宏；
• 模板简介；
• 如何编写函数模板和模板类；
• 宏和模板之间的区别；
• 如何使用 C++ 11 引入的 static_assert 执行编译阶段检查。

*/

/*
定义将被替换为 25 的常量 ARRAY_LENGTH

#define ARRAY_LENGTH 25
这样，每当预处理器遇到标识符 ARRAY_LENGTH 时，都会将其替换为 25。

int numbers [ARRAY_LENGTH] = {0}; 
double radiuses [ARRAY_LENGTH] = {0.0}; 
std::string names [ARRAY_LENGTH]; 
对于上述三行代码，预处理器运行完毕后，编译器看到的代码如下：

int numbers [25] = {0}; // an array of 25 integers 
double radiuses [25] = {0.0}; // an array of 25 doubles 
std::string names [25]; // an array of 25 std::strings 

替换将在所有代码中进行，包括下面这样的 for 循环：
for(int index = 0; index < ARRAY_LENGTH; ++index) 
 numbers[index] = index; 

编译器看到的上述循环如下：
for(int index = 0; index < 25; ++index) 
 numbers[index] = index;
*/

//声明并使用定义常量的宏

#include <iostream> 
#include<string> 
using namespace std; 

#define ARRAY_LENGTH 25 
#define PI 3.1416 
#define MY_DOUBLE double 
#define FAV_WHISKY "Jack Daniels"
//定义了 4 个宏常量：ARRAY_LENGTH、PI、MY_DOUBLE 和 FAV_WHISKYf
//对于使用宏定义的常量 PI，您没有太大的控制权：其类型是 double 还是 float？答案是都不是。 在预处理器看来，PI 就是 3.1416，根本不知道其数据类型

    int
    main()
{ 
    int numbers [ARRAY_LENGTH] = {0}; 
    cout << "Array’s length: " << sizeof(numbers) / sizeof(int) << endl; 

    cout << "Enter a radius: "; 
    MY_DOUBLE radius = 0; 
    cin >> radius; 
    cout << "Area is: " << PI * radius * radius << endl; 

    string favoriteWhisky (FAV_WHISKY); 
    cout << "My favorite drink is: " << FAV_WHISKY << endl;

    return 0;   
}
//定义常量时，更好的选择是使用关键字 const 和数据类型
/*
    const int ARRAY_LENGTH = 25; 
    const double PI = 3.1416; 
    const char* FAV_WHISKY = "Jack Daniels"; 
    typedef double MY_DOUBLE; // typedef aliases a type

*/