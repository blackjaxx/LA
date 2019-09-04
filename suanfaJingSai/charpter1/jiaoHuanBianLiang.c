/*

输入两个整数a和b， 交换二者的值， 然后输出。
样例输入：
824 16
样例输出：
16 824

 */

#include <stdio.h>
int main()
{
    int a, b, t;
    scanf("%d%d", &a, &b);
    t = a;
    a = b;
    b = t;
    printf("%d %d\n", a, b);
    return 0;
}

/*
不借助中间变量

#include<stdio.h>
int main()
{
    int a, b;
    scanf("%d%d", &a, &b);a = a + b;
    b = a - b;
    a = a - b;
    printf("%d %d\n", a, b);
    return 0;
}


在顺序结构程序中， 程序一条一条依次执行。 为了避免值和变量名混淆， 假定用户输入
的是a0和b0， 因此scanf语句执行完后a=a0， b=b0。
执行完a=a+b后： a=a0+b0， b=b0。
执行完b=a-b后： a=a0+b0， b=a0。
执行完a=a-b后： a=b0， b=a0。
这样， 就不难理解两个变量是如何交换的了。

 */