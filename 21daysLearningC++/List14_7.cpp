//如果需要编写一个函数，能够计算任意数量值的和，就需要使用参数数量可变
//的模板。参数数量可变的模板是 2014 年发布的 C++ 14 新增的
//使用参数数量可变的模板的函数
#include <iostream> 
using namespace std;

template <typename Res, typename ValType>
void Sum(Res& result, ValType& val)
{ 
    result = result + val;
} 
 
template <typename Res, typename First, typename... Rest>
void Sum(Res& result, First val1, Rest... valN)
{ 
    result = result + val1;
    return Sum(result, valN ...);
} 
 
int main()
{ 
    double dResult = 0;
    Sum (dResult, 3.14, 4.56, 1.1111);
    //调用 Sum()时指定了 4 个参数
    cout << "dResult = " << dResult << endl;
 
    string strResult;
    Sum (strResult, "Hello ", "World");
    //调用它时指定了 3 个参数
    cout<< "strResult = " << strResult.c_str() << endl;

    return 0;
}
//千万不要将 sizeof…()和 sizeof(Type)混为一谈。后者返回类型的长度，而前者指出向参
//数数量可变的模板传递了多少个参数