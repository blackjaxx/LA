//模板类是创建类的蓝图，因此在编译器看来，仅当模板类以某种方式被使用后，其代码才存在 换言之，对于您定义了但未使用的模板类，编译器将忽略它
//模板具体化

#include <iostream> 
using namespace std; 

template <typename T1 = int, typename T2 = double>
//par1 = int par2 = double
class HoldsPair 
{ 
    private: 
        T1 value1;
        T2 value2;
    public: 
        HoldsPair(const T1& val1, const T2& val2) : value1(val1), value2(val2) {} 

    // Accessor functions 
    const T1 & GetFirstValue() const; 
    const T2& GetSecondValue() const; 
}; 

    // specialization of HoldsPair for types int & int here 
template<> class HoldsPair<int, int> 
{ 
    private: 
        int value1; 
        int value2; 
        string strFun; 
    public: 
        HoldsPair(const int& val1, const int& val2) : value1(val1), value2(val2) {} 
        const int & GetFirstValue() const 
        { 
            cout << "Returning integer " << value1 << endl; 
            return value1; 
        } 
};

int main() 
{ 
    HoldsPair<int, int> pairIntInt(222, 333); 
    pairIntInt.GetFirstValue(); 

    return 0; 
}
//这个模板定义甚至都没有提供存取函数 GetFirstValue() 和 GetSecondValue() 的实现，但程序依然能够通过编译。这是因为
//编译器只需考虑针对<int, int> 的模板实例化，而在这个实例化中，我们提供了完备的具体实现