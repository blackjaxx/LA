//排序的性能问题
//sort有两种用法：第一种是传入一个functor对象，另一种是直接传入排序函数
//性能上STL的functor是最快的比qsort快一倍多，sort传入指针的版本是最慢的，相对于前者大概有3至6倍差距，所以对排序性能要求较高的题目应注意

//测试代码
#include <stdlib.h> //rand()
#include <cstdio>
#include <ctime>     //time()
#include <algorithm> //sort()
using namespace std;
#define _for(i, a, b) for (int i = a; i < b; ++i)
const int N = 1000000;
struct TS
{
    int a, b, c;
};

inline bool cmp(const TS &t1, const TS &t2)
{
    if (t1.a != t2.a)
    {
        return t1.a < t2.a;
    }

    if (t1.b != t2.b)
    {
        return t1.b < t2.b;
    }
    return t1.c <= t2.c;
}

int cmp4qsort(const void *a, const void *b)
{
    TS *t1 = (TS *)a, *t2 = (TS *)b;
    if (t1->a != t2->a)
    {
        return t1->a - t2->a;
    }
    if (t1->b != t2->b)
    {
        return t1->b - t2->b;
    }
    return t1->c - t2->c;
}

struct cmpFunctor
{
    inline bool operator()(const TS &t1, const TS &t2)
    {
        if (t1.a != t2.a)
        {
            return t1.a < t2.a;
        }
        if (t1.b != t2.b)
        {
            return t1.b < t2.b;
        }
        return t1.c <= t2.c;
    }
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
    srand(time(NULL));

    getData();
    clock_t start = clock();
    sort(tss, tss + N, cmpFunctor());
    printf("Sort By Function Pointer : %ld\n", clock() - start);

    getData();
    start = clock();
    sort(tss, tss + N, cmpFunctor());
    printf("Sort By Functor : %ld\n", clock() - start);

    getData();
    start = clock();
    qsort(tss, N, sizeof(TS), cmp4qsort);
    printf("Sort By Function Pointer : %ld\n", clock() - start);

    return 0;
}

/*
测试并跑通数据


*/

/*

c++的rand()函数和srand()函数:

1、rand()不需要参数，它会返回一个从0到最大随机数的任意整数，最大随机数的大小通常是固定的一个大整数。
2、如果你要产生0~99这100个整数中的一个随机整数，可以表达为：int num = rand() % 100; 
这样，num的值就是一个0~99中的一个随机数了。
3、如果要产生1~100，则是这样：int num = rand() % 100 + 1;  
4、总结来说，可以表示为：int num = rand() % n +a;其中的a是起始值，n-1+a是终止值，n是整数的范围。
5、一般性：rand() % (b-a+1)+ a ;    就表示  a~b 之间的一个随机整数。
6、若要产生0~1之间的小数，则可以先取得0~10的整数，然后均除以10即可得到“随机到十分位”的10个随机小数。
若要得到“随机到百分位”的随机小数，则需要先得到0~100的10个整数，然后均除以100，其它情况依此类推。
7、通常rand()产生的随机数在每次运行的时候都是与上一次相同的，这样是为了便于程序的调试。
若要产生每次不同的随机数，则可以使用srand( seed )函数进行产生随机化种子，随着seed的不同，就能够产生不同的随机数。
8、还可以包含time.h头文件，然后使用srand(time(0))来使用当前时间使随机数发生器随机化，这样就可以保证每两次运行时可以得到不同的随机数序列，同时这要求程序的两次运行的间隔超过1秒。

*/

/*

STL中的sort()和qsort():

函数名 功能描述

sort 对给定区间所有元素进行排序;
stable_sort 对给定区间所有元素进行稳定排序;
partial_sort 对给定区间所有元素部分排序;
partial_sort_copy 对给定区间复制并排序;
nth_element 找出给定区间的某个位置对应的元素;
is_sorted 判断一个区间是否已经排好序;
partition 使得符合某个条件的元素放在前面; 
stable_partition 相对稳定的使得符合某个条件的元素放在前面;

要使用此函数只需用#include <algorithm> sort即可使用;




*/
