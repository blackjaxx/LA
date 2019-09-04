//最大连续和问题。 给出一个长度为n的序列A1, A2,…, An， 求最大连续和。 换句话说， 要
//求找到1≤i≤j≤n， 使得 尽量大;

//暴力枚举法
//时间复杂度 O(n*3)
#include <stdio.h>
#define n 100 //假设数组输入数组长度不大于100

int main()
{
    int a[] = {}; //nsize
    int tot = 0;
    int best = a[1];

    for (int i = 0; i <= n; i++)
        for (int j = i; j <= n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += a[k];
                tot++; //统计为计算出子序列一共尝试累加了多少次
            }
            if (sum > best)
                best = sum; //max update
        }
}

//若使用数学方法
//连续子序列之和等于两个前缀和之差
//A[i]+A[i+1]+...+A[j]=S[j]-S[j-1]
//时间复杂度降为O(n*2)

/* 
S[0] = 0;
    for (int i = 1; i <= n; i++)
        S[i] = S[i - 1] + A[i]; //递推前缀和S
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            best = max(best, S[j] - S[i - 1]); //更新最大值


*/

/*
若使用分治法来解决问题

划分问题： 把问题的实例划分成子问题。
递归求解： 递归解决子问题。
合并问题： 合并子问题的解得到原问题的解。

前两部分没有什么特别之处， 关键在于“合并”步骤。 既然起点位于左半， 终点位于右
半， 则可以人为地把这样的序列分成两部分， 然后独立求解： 先寻找最佳起点， 然后再寻找
最佳终点；

 */

#include <cmath>
#include <cstdio>

int maxsum(int *A, int x, int y)
{
    int v, L, R, maxs;
    if (y - x == 1)
        return A[x];

    int m = x + (y - x) / 2;
    int maxs = max(maxsum(A, x, m), maxsum(A, m, y));
    v = 0;
    L = A[m - 1];
    for (int i = m - 1; i >= x; i--)
        L = max(L, v += A[i]);
    for (int i = m; i < y; i++)
        R = max(R, v += A[i]);
    return max(maxs, L + R);
}