//数值的整数次方
//剑指offer16题
//实现函数double Power(double base,int exponent),求base的exponent次方
//不使用库函数且不需要考虑大数问题
#include <cstdio>
#include <math.h>

bool g_InvalidInput = false;

double Power(double base, int exponent)
{
    g_InvalidInput = false;

    if (equal(base, 0.0) && exponent < 0)
    {
        g_InvalidInput = true; // 如果底数为0 且 指数小于0
        return 0.0;            //数学计算中没有意义，排除结果
    }

    unsigned int absExponent = (unsigned int)(exponent);
    if (exponent < 0)
    {
        absExponent = (unsigned int)(-exponent); //指数小于零 先求个绝对值
    }

    double result = PowerWithUnsignedExponent(base, absExponent);
    if (exponent < 0)
    {
        result = 1.0 / result; //指数小于零 先求绝对值再求倒数
    }

    return result;
}

double PowerWithUnsignedExponent(double base, unsigned int exponent) //递归方法求结果 ，如果求base的16次方，那么应该知道base的8次方，递推知道base的4次方，以此类推
{
    if (exponent == 0)
        return 1; //指数0次方结果为1
    if (exponent == 1)
        return base; // 底数的1次方为其本身

    double result = PowerWithUnsignedExponent(base, exponent >> 1); //右移一位除以2
    result *= result;
    if (exponent & 0x1 == 1)
    {
        result *= base; //和1做与运算，能得知是奇次方还是偶次方，奇次方在乘一次base；
    }
    return result;
}