//分数化小数
#include <cstdio>

int main()
{
    int a, b, c, ct = 1;
    while (scanf("%d %d %d", &a, &b, &c) == 3)
    {
        if (a == 0 &&b = 0 &&c = 0)
        {
            break;
        }
        int integer = a / b;
        printf("Case %d: %d.", ct++, integer);
        a %= b;
        int i = 1;
        while (i++ < c)
        {
            a *= 10;
            printf("%d", a / b);
            a %= b;
        }
        a *= 10;
        // 判断最后一位的下一位是否大于5,进行四舍五入
        printf("%d\n", ((a % b) * 10 / b > 5) ? (a / b + 1) : (a / b));
    }
    return 0;
}