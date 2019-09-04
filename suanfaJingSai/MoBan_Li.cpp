/* 

int sum(int *begin, int *end)
{
    int *p = begin;
    int ans = 0;
    for (int *p = begin; p != end; p++)
        ans += *p;
    return ans;
}

*/
#include <iostream>
using namespace std;
template <typename T>
T sum(T *begin, T *end)
{
    T *p = begin;
    T ans = 0;
    for (T *p = begin; p != end; p++)
        ans = ans + *p;
    return ans;
}
//这样， 就可以用sum函数给double数组和Point数组求和了
template <typename T>
struct Point
{
    T x, y;
    Point(T x = 0, T y = 0) : x(x), y(y) {}
};
//然后把“+”和“<<”的代码也稍加改变：
template <typename T>
Point<T> operator+(const Point<T> &A, const Point<T> &B)
{
    return Point<T>(A.x + B.x, A.y + B.y);
}
template <typename T>
ostream &operator<<(ostream &out, const Point<T> &p)
{
    out << "(" << p.x << "," << p.y << ")";
    return out;
}