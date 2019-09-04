#include <cstdio>
int main()
{
    int n, sum;
    scanf("%d", &n);
    sum = 95 * n;
    if (sum >= 300)
    {
        sum = sum * 0.85;
    }
    printf("%d", sum);
    return 0;
}