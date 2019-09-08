//1-n整数中1出现的次数
//剑指offer第43题
//输入一个整数n，求1-n这n个整数的十进制表示中1出现的次数；例如：12，则1-12中包含1的数字有1.10.11.12，数字1一共出现了5次；

//常规思路：
int NumberOf1Between1AndN(unsigned int n)
{
    int number = 0;

    for (unsigned int i = 0; i <= n; i++)
    {
        number += NumberOf1(i);
        return number;
    }
}

int NumberOf1(unsigned int n) //对于每个数字，判断个位及高位
{
    int number = 0;
    while (n)
    {
        if (n % 10 == 1)
        {
            number++; //判断个位
        }

        n = n / 10; //判断10位
    }

    return number;
}

//此时时间效率为O（n*log（n））
