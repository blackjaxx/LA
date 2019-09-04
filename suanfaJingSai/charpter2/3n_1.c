/*
对于任意大于1的自然数n， 若n为奇数， 则将n变为3n＋ 1， 否则变为n的一半。
经过若干次这样的变换， 一定会使n变为1。 例如， 3→10→5→16→8→4→2→1

输入n， 输出变换的次数。 n≤109;

样例输入：

3 

样例输出：

7
 */

/*

不难发现， 程序完成的工作依然是重复性的： 要么乘3加1， 要么除以2， 但和2.1节的程
序又不太一样： 循环的次数是不确定的， 而且n也不是“递增”式的循环。 这样的情况很适合
用while循环来实现;

 */

#include <stdio.h>
int main()
{
    int n, count = 0;
    scanf("%d", &n);
    while (n > 1)
    {
        if (n % 2 == 1)
            n = n * 3 + 1;
        else
            n /= 2;
        count++;
    }
    printf("%d\n", count);
    return 0;
}

//使用long数据类型防止溢出；
#include <stdio.h>
int main()
{
    int n2, count = 0;
    scanf("%d", &n2);
    long long n = n2;
    while (n > 1)
    {
        if (n % 2 == 1)
            n = n * 3 + 1;
        else
            n /= 2;
        count++;
    }
    printf("%d\n", count);
    return 0;
}