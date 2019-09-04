/*

 有n盏灯， 编号为1～ n。 第1个人把所有灯打开， 第2个人按下所有编号为2
的倍数的开关（ 这些灯将被关掉） ， 第3个人按下所有编号为3的倍数的开关（ 其中关掉的灯
将被打开， 开着的灯将被关闭） ， 依此类推。 一共有k个人， 问最后有哪些灯开着？ 输
入n和k， 输出开着的灯的编号。 k≤n≤1000。

样例输入：

7 3

样例输出：

1 5 6 7

 */

/*
用a[1]， a[2]， …， a[n]表示编号为1， 2， 3， …， n的灯是否开着。 模拟这些操作即可;
 */

#include <stdio.h>
#include <string.h>
#define maxn 1010

int a[maxn];

int main()
{
    int n, k, first = 1;     //n盏灯,k个人
    memset(a, 0, sizeof(a)); //初始化数组中全部元素为0；
    scanf("%d%d", &n, &k);

    for (int i = 1; i <= k; i++)     //k个人；
        for (int j = 1; j <= n; j++) //n盏灯；
            if (j % i == 0)
                a[j] = !a[j]; //类推 开关灯动作；
    for (int i = 1; i <= n; i++)
        if (a[i]) //light on
        {
            if (first)
                first = 0; //这样第一个元素first变为0了,后边元素都是0，则if跳过，直接执行输出一空格！！！
            else
                printf(" ");
            printf("%d", i); //为了避免输出
            //多余空格， 设置了一个标志变量first， 可以表示当前要输出的变量是否为第一个。
            //第一个变量前不应有空格， 但其他变量都有!!!!!!
        }
    printf("\n");
    return 0;
}