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
