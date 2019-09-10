//静态成员对模板类和实例的影响
#include <iostream> 
using namespace std; 
 
template <typename T> 
class TestStatic 
{ 
    public: 
        static int staticVal; 
};

// static member initialization 它初始化模板类的静态成员 
template<typename T> int TestStatic<T>::staticVal;
 
int main() 
{ 
    TestStatic<int> intInstance;
    //创建模板实例
    cout << "Setting staticVal for intInstance to 2011" << endl; 
    intInstance.staticVal = 2011;

    TestStatic<double> dblnstance;
    cout << "Setting staticVal for Double_2 to 1011" << endl;
    dblnstance.staticVal = 1011;

    cout << "intInstance.staticVal = " << intInstance.staticVal << endl; 
    cout << "dblnstance.staticVal = " << dblnstance.staticVal << endl; 

    return 0; 
}