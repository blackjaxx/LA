//实现一个函数，输入一个整数，输出其二进制1的个数；
//常规解法

int NumberOf1(int n)
{
    int count = 0;
    unsigned int flag = 1;
    while (flag)
    {
        if (n & flag)
            count++;

        flag = flag << 1;
    }
}
//如32位整数需要循环32次，时间复杂度高，下面提供更好的解法；

int NumberOf1_2(int n)
{
    int count = 0;

    while (n)
    {
        ++count;
        n = (n - 1) & n;
    }

    return count;
}