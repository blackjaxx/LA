/*

输入底面半径r和高h， 输出圆柱体的表面积， 保留3位小数， 格式见样例。
样例输入：
3.5 9
样例输出：
Area = 274.889

 */

#include <stdio.h>
#include <math.h>

int main()
{
    double r, h, area;
    const double pi = acos(-1.0); //  acos()
    scanf("%lf%lf", &r, &h);      //lf
    area = 2 * pi * r * r + pi * r * h;
    printf("Area = %.3f\n", area);
    return 0;
}