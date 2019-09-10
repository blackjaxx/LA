/*
    class Human 
{ 
 // Member attributes: 
 string name; 
 string dateOfBirth; 
 string placeOfBirth; 
 string gender; 
 // Member functions: 
 void Talk(string textToTalk); 
 void IntroduceSelf(); 
 ... 
};

类相当于蓝图，仅声明类并不会对程序的执行产生影响。在程序执行阶段，对象是类的化身。要
使用类的功能，通常需要创建其实例—对象，并通过对象访问成员方法和属性。
创建 Human 对象与创建其他类型（如 double）的实例类似

    double pi= 3.1415; // a variable of type double 
    Human firstMan; // firstMan: an object of class Human

就像可以为其他类型（如 int）动态分配内存一样，也可使用 new 为 Human 对象动态地分配内存：

    int* pointsToNum = new int; // an integer allocated dynamically 
    delete pointsToNum; // de-allocating memory when done using

    Human* firstWoman = new Human(); // dynamically allocated Human 
    delete firstWoman; // de-allocating memory

    一个人的例子是 Adam，男性，1970 年出生于阿拉巴马州。firstMan 是 Human 类的对象，是这个
类存在于现实世界（运行阶段）的化身：
    Human firstMan; // an instance i.e. object of Human

    类声明表明，firstMan 有 dateOfBirth 等属性，可使用句点运算符（.）来访问:

    firstMan.dateOfBirth = "1970"; 
    这是因为从类声明表示的蓝图可知，属性 dateOfBirth 是类 Human 的一部分。仅当实例化了一个对
象后，这个属性在现实世界（运行阶段）才存在。句点运算符（.）用于访问对象的属性。
这也适用于 IntroduceSelf( )等方法

    firstMan.IntroduceSelf(); 
    如果有一个指针 firstWoman，它指向 Human 类的一个实例，则可使用指针运算符（->）来访问成
员（这将在下一小节介绍），也可使用间接运算符（*）来获取对象，再使用句点运算符来访问成员

    Human* firstWoman = new Human(); 
    (*firstWoman).IntroduceSelf();

    如果对象是使用 new 在自由存储区中实例化的，或者有指向对象的指针，则可使用指针运算符（->）
来访问成员属性和方法
    Human* firstWoman = new Human(); 
    firstWoman->dateOfBirth = "1970"; 
    firstWoman->IntroduceSelf(); 
    delete firstWoman;

*/

//一个值得编译的 Human 类

#include <iostream>
#include <string>
using namespace std;

class Human
{
  public:
    string name;
    int age;

    void IntroduceSelf()
    {
        cout << "I am " + name << " and am ";
        cout << age << " years old" << endl;
    }
};

int main()
{
    // An object of class Human with attribute name as "Adam"
    Human firstMan;
    firstMan.name = "Adam";
    firstMan.age = 30;

    // An object of class Human with attribute name as "Eve"
    Human firstWoman;
    firstWoman.name = "Eve";
    firstWoman.age = 28;

    firstMan.IntroduceSelf();
    firstWoman.IntroduceSelf();
}
