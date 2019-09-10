/*
    C++提供了一种新的类型转换运算符，专门用于基于继承的情形，这种情
形在 C 语言编程中并不存在。
4 个 C++类型转换运算符如下：
• static_cast 
• dynamic_cast 
• reinterpret_cast 
• const_cast 
这 4 个类型转换运算符的使用语法相同：
destination_type result = cast_operator<destination_type> (object_to_cast);


    static_cast 用于在相关类型的指针之间进行转换，还可显式地执行标准数据类型的类型转换—这
种转换原本将自动或隐式地进行。用于指针时，static_cast 实现了基本的编译阶段检查，确保指针被转
换为相关类型。这改进了 C 风格类型转换，在 C 语言中，可将指向一个对象的指针转换为完全不相关
的类型，而编译器不会报错。使用 static_cast 可将指针向上转换为基类类型，也可向下转换为派生类型，
如下面的示例代码所示

    Base* objBase = new Derived (); 
    Derived* objDer = static_cast<Derived*>(objBase); // ok!
    // class Unrelated is not related to Base 
    Unrelated* notRelated = static_cast<Unrelated*>(objBase); // Error 
    // The cast is not permitted as types are unrelated

    将 Derived*转换为 Base*被称为向上转换，无需使用任何显式类型转换运算符就能进行
    这种转换：
        Derived objDerived; 
        Base* objBase = &objDerived; // ok!

    将 Base*转换为 Derived*被称为向下转换，如果不使用显式类型转换运算符，就无法进
    行这种转换：
        Derived objDerived; 
        Base* objBase = &objDerived; // Upcast -> ok! 
        Derived* objDer = objBase; // Error: Downcast needs explicit cast



    然而，static_cast 只验证指针类型是否相关，而不会执行任何运行阶段检查。因此，程序员可使用
static_cast 编写如下代码，而编译器不会报错

    Base* objBase = new Base(); 
    Derived* objDer = static_cast<Derived*>(objBase); // Still no errors!

    其中 objDer 实际上指向一个不完整的 Derived 对象，因为它指向的对象实际上是 Base()类型。由
于 static_cast 只在编译阶段检查转换类型是否相关，而不执行运行阶段检查，因此 objDer -> 
DerivedFunction()能够通过编译，但在运行阶段可能导致意外结果。
除用于向上转换和向下转换外，static_cast 还可在很多情况下将隐式类型转换为显式类型，以引起
程序员或代码阅读者的注意

    double Pi = 3.14159265; 
    int num = static_cast<int>(Pi); // Making an otherwise implicit cast, explicit
    在上述代码中，使用 num = Pi 将获得同样的效果，但使用 static_cast 可让代码阅读者注意到这里
使用了类型转换，并指出（对知道 static_cast 的人而言）编译器根据编译阶段可用的信息进行了必要的
调整，以便执行所需的类型转换。对于使用关键字 explicit 声明的转换运算符和构造函数，要使用它们，
也必须通过 static_cast



    顾名思义，与静态类型转换相反，动态类型转换在运行阶段（即应用程序运行时）执行类型转换。
可检查 dynamic_cast 操作的结果，以判断类型转换是否成功。使用 dynamic_cast 运算符的典型语法如下
    destination_type* Dest = dynamic_cast<class_type*>(Source); 
    if(Dest) // Check for success of the casting operation 
        Dest->CallFunc ();
    Base* objBase = new Derived();
    // Perform a downcast 
    Derived* objDer = dynamic_cast<Derived*>(objBase); 
    if(objDer) // Check for success of the cast 
        objDer->CallDerivedFunction ();

    如上述代码所示，给定一个指向基类对象的指针，程序员可使用 dynamic_cast 进行类型转换，并
在使用指针前检查指针指向的目标对象的类型。在上述示例代码中，目标对象的类型显然是 Derived，
因此这些代码只有演示价值。然而，情况并非总是如此，例如，将 Derived*传递给接受 Base*参数的函
数时。该函数可使用 dynamic_cast 判断基类指针指向的对象的类型，再执行该类型特有的操作。总之，
可使用 dynamic_cast 在运行阶段判断类型，并在安全时使用转换后的指针

*/

//使用动态转换判断 Fish 指针指向的是否是 Tuna 对象或 Carp 对象

#include <iostream> 
using namespace std; 

class Fish 
{ 
    public: 
    virtual void Swim() 
    { 
        cout << "Fish swims in water" << endl; 
    } 

    // base class should always have virtual destructor 
    virtual ~Fish() {} 
}; 
 
class Tuna: public Fish
//Tuna 和 Carp 从基类 Fish 派生而来
{ 
    public: 
    void Swim() 
    { 
        cout << "Tuna swims real fast in the sea" << endl; 
    } 

    void BecomeDinner()
    //包含一个特有的函数
    { 
        cout << "Tuna became dinner in Sushi" << endl; 
    } 
}; 

class Carp: public Fish
//Tuna 和 Carp 从基类 Fish 派生而来
{  

    public: 
        void Swim() 
        { 
            cout << "Carp swims real slow in the lake" << endl; 
        } 

        void Talk()
        //包含一个特有的函数
        { 
            cout << "Carp talked Carp!" << endl; 
        }; 
};

void DetectFishType(Fish *objFish)//*objFish是Fish类型指针
//给定一个基类指针（Fish*），您可动态地检测它指向的是否是 Tuna 或 Carp
{ 
    Tuna* objTuna = dynamic_cast <Tuna*>(objFish); 
    if (objTuna) // check success of cast 
        {
            cout << "Detected Tuna. Making Tuna dinner: " << endl; 
            objTuna->BecomeDinner();
            //知道指针 objTuna 指向的是一
            //个有效的 Tuna 对象，因此可以使用它来调用函数 Tuna::BecomeDinner()
        }
        //使用 dynamic_cast 传入的基类指针（Fish*）参数指向的是否是 Tuna 对象。如
        //果该 Fish *指向的是 Tuna 对象，该运算符将返回一个有效的地址，否则将返回 NULL

    Carp *objCarp = dynamic_cast<Carp *>(objFish);
    if (objCarp) 
        { 
            cout << "Detected Carp. Making carp talk: " << endl; 
            objCarp->Talk(); 
        } 

    cout << "Verifying type using virtual Fish::Swim: " << endl; 
    objFish->Swim(); // calling virtual function Swim 
} 

int main() 
{ 
    Carp myLunch; 
    Tuna myDinner; 

    DetectFishType(&myDinner); 
    cout << endl; 
    DetectFishType(&myLunch); 

    return 0; 
}

/*
    reinterpret_cast 是 C++中与 C 风格类型转换最接近的类型转换运算符。它让程序员能够将一种对象
类型转换为另一种，不管它们是否相关；也就是说，它使用如下所示的语法强制重新解释类型：
reinterpret_cast 只改变对指针的解释，并不改变指向的对象
    Base* objBase = new Base (); 
    Unrelated* notRelated = reinterpret_cast<Unrelated*>(objBase); 
    // The code above compiles, but is not good programming! 
    这种类型转换实际上是强制编译器接受 static_cast 通常不允许的类型转换，通常用于低级程序（如
驱动程序），在这种程序中，需要将数据转换为 API（应用程序编程接口）能够接受的简单类型（例如，
有些 OS 级 API 要求提供的数据为 BYTE 数组，即 unsigned char*）：
    SomeClass* object = new SomeClass(); 
    // Need to send the object as a byte-stream... 
    unsigned char* bytesFoAPI = reinterpret_cast<unsigned char*>(object);

    应尽量避免在应用程序中使用 reinterpret_cast，因为它让编译器将类型 X 视为不相关的
类型 Y，这看起来不像是优秀的设计或实现;
*/

/*
    const_cast 让程序员能够关闭对象的访问修饰符 const。您可能会问：为何要进行这种转换？在理
想情况下，程序员将经常在正确的地方使用关键字 const
    class SomeClass 
    { 
        public: 
        // ... 
            void DisplayMembers(); //problem - display function isn't const 
    };

    在下面的函数中，以 const 引用的方式传递 object 显然是正确的。毕竟，显示函数应该是只读的，
不应调用非 const 成员函数，即不应调用能够修改对象状态的函数。然而，DisplayMembers()本应为 const
的，但却没有这样定义。如果 SomeClass 归您所有，且源代码受您控制，则可对 DisplayMembers()进
行修改。然而，在很多情况下，它可能属于第三方库，无法对其进行修改。在这种情况下，const_cast
将是您的救星;
    void DisplayAllData (const SomeClass& object) 
    { 
        object.DisplayMembers (); // Compile failure 
        // reason: call to a non-const member using a const reference 
    }
    在这种情况下，调用 DisplayMembers()的语法如下
    void DisplayAllData (const SomeClass& object) 
    { 
        SomeClass& refData = const_cast<SomeClass&>(object); 
        refData.DisplayMembers(); // Allowed! 
    }
    除非万不得已，否则不要使用 const_cast 来调用非 const 函数。一般而言，使用 const_cast 来修改
const 对象可能导致不可预料的行为;
    另外，const_cast 也可用于指针;
    void DisplayAllData (const SomeClass* data) 
    { 
        // data->DisplayMembers(); Error: attempt to invoke a non-const function! 
        SomeClass* pCastedData = const_cast<SomeClass*>(data); 
        pCastedData->DisplayMembers(); // Allowed! 
    }



    请牢记，将 Derived*转换为 Base*被称为向上转换；这种转换是安全的。请牢记，将 Base*转换为 Derived*被称为向下转
换；除非使用 dynamic_cast 并核实转换成功，否则这种转换不安全。请牢记，创建继承层次结构时，应尽量将函数
声明为虚函数。这样通过基类指针调用这些函数时，如果该指针指向的是派生类对象，将调用相应类的函数版本

    使用 dynamic_cast 时，别忘了对转换得到的指针进行检查，看其是否有效。设计应用程序时，不要使用 dynamic_cast 来依赖于 RTTI
*/