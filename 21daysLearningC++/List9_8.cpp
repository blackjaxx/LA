//复制构造函数
//浅复制及其存在的问题

/*
    程序清单 9.7 所示的 MyString 类包含一个指针成员 buffer，它指向动态分配的内存（这些内存是
在构造函数中使用 new 分配的，并在析构函数中使用 delete[]进行释放）。复制这个类的对象时，将复
制其指针成员，但不复制指针指向的缓冲区，其结果是两个对象指向同一块动态分配的内存。销毁其
中一个对象时，delete[]释放这个内存块，导致另一个对象存储的指针拷贝无效。这种复制被称为浅复
制，会威胁程序的稳定性，如程序清单 9.8 所示;

*/

//按值传递类（如 MyString）的对象带来的问题

#include <iostream>
#include <string.h>
using namespace std;

class MyString
{
  private:
    char *buffer;

  public:
    MyString(const char *initString) // Constructor
    {
        buffer = NULL;
        if (initString != NULL)
        {
            buffer = new char[strlen(initString) + 1];
            strcpy(buffer, initString);
        }
    }

    ~MyString() // Destructor
    {
        cout << "Invoking destructor, clearing up" << endl;
        delete[] buffer;
    }

    int GetLength()
    {
        return strlen(buffer);
    }

    const char *GetString()
    {
        return buffer;
    }
};

void UseMyString(MyString str)
{
    cout << "String buffer in MyString is " << str.GetLength();
    cout << " characters long" << endl;

    cout << "buffer contains: " << str.GetString() << endl;
    return;
}

int main()
{
    MyString sayHello("Hello from String Class");
    //在 main( )中，将使用 MyString 对象 sayHello 的工作交给了函数UseMyString()
    UseMyString(sayHello);
    //在 main( )中将工作交给这个函数的结果是，对象 sayHello 被复制到形参 str，并在 UseMyString() 中使用它
    //编译器之所以进行复制，是因为函数 UseMyString( )的参数 str被声明为按值（而不是按引用）传递
    //对于整型、字符和原始指针等 POD 数据，编译器执行二进制复制，
    //因此 sayHello.buffer 包含的指针值被复制到 str 中，即 sayHello.buffer 和 str.buffer 指向同一个内存单元
    return 0;
}
/*
    二进制复制不复制指向的内存单元，这导致两个 MyString 对象指向同一个内存单元。函数
UseMyString( )返回时，变量 str 不再在作用域内，因此被销毁。为此，将调用 MyString 类的析构函数，
而该析构函数使用 delete[]释放分配给 buffer 的内存（如程序清单 9.8 的第 22 行所示）。这将导致 main( )
中的对象 sayHello 指向的内存无效，而等 main( )执行完毕时，sayHello 将不再在作用域内，进而被销
毁。但这次第 22 行对不再有效的内存地址调用 delete（销毁 str 时释放了该内存，导致它无效）。正是
这种重复调用 delete 导致了程序崩溃;


*/