/*

现有N个大理石， 每个大理石上写了一个非负整数。 首先把各数从小到大排序， 然后回
答Q个问题。 每个问题问是否有一个大理石写着某个整数x， 如果是， 还要回答哪个大理石上
写着x。 排序后的大理石从左到右编号为1～ N。 （ 在样例中， 为了节约篇幅， 所有大理石上
的数合并到一行， 所有问题也合并到一行。）

样例输入：

2 3 5 1
5 4
1
5 2
1 3 3 3 1
2 3

样例输出：

CASE #1:
5 found at 4
CASE #2:
2 not found
3 found at 3

 */
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 10000;

int main()
{
    int n, q, x, a[maxn], kase = 0;
    while (scanf("%d%d", &n, &q) == 2 && n)
    {
        printf("CASE# %d:\n", ++kase);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a, a + n); //排序
        while (q--)
        {
            scanf("%d", &x);
            int p = lower_bound(a, a + n, x) - a; //在已排序数组a中寻找x
            if (a[p] == x)
                printf("%d found at %d\n", x, p + 1);
            else
                printf("%d not found\n", x);
        }
    }
    return 0;
}