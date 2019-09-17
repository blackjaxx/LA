//经常用到STL中的容器类，如vector或set，且在调试中经常需要输出容器的内容，每次都要写循环来输出，封装两个泛型函数使用C++ IO流对集合的输出
#include <iostream>
#include <vector>
#include <set>
using namespace std;

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        os << v[i] << " ";
        return os;
    }
}

template <typename T>
ostream &operator<<(ostream &os, const set<T> &v)
{
    for (typename set<T>::iterator it = v.begin(); it != v.end(); it++)
    {
        os << *it << " ";
        return os;
    }
}

vector<int> a;
a.push_back(1);
a.push_back(2);
cout << a;

set<string> b;
b.insert("1");
b.insert("2");
cout << b;
