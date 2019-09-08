//数字序列中的某一位数字
//剑指offer第44题
//数字以01234567891011121314...格式序列化到一个字符串序列中；这个序列中，第5位是5，第13位是1，第19位是4，请写一函数，求第n位对应数字；

//序列中前10位数字是0-9，这10个只有一位的数字
//接下来是10-99，两位数一共占180位数字
//接下来是100-999，一共占2700位数字
//例求1001位数字是什么，那么1001-（10+180）=881位
//881 < 2700说明在三位数中
//881 = 270 *3 +1
//即371
#include <cmath>

int digitAtIndex(int index)
{
    if (index < 0)
    {
        return -1;
    }

    int digits = 1;
    while (true)
    {
        int numbers = CountOfIntegers(digits);
        if (index < numbers * digits)
        {
            return digitAtIndex(index, digits);
        }
        index -= digits * numbers;
        digits++;
    }
    return -1;
}

//得到m位数字共多少个
int CountOfIntegers(int digits)
{
    if (digits == 1)
    {
        return 10;
    }
    int count = (int)(pow(10, digits - 1)); //两位数一共90个数，三位数900个数
    return 9 * count;
}

//当我们知道找的那一位数字位于m位数之中后，可以用如下函数找出那位数字
int digitAtIndex(int index, int digits)
{
    int number = beginNumber(digits) + index / digits;
    int indexFromRight = digits - index % digits;
    for (int i = 1; i < indexFromRight; ++i)
    {
        number /= 10;
    }
    return number % 10;
}

//需要知道m位数的第一个数字，第一个二位数是10，第一个三位数是100
int beginNumber(int digits)
{
    if (digits == 1)
    {
        return 0;
    }

    return (int)pow(10, digits - 1);
}