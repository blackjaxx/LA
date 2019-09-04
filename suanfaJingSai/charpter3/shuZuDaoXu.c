/*
读入一些整数， 逆序输出到一行中。 已知整数不超过100个。 
 */

#include <stdio.h>
#define maxn 105

int a[maxn];

int main()
{
    int x, n = 0;
    while (scanf("%d", &x) == 1)
        a[n++] = x; //首先赋值a[n]＝ x， 然后执行n＝ n＋ 1

    for (int i = n - 1; i >= 1; i--)
        printf("%d", a[i]);
    printf("%d\n", a[0]);
    return 0;
}