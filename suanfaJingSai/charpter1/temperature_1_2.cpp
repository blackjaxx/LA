#include <cstdio>
int main()
{
    double c, f;
    scanf("%lf", &f);
    c = 5.0 * (f - 32) / 9;
    printf("%.3lf", c);
}