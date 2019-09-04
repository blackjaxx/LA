//与构造函数一样，析构函数也是一种特殊的函数。构造函数在实例化对象时被调用，而析构函数在对象销毁时自动被调用

/*
析构函数看起来像一个与类同名的函数，但前面有一个腭化符号（～）。因此，Human 类的析构函
数的声明类似于下面这样

class Human 
{ 
    ~Human(); // declaration of a destructor 
};

这个析构函数可在类声明中实现，也可在类声明外实现。在类声明中实现（定义）析构函数的代
码类似于下面这样：
class Human 
{ 
public: 
    ~Human() 
    { 
        // destructor code here 
    } 
};

在类声明外定义析构函数的代码类似于下面这样：
class Human 
{ 
    public: 
        ~Human(); // destructor declaration 
}; 
        // destructor definition (implementation)
Human::~Human()
{ 
    // destructor code here
}
//正如您看到的，析构函数的声明与构造函数稍有不同，那就是包含腭化符号（～）。然而，析构函数的作用与构造函数完全相反


//何时及如何使用析构函数

/*
    每当对象不再在作用域内或通过 delete 被删除进而被销毁时，都将调用析构函数。这使得析构函
数成为重置变量以及释放动态分配的内存和其他资源的理想场所。
    使用 char*缓冲区时，您必须自己管理内存分配和释放，因此本书建议不要使用它们，而使用
std::string。std::string 等工具都是类，它们充分利用了构造函数和析构函数，还有将在第 12 章介绍的
运算符，让您无需考虑分配和释放等内存管理工作。程序清单 9.7 所示的类 MyString 在构造函数中为
一个字符串分配内存，并在析构函数中释放它。
*/

//一个简单的类，它封装了字符缓冲区并通过析构函数释放它

#include <iostream>
#include <string.h>
using namespace std;

class MyString
{
  private:
    char *buffer;

  public:
    MyString(const char *initString)
    //这个构造函数构造 MyString 对象
    //它通过输入参数获取一个输入字符串
    {
        if (initString != NULL)
        {
            buffer = new char[strlen(initString) + 1];
            //然后使用标准库函数 strlen 确定输入字符串的长度，并使用 new 为字符缓冲区 buffer 分配内存
            strcpy(buffer, initString);
            //再使用标准库函数 strcpy 将输入字符串 initString 复制到 buffer 指向的新分配的内存中
        }
        else
            buffer = NULL;
        //如果传递给参数 initString 的值为 NULL，MyString::buffer 也被初始化为 NULL
        //（以防该指针包含随机值，否则使用它来访问内存单元将非常危险）
    }

    ~MyString()
    //析构函数的代码确保构造函数分配的内存自动被归还给系统
    {
        cout << "Invoking destructor, clearing up" << endl;
        if (buffer != NULL)
            delete[] buffer;
    }
    //检查 MyString::buffer是否为 NULL，如果不是，则对其执行 delete[] ，这对应于构造函数中的 new

    int
    GetLength()
    {
        return strlen(buffer);
    }

    const char *GetString()
    {
        return buffer;
    }
};

int main()
{
    MyString sayHello("Hello from String Class");
    cout << "String buffer in sayHello is " << sayHello.GetLength();
    cout << " characters long" << endl;

    cout << "Buffer contains: " << sayHello.GetString() << endl;
    //注意到在 main( )中，程序员无需调用 new 和 delete。MyString 类不仅对程序员隐藏了内存管理实现，还正确地释放了分配的
    //内存。main() 执行完毕时，将自动调用析构函数～MyString() ，输出证明了这一点—其中包含析构函数中 cout 语句的输出;
}
/*
    析构函数不能重载，每个类都只能有一个析构函数。如果您忘记了实现析构函数，编译
器将创建一个伪（dummy）析构函数并调用它。伪析构函数为空，即不释放动态分配的内存

*/