//内存池
//一般的做法是开辟数组，但是大小实现难以估计，逻辑控制中还需要维护变量的释放和分配，如果多种对象都需要动态分配，则非常繁琐
//基于vector和c++内存分配机制，编写一个内存池
#include <vector>
template <typename T>
struct Pool
{
    vector<T *> buf; //vector对象
    T *createNew()   //
    {
        buf.push_back(newT());
        return buf.back(); //返回当前vector容器中末尾元素的引用
    }

    void dispose() //释放内存
    {
        for (int i = 0; i < buf.size(); i++)
        {
            delete buf[i];
        }
        buf.clear();
    }
};

struct Node
{
    ...
};
struct Node2
{
    ...
};

Pool<Node> n1Pool;
Pool<Node> n2Pool;
//要分配内存构造新对象的时候，直接调用
Node *p = n1Pool.createNew();
Node *p2 = n2Pool.createNew();
//每次释放时调用dispose方法即可，不需要维护中间变量