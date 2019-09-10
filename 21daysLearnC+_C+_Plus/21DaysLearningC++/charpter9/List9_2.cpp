/*

class Human 
{ 
private: 
 // Private member data: 
 int age; 
 string name; 
public: 
 int GetAge() 
 { 
 return age; 
 } 
 void SetAge(int humansAge) 
 { 
 age = humansAge; 
 } 
// ...Other members and declarations 
};

假设有一个名为 eve 的 Human 实例：
    Human eve; 
如果试图使用下述代码访问成员 age：
    cout << eve.age; // compile error 
将出现类似于这样的编译错误：“错误：Human::age—不能访问 Human 类声明的私有成员”。要
访问 age，唯一的途径就是通过 Human 类的公有方法 GetAge( )，这个方法以编写 Human 类的程序员
认为的合适方式暴露 age：
        cout << eve.GetAge(); // OK 
如果编写 Human 类的程序员愿意，可以让 GetAge( )显示的年龄比 Eve 的实际年龄小！换句话说，
这意味着 C++允许类决定要暴露哪些属性以及如何暴露。如果 Human 类没有公有成员方法 GetAge( )，
就可确保用户根本无从查询 age。在本章后面将介绍的情形下，这种功能很有用。
同样，也不能直接给 Human::age 赋值：
    eve.age = 22; // compile error 
要设置年龄，唯一的途径是通过 SetAge( )：
    eve.SetAge(22); // OK 
这有很多优点。当前，SetAge( )的实现只是直接设置成员变量 Human::age，但也可在 SetAge( )中
验证外部输入，避免 age 被设置为零或负数：

class Human 
{ 
private: 
 int age; 
public: 
 void SetAge(int humansAge) 
 { 
 if (humansAge > 0) 
 age = humansAge; 
 } 
}; 
总之，C++让类的设计者能够控制类属性的访问和操纵方式
*/

//一个对外隐藏真实年龄并将自己说得更年轻的 Human 类

#include <iostream>
using namespace std;

class Human
{
  private:
    // Private member data:
    int age;

  public:
    void SetAge(int inputAge)
    {
        age = inputAge;
    }

    // Human lies about his / her age (if over 30)
    int GetAge()
    {
        if (age > 30)
            return (age - 2);
        else
            return age;
    }
    //Human 向外提供的年龄是假的：对于年龄大于 30 的人，GetAge() 返回的年龄都比实际年龄小
};

int main()
{
    Human firstMan;
    firstMan.SetAge(35);

    Human firstWoman;
    firstWoman.SetAge(22);

    cout << "Age of firstMan " << firstMan.GetAge() << endl;
    cout << "Age of firstWoman " << firstWoman.GetAge() << endl;

    return 0;
}

//如果忘记调用 SetAge( )，int 变量 Human::age 将包含未知的
//垃圾值，因为该变量未初始化;