//构造函数(重点)
//构造函数是一种特殊的函数（方法），在根据类创建对象时被调用。与函数一样，构造函数也可以重载

//构造函数可在类声明中实现，也可在类声明外实现

/*
在类声明中实现（定义）构造函数的代码类似于下面这样：

class Human 
{ 
    public: 
        Human() 
        { 
            // constructor code here 
        } 
};


在类声明外定义构造函数的代码类似于下面这样：
class Human 
{ 
    public: 
        Human(); // constructor declaration
};

// constructor implementation (definition) 
Human::Human()
{ 
 // constructor code here 
}

*/

//::被称为作用域解析运算符。例如，Human::dateOfBirth 指的是在 Human 类中声明的变
//量 dateOfBirth，而::dateOfBirth 表示全局作用域中的变量 dateOfBirth;

//使用构造函数初始化类成员变量

#include <iostream>
#include <string>
using namespace std;

class Human
{
  private:
    string name;
    int age;

  public:
    Human() // constructor
    {
        age = 1; // initialization
        cout << "Constructed an instance of class Human" << endl;
    }

    void SetName(string humansName)
    {
        name = humansName;
    }

    void SetAge(int humansAge)
    {
        age = humansAge;
    }

    void IntroduceSelf()
    {
        cout << "I am " + name << " and am ";
        cout << age << " years old" << endl;
    }
};

int main()
{
    Human firstWoman;
    firstWoman.SetName("Eve");
    firstWoman.SetAge(28);

    firstWoman.IntroduceSelf();
}
//可在不提供参数的情况下调用的构造函数被称为默认构造函数。默认构造函数是可选的
//没有提供默认构造函数，编译器将为您创建一个，这种构造
//函数会创建成员属性，但不会将 POD 类型（如 int）的属性初始化为非零值