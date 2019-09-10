//包含初始化列表的构造函数
/*
    构造函数对初始化成员变化很有用。另一种初始化成员的方式是使用初始化列表。对于
程序清单 9.5 中接受两个参数的构造函数，其包含初始化列表的变种类似于下面这样:

class Human 
{ 
    private: 
        string name; 
        int age;
    public: 
        // two parameters to initialize members age and name 
        Human(string humansName, int humansAge) :name(humansName), age(humansAge) 
        { 
            cout << "Constructed a human called " << name; 
            cout << ", " << age << " years old" << endl; 
        } 
            // ... other class members 
};

    初始化列表由包含在括号中的参数声明后面的冒号标识，冒号后面列出了各个成员变量及其初始
值。初始值可以是参数（如 humansName），也可以是固定的值。使用特定参数调用基类的构造函数时，
初始化列表也很有用

*/

//接受带默认值的参数的默认构造函数，并使用初始化列表来设置成员

#include <iostream>
#include <string>
using namespace std;

class Human
{
  private:
    int age;
    string name;

  public:
    Human(string humansName = "Adam", int humansAge = 25) : name(humansName), age(humansAge)
    {
        cout << "Constructed a human called " << name;
        cout << ", " << age << " years old" << endl;
    }
};

int main()
{
    Human adam;
    Human eve("Eve", 18);

    return 0;
}

/*

    也可使用关键字 constexpr 将构造函数定义为常量表达式。在有助于提高性能的情况下，
可在构造函数的声明中使用这个关键字，如下所示：

class Sample 
{ 
const char* someString; 
public: 
    constexpr Sample(const char* input):someString(input) 
 { // constructor code } 
};

*/
