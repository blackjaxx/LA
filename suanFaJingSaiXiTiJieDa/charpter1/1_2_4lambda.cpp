//匿名函数
//lambda是比较重要的改进，是函数式编程的基石
//即在需要的地方定义函数不是提前定义好才能使用
#include <stdlib.h> //rand()
#include <cstdio>
#include <ctime>     //time()
#include <algorithm> //sort()
using namespace std;
#define _for(i, a, b) for (int i = a; i < b; i++)
const int N = 10000000;
struct TS
{
    int a, b, c;
};

TS tss[N];

void getData()
{
    _for(i, 0, N)
    {
        tss[i].a = rand();
        tss[i].b = rand();
        tss[i].c = rand();
    }
}

int main()
{
    getData();
    sort(tss, tss + N, [](const TS &t1, const TS &t2) {
        if (t1.a != t2.a)
        {
            return t1.a < t2.a;
        }
        if (t1.b != t2.b)
        {
            return t1.b < t2.b;
        }
        return t1.c <= t2.c;
    }); //sort函数需要的第三个参数functor，functor本质是一个类，这个类重载了operator，这个对象可以像函数一样被使用
    return 0;
}

//c++11中，functor可以直接用lambda替代，lambda也可以对外围作用域变量进行捕捉：
vector<int> list{1, 2, 3};
int total = 0;
for_each(list.begin(), list.end(), [&total](int x) //这里传引用，对total进行写操作
         {
             //匿名函数捕捉total
             total += x;
         });
cout << total << endl;

//可以像声明一个变量声明一个函数
total = 0;
std::functor<void(int)> add = [&total](int x) {
    total += x;
};

for_each(begin(list), end(list), add);
cout << total << endl;

//或者类型部分也可以直接使用类型推导

total = 0;
auto add2 = [&total](int x) {
    total += x;
};
for_each(begin(list), end(list), add2);
cout << total << endl;