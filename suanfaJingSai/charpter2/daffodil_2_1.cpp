#include <cstdio>
int main()
{
    int hun, ten, ind, i;

    for (i = 100; i < 1000; i++)
    {
        hun = i / 100;
        ten = (i - hun * 100) / 10;
        ind = i % 10;
        if (i == hun * hun * hun + ten * ten * ten + ind * ind * ind) /*各位上的立方和是否与原数n相等*/
            printf("%d  ", i);
    }
    printf("\n");

    return 0;
}