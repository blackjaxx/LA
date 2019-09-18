//hash容器
//基于平衡二叉树的map可实现类似功能，但在数据量较大时速度不够o(logn)，不得已手动编写hash算法
//c++11引入了几个基于hash算法的容器 unordered_map unordered_set unordered_multimap unordered_multiset
//不需要元素排序时，尽量使用这些容器获得更好的查找性能
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

unordered_map<string, int> um{
    {"Dijkstra", 1972}, {"Scott", 1976}, {"Wilkes", 1967}};

um["Ritchie"] = 1983;

for (auto x; um)
{
    cout << '{' << x.first << ',' << x.second << '}';
}

//默认的hash只提供了内置数据类型的hash算法，如果自定义类型，需要提供自定义的hash函数，可以分别算出其hash，然后进行组合得到新的hash值
//容器处理碰撞时需要判断两对象是否相等，所以必须提供判断相等的方法，建议重载“==”

struct Type
{
    int x;
    string y;
    bool operator==(const Type &a) const
    {
        return x == a.x && y == a.y;
    }
};

struct HashFunc
{
    std::size_t operator()(const Type &o) const
    {
        return ((hash<int>()(o.x) ^ (hash<string>()(o.y) << 1)) >> 1);
    }
};

int main()
{
    unordered_map<Type, string, HashFunc> TESThash =
        {
            {{1, "1"}, "one"},
            {{2, "2"}, "two"},
            {{3, "3"}, "three"}};

    for (const auto &kv : TESThash)
    {
        cout << kv.first.x << "," << kv.first.y << "-" << kv.second << endl;
    }
    return 0;
}
