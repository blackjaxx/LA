//泛型参数的使用
//很多算法都会在结构体中开辟一个数组，并且使用类似MAXSIZE的结构全局定义这个数组的大小，典型的如Dijkstra等算法
const int MAXSIZE;
struct Dijkstra
{
    int m, n, d[MAXSIZE], p[MAXSIZE];
    ...
};

//如果题目需要定义多个MAXSIZE变量，比较麻烦，解决办法是引入泛型参数
template <int MAXSIZE>
struct Dijkstra
{
    int n, m, d[MAXSIZE], p[MAXSIZE];
};

//使用时就可以指定不同MAXSIZE
Dijkstra<MAXK * MAXN> sd;
Dijkstra<MAXN> pd;
/*
泛型参数问题：
    模板的声明或定义只能在全局，命名空间或类范围内进行。即不能在局部范围，函数内进行，比如不能在main函数中声明或定义一个模板。

    模板分为两种，一种是类模板，一种是函数模板。

    使用模板的目的就是能够让程序员编写与类型无关的代码。比如编写了一个交换两个整型int 类型的swap函数，这个函数就只能实现int 型，
对double，字符这些类型无法实现，要实现这些类型的交换就要重新编写另一个swap函数。使用模板的目的就是要让这程序的实现与类型无关，
比如一个swap模板函数，即可以实现int 型，又可以实现double型的交换。模板可以应用于函数和类。

    函数模板格式：

    template <class 形参名，class 形参名，......> 返回类型 函数名(参数列表)
    {
        函数体
    }

*/