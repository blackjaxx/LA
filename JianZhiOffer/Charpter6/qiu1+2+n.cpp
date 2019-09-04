//求1+2+...+n
//剑指offer第64题
//累加和，要求不能使用乘除法，for，while，if，else，switch，else等关键语句和条件判断语句（三目运算符）
//实际软件开发不会有这么苛刻的条件

//解法一：可以利用构造函数求解
//定义一个类型，创建该类型的N个实例，则会调用N次构造函数，将累加的代码放入构造函数，则可以模拟循环
class Temp
{
public:
    Temp()
    {
        ++N;
        sum += N;
    }

    static void Reset()
    {
        N = 0;
        sum = 0;
    }
    static unsigned int GetSum() { return sum; }

private:
    static unsigned int N;
    static unsigned int sum;
};

unsigned int Temp::N = 0;
unsigned int Temp::sum = 0;

unsigned int Sum_Solution1(unsigned int n)
{
    Temp::Reset();

    Temp *a = new Temp[n];
    delete[] a;
    a = nullptr;
    return Temp::GetSum();
}

//解法二：虚函数
//一个函数充当递归函数的角色，一个函数处理终止递归的角色
//如何确定选哪个函数呢，需要用到bool值，那么我们如何把n变为bool值，连续两次取反运算 ！！n，就变为bool值了
class A;
A *Array[2];

class A
{

public:
    virtual unsigned int Sum(unsigned int n)
    {
        return 0;
    }
};

class B : public A
{
public:
    virtual unsigned int Sum(unsigned int n)
    {
        return Array[!!n]->Sum(n - 1) + n;
    }
};

int Sum_Solution2(int n)
{
    A a;
    B b;
    Array[0] = &a; //当数组的下标元素为0的时候调用a的实例
    Array[1] = &b; //其余情况调用b的实例

    int value = Array[1]->Sum(n);

    return value;
}

//这里考察到虚函数的用法

//如果在纯C环境中，没有虚函数这样的特性，需要用函数指针模拟
//解法三：函数指针
typedef unsigned int (*fun)(unsigned int);

unsigned int Solution3_Teminator(unsigned int)
{
    return 0;
}

unsigned int Sum_Solution3(unsigned int n)
{
    static fun f[2] = {Solution3_Teminator, Sum_Solution3};
    return n + f[!!n](n - 1);
}

//解法四：利用模板类型求解
template <unsigned int n>
struct Sum_Solution4
{
    enum Value
    {
        N = Sum_Solution4<n - 1>::N + n
    }
};

template <>
struct Sum_Solution4<1>
{
    enum Value
    {
        N = 1
    };
};

//本体考察全面，涉及构造函数，虚拟指针，函数指针，模板类型与实例化等知识点