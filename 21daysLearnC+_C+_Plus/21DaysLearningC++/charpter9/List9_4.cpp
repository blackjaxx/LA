//包含多个构造函数的 Human 类
//重载构造函数

#include <iostream>
#include <string>
using namespace std;

class Human
{
  private:
    string name;
    int age;

  public:
    Human() // default constructor
    {
        age = 0; // initialized to ensure no junk value
        cout << "Default constructor: name and age not set" << endl;
    }

    Human(string humansName, int humansAge) // overloaded
    {
        name = humansName;
        age = humansAge;
        cout << "Overloaded constructor creates ";
        cout << name << " of " << age << " years" << endl;
    }
};

int main()
{
    Human firstMan;              // use default constructor
    Human firstWoman("Eve", 20); // use overloaded constructor
}
