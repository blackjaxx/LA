//使用复制构造函数确保深复制

/*

    复制构造函数是一个重载的构造函数，由编写类的程序员提供。每当对象被复制时，编译器都将
调用复制构造函数。为 MyString 类声明复制构造函数的语法如下

class MyString 
{ 
    MyString(const MyString& copySource); // copy constructor 
};

MyString::MyString(const MyString& copySource) 
{ 
    // Copy constructor implementation code 
} 
复制构造函数接受一个以引用方式传入的当前类的对象作为参数。这个参数是源对象的别名，您
使用它来编写自定义的复制代码，确保对所有缓冲区进行深复制，如程序清单 9.9 所示

*/

//定义一个复制构造函数，确保对动态分配的缓冲区进行深复制

#include <iostream>
#include <string.h>
using namespace std;

class MyString
{
  private:
    char *buffer;

  public:
    MyString(const char *initString) // constructor
    {
        buffer = NULL;
        cout << "Default constructor: creating new MyString" << endl;
        if (initString != NULL)
        {
            buffer = new char[strlen(initString) + 1];
            strcpy(buffer, initString);

            cout << "buffer points to: 0x" << hex;
            cout << (unsigned int *)buffer << endl;
        }
    }

    MyString(const MyString &copySource) // Copy constructor
    {
        buffer = NULL;
        cout << "Copy constructor: copying from MyString" << endl;
        if (copySource.buffer != NULL)
        {
            // allocate own buffer
            buffer = new char[strlen(copySource.buffer) + 1];

            // deep copy from the source into local buffer
            strcpy(buffer, copySource.buffer);

            cout << "buffer points to: 0x" << hex;
            cout << (unsigned int *)buffer << endl;
        }
    }

    // Destructor
    ~MyString()
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
    UseMyString(sayHello);

    return 0;
}