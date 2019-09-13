// sayings2.cpp -- using pointers to objects
// compile with string1.cpp
#include <iostream>
#include <cstdlib> // (or stdlib.h) for rand(), srand()
#include <ctime>   // (or time.h) for time()
#include "string1.h"
const int ArSize = 10;
const int MaxLen = 81;
int main()
{
    using namespace std;
    String name;
    cout << "Hi, what's your name?\n>> ";
    cin >> name;

    cout << name << ", please enter up to " << ArSize
         << " short sayings <empty line to quit>:\n";
    String sayings[ArSize];
    char temp[MaxLen]; // temporary string storage
    int i;
    for (i = 0; i < ArSize; i++)
    {
        cout << i + 1 << ": ";
        cin.get(temp, MaxLen);
        while (cin && cin.get() != '\n')
            continue;
        if (!cin || temp[0] == '\0') // empty line?
            break;                   // i not incremented
        else
            sayings[i] = temp; // overloaded assignment
    }
    int total = i; // total # of lines read

    if (total > 0)
    {
        cout << "Here are your sayings:\n";
        for (i = 0; i < total; i++)
            cout << sayings[i] << "\n";

        // use pointers to keep track of shortest, first strings
        String *shortest = &sayings[0]; // initialize to first object
        String *first = &sayings[0];
        for (i = 1; i < total; i++)
        {
            if (sayings[i].length() < shortest->length())
                shortest = &sayings[i];
            if (sayings[i] < *first) // compare values
                first = &sayings[i]; // assign address
        }
        cout << "Shortest saying:\n"
             << *shortest << endl;
        cout << "First alphabetically:\n"
             << *first << endl;

        srand(time(0));
        int choice = rand() % total;                    // pick index at random
                                                        // use new to create, initialize new String object
        String *favorite = new String(sayings[choice]); //跟踪新对象，参数初始化新的对象favorite指向new创建的未命名对象
        cout << "My favorite saying:\n"
             << *favorite << endl;
        delete favorite;
    }
    else
        cout << "Not much to say, eh?\n";
    cout << "Bye.\n";
    // keep window open
    /*    if (!cin)
        cin.clear();
    while (cin.get() != '\n')
        continue;
    cin.get();

*/
    return 0;
}

/*
如下情况析构函数将被调用

如果对象是动态变量，执行完定义该对象的程序块时，调用该对象的析构函数
对象是静态变量，程序结束时将调用对象的析构函数
如果对象是用new创建的，仅当使用delete时，析构才会被调用
*/

/*
指针和对象小结：

使用常规表示法声明指向对象的指针
String *glamour;

可以将指针初始化为指向已有对象
String *first = &sayings[0];

可以使用new初始化指针，这将创建一个新的对象
String *favorite = new String(sayings[choice]);

对类使用new将调用相应的类构造函数来初始化新创建的对象
String *gleep = new String;
String *glop = new String("my my my");  //invokes the String(const char *) constructor
String *favorite = new String(sayings[choice]);  //invokes the String(const String &) constructor;



*/