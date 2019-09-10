//using prototypes and function calls
#include <iostream>
using namespace std;

void cheers(int);  //prototype :no return value
double cube(double x);  //prototype :returns a double

int main()
{
    cheers(5);
    cout << "Give me a number:";
    double side;
    cin >> side;
    double volume = cube(side);  //function call
    cout << "A " <<side << "-foot cube has a volume of ";
    cout << volume << "cubic feet.\n";
    cheers(cube(2));  //prototype protection at work
    //这里面需要注意，cube接受double类型，传递为int类型会被强制转换，而cheers同理，会把double转换为int
    return 0;
}

void cheers(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "cheers!";
    }
    cout << endl;
}

double cube(double x)
{
    return x * x * x;
}

//函数原型描述了函数到编译器的接口，即它将函数的返回值类型和参数类型和数量告诉了编译器
//c++编程的风格通常将main()放在最前面，因为它通常提供了程序的整体结构
//函数原型不要求提供变量名，有类型列表就可以了

//c++原型和ANSI原型
//ANSI中原型是可选的，但是c++中原型是不可缺少的
//ANSI C中，括号为空意味着不指出参数，将在后边定义
//而c++中括号为空和在括号中使用void是等效的-意味函数没有参数

//关于自动转换的问题
//编译过程中进行的原型转化被称为自动类型检查
