/*
蛇形填数。 在n×n方阵里填入1， 2， …， n×n， 要求填成蛇形。 例如， n＝ 4时方阵为：
10 11 12 1
9 16 13 2
8 15 14 3
7 6 5 4
上面的方阵中， 多余的空格只是为了便于观察规律， 不必严格输出。 n≤8

类比数学中的矩阵， 可以用一个二维数组来储存题目中的方阵。 只需声明一个“int
a[maxn][maxn]”， 就可以获得一个大小为maxn×maxn的方阵。 在声明时， 二维的大小不必相
同， 因此也可以声明int a[30][50]这样的数组， 第一维下标范围是0,1, 2,…,29， 第二维下标范
围是0,1,2,…,49。

可以用“int a[maxn][maxm]”生成一个整型的二维数组， 其中maxn和maxm
不必相等。 这个数组共有maxn×maxm个元素， 分别为a[0][0], a[0][1],…, a[0][maxm-1],
a[1][0],a[1][1],…,a[1][maxm-1],…,a[maxn-1][0],a[maxn-1][1],…, a[maxn-1] [maxm -
1]。

从1开始依次填写。 设“笔”的坐标为（ x,y） ， 则一开始x=0， y=n-1， 即第0行， 第n-1列
（ 行列的范围是0～ n-1， 没有第n列） 。 “笔”的移动轨迹是： 下， 下， 下， 左， 左， 左，
上， 上， 上， 右， 右， 下， 下， 左， 上。 总之， 先是下， 到不能填为止， 然后是左， 接着是
上， 最后是右。 “不能填”是指再走就出界（ 例如4→5） ， 或者再走就要走到以前填过的格子
（ 例如12→13） 。 如果把所有格子初始化为0， 就能很方便地加以判断;

 */

#include <stdio.h>
#include <string.h>

#define maxn 20
int a[maxn][maxn];

int main()
{
    int n, x, y, tot = 0;
    scanf("%d", &n);
    memset(a, 0, sizeof(a));
    tot = a[x = 0][y = n - 1] = 1; //从右上角开始
    while (tot <= n * n)
    {
        while (x + 1 < n && !a[x + 1][y])  //第一行最后一个元素，从上向下
            a[++x][y] = ++tot;             //先判断在移动
        while (y - 1 >= 0 && !a[x][y - 1]) // 从右向左
            a[x][--y] = ++tot;
        while (x - 1 >= 0 && !a[x - 1][y]) //从下到上
            a[--x][y] = ++tot;
        while (y + 1 < n && !a[x][y + 1])
            a[x][++y] = ++tot;
    }
    for (x = 0; x < n; x++) //打印整个矩阵
    {
        for (y = 0; y < n; y++)
            printf("%3d", a[x][y]);
        printf("\n");
    }
    return 0;
}