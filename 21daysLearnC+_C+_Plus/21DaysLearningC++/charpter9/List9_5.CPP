//一个有重载的构造函数，但没有默认构造函数的类

#include <iostream>
#include <string>
using namespace std;

class Human
{
private:
  string name;
  int age;

public:
  Human(string humansName, int humansAge)
  {
    name = humansName;
    age = humansAge;
    cout << "Overloaded constructor creates " << name;
    cout << " of age " << age << endl;
  }

  void IntroduceSelf()
  {
    cout << "I am " + name << " and am ";
    cout << age << " years old" << endl;
  }
};

int main()
{
  Human firstMan("Adam", 25);
  Human firstWoman("Eve", 28);

  firstMan.IntroduceSelf();
  firstWoman.IntroduceSelf();
}
//没有默认构造函数，而在您提供了重载的构造函数时，C++编译器不会为您生成默认构造函
//数。这个示例还表明，可在创建 Human 对象时提供 name 和 age，且以后不能修改它们
//这是因为 Human类的 name 属性存储在私有变量 Human::name 中，main() 或其他不属于 Human 类成员的实体不能访问或修改它

//带默认值的构造函数参数
//就像函数可以有带默认值的参数一样，构造函数也可以。在下面的代码中，对程序清单 9.5 中第14行的构造函数稍做了修改，给参数 age 指定了默认值 25
/*

class Human 
{ 
private: 
 string name; 
 int age; 
public: 
 // overloaded constructor (no default constructor) 
 Human(string humansName, int humansAge = 25) 
 { 
 name = humansName; 
 age = humansAge; 
 cout << "Overloaded constructor creates " << name; 
 cout << " of age " << age << endl; 
 } 
 // ... other members 
};

*/

/*
//实例化这个类时，可使用下面的语法：
  Human adam("Adam"); // adam.age is assigned a default value 25
  Human eve("Eve, 18); // eve.age is assigned 18 as specified
  */
