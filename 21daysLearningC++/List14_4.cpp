/*
    下面是一个简单的模板类，它只有单个模板参数 T，用于存储一个成员变量
    template <typename T> 
    class HoldVarTypeT 
    { 
    private: 
        T value; 
    public: 
        void SetValue (const T& newValue) { value = newValue; } 
        T& GetValue() {return value;} 
    };

    来看该模板类的一种用法
    HoldVarTypeT <int> holdInt; // template instantiation for int 
    holdInt.SetValue(5); 
    cout << "The value stored is: " << holdInt.GetValue() << endl;



    template <typename T1, typename T2> 
    class HoldsPair 
    { 
        private: 
            T1 value1; 
            T2 value2; 
        public: 
            // Constructor that initializes member variables 
            HoldsPair (const T1& val1, const T2& val2) 
                { 
                    value1 = val1; 
                    value2 = val2; 
                }; 
                // ... Other member functions 
    };

    // A template instantiation that pairs an int with a double 
    HoldsPair <int, double> pairIntDouble (6, 1.99); 
    // A template instantiation that pairs an int with an int
    HoldsPair <int, int> pairIntDouble (6, 500);


    可以修改前面的 HoldsPair <…>，将模板参数的默认类型指定为 int：
    template <typename T1=int, typename T2=int> 
    class HoldsPair 
        { 
            // ... method declarations 
        }; 
    这与给函数指定默认参数值极其类似，只是这里指定的是默认类型

    这样，前述第二种 HoldsPair 用法可以简写为：
    // Pair an int with an int (default type) 
    HoldsPair <> pairInts (6, 500);
*/

//包含两个成员属性的模板类

#include <iostream> 
using namespace std; 

// template with default params: int & double
template <typename T1 = int, typename T2 = double>
//模板参数列表，它定义了两个参数（T1 和 T2），这两个参数的默认类型分别为 int 和 double
class HoldsPair
{ 
    private: 
        T1 value1; 
        T2 value2; 
    public: 
        HoldsPair(const T1& val1, const T2& val2) : value1(val1), value2(val2) {
        }//构造

    // Accessor functions 
    const T1 & GetFirstValue () const 
    { 
        return value1; 
    } 
    
    const T2& GetSecondValue () const 
    { 
        return value2; 
    } 
}; 
 
int main () 
{ 
    HoldsPair<> pairIntDbl (300, 10.09); 
    HoldsPair<short,const char*>pairShortStr(25,"Learn templates, love C++");

    cout << "The first object contains -" << endl; 
    cout << "Value 1: " << pairIntDbl.GetFirstValue () << endl; 
    cout << "Value 2: " << pairIntDbl.GetSecondValue () << endl; 

    cout << "The second object contains -" << endl; 
    cout << "Value 1: " << pairShortStr.GetFirstValue () << endl; 
    cout << "Value 2: " << pairShortStr.GetSecondValue () << endl; 
 
    return 0; 
}
//如何声明模板类 HoldsPair 来存储两个值
//存取器函数 GetFirstValue ()和 GetSecondValue()用于查询对象的值，它们将根据模板实例化
//语法返回正确的对象类型。HoldsPair 定义了一种模式，可通过重用该模式针对不同的变量类型实现相同的逻辑