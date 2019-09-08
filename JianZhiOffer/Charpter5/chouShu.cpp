//丑数
//剑指offer第49题
//我们把只包含因子2，3和5的数称作丑数（只包含），求从小到大顺序的第1500个丑数，习惯上我们把1当作第一个丑数
//例如：6，8是但14不是，因为它包含因子7

//第一种解法：逐一判断每个整数是不是丑数的解法
//如果一个数仅能被2，3，5整除，那么连续除以2，3，5，最后得到的是1，那这个数就是丑数，否则不是

//函数判断一个数是不是丑数
bool isUgly(int number)
{
    while (number % 2 == 0)//能整除以2，那么连续除以二除到不能除尽为止
    {
        number /= 2;
    }
    while (number % 3 == 0)
    {
        number /= 3;
    }
    while (number % 5 == 0)
    {
        number /= 5;
    }

    return (number == 1)?true:false;    
}

//接下来，我们只需要按照排序查看每个整数是不是丑数
int GetUglyNumber(int index)
{
    if (index <= 0)
    {
        return 0;
    }
    int number = 0;
    int uglyFound = 0;
    while (uglyFound < index)
    {
        ++number;

        if (isUgly(number))
        {
            ++uglyFound;
        }
    }
    return number;
}

//直观且代码简洁，问题是即使一个数不是丑数，也需要判断，效率不是很高
