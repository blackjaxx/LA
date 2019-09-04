/*

已知鸡和兔的总数量为n， 总腿数为m。 输入n和m， 依次输出鸡的数目和兔的数目。 如
果无解，则输出No answer。

    样例输入：

        14 32

    样例输出：

        12 2

    样例输入：

        10 16

    样例输出：

        No answer

 */
/*

    设鸡有a只， 兔有b只， 则a＋ b＝ n， 2a＋ 4b＝ m， 联立解得a＝ （ 4n－ m） /2， b＝ n－ a。
在什么情况下此解“不算数”呢？ 首先， a和b都是整数； 其次， a和b必须是非负的。 可以通过
下面的程序判断

 */

#include <stdio.h>
int main()
{
    int n, m, a, b;
    scanf("%d%d", &n, &m);

    a = (4 * n - m) / 2;
    b = n - a;

    if (m % 2 == 0 || a < 0 || b < 0)
    {
        printf("No answer\n");
    }
    else
    {
        printf("%d %d\n", a, b);
    }
    return 0;
}