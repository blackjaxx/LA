#include <cstdio>
int main()
{
    int a, b, c;
    double ave;
    scanf("%d %d %d", &a, &b, &c);
    ave = (a + b + c) / 3.00;
    printf("%.3lf", ave);
    return 0;
}
