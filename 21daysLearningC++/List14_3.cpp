//模板让程序员能够定义一种适用于不同类型对象的行为
//但宏不是类型安全的，而模板是类型安全的

//模板声明以关键字 template 打头，接下来是类型参数列表。这种声明的格式如下：
    //template <parameter list>
    //template function / class declaration..

//关键字 template 标志着模板声明的开始，接下来是模板参数列表。该参数列表包含关键字 typename，
//它定义了模板参数 objType，objType 是一个占位符，针对对象实例化模板时，将使用对象的类型替换它
/*
    template <typename T1, typename T2 = T1>
    bool TemplateFunction(const T1 &param1, const T2 &param2);

        // A template class
    template <typename T1, typename T2 = T1>
    class MyTemplate 
    { 
        private: 
            T1 member1; 
            T2 member2; 
        public: 
            T1 GetObj1() {return member1; } 
            // ... other members 
    };
*/

/*

    模板声明可以是：
• 函数的声明或定义；
• 类的定义或声明；
• 类模板的成员函数或成员类的声明或定义；
• 类模板的静态数据成员的定义；
• 嵌套在类模板中的类的静态数据成员的定义；
• 类或类模板的成员模板的定义

*/

/*
    template <typename objType> 
    const objType& GetMax(const objType& value1, const objType& value2) 
    { 
        if (value1 > value2) 
            return value1; 
        else 
            return value2; 
    }

    下面是一个使用该模板的示例
    int num1 = 25; 
    int num2 = 40; 
    int maxVal = GetMax <int> (num1, num2); 
    double double1 = 1.1; 
    double double2 = 1.001; 
    double maxVal = GetMax <double>(double1, double2);

    const int& GetMax(const int& value1, const int& value2) 
{ 
 //... 
} 
const double& GetMax(const double& value1, const double& value2) 
{ 
 // ... 
} 
    然而，实际上调用模板函数时并非一定要指定类型，因此下面的函数调用没有任何问题：
    int maxVal = GetMax(num1, num2); 
    在这种情况下，编译器很聪明，知道这是针对整型调用模板函数
*/

//模板函数 GetMax，它返回两个参数中较大的一个

#include<iostream> 
#include<string> 
using namespace std; 

template <typename Type> 
//声明
const Type& GetMax(const Type& value1, const Type& value2) 
{ 
    if (value1 > value2) 
        return value1; 
    else 
        return value2; 
} 
 
template <typename Type>
//模板声明
void DisplayComparison(const Type& value1, const Type& value2) 
{ 
    cout << "GetMax(" << value1 << ", " << value2 << ") = "; 
    cout << GetMax(value1, value2) << endl; 
    } 
 
int main() 
{ 
    int num1 = -101, num2 = 2011; 
    DisplayComparison(num1, num2); 

    double d1 = 3.14, d2 = 3.1416; 
    DisplayComparison(d1, d2); 

    string name1("Jack"), name2("John"); 
    DisplayComparison(name1, name2); 

    return 0; 
}
//模板函数 DisplayComparison( )和 GetMax( )是类型安全的，这意味着不能像下面这样进行无意义的调用：
//DisplayComparison(num1, name1);
//这种调用将导致编译错误