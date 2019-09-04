//斐波那契数列
//求斐波那契数列的第N项
//写一个函数，已经给出了斐波那契数列公式；
/*

if(n<=0){
    f(n)=0;
}
else if(n=1)
{
    f(n)=1;
}
else
{
    f(n) = f(n-1) + f(n -2);
}

*/

//教科书的解法
long long Fibonacci(unsigned int n)
{
    if (n <= 0)
    {
        return 0;
    }

    if (n == 1)
    {
        return 1;
    }

    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

//改进后做法防止重复计算
//核心想法时递推 使用循环和额外变量表示递归，从底向上，而不是从上到下，时间复杂度O（n）
long long Fibonacci_Advance(unsigned n)
{
    int result[2] = {0, 1}; //当n = 0 || n = 1的情况
    if (n < 2)
    {
        return result[n]; //当n = 0返回0，n = 1返回 1
    }

    long long fibNMinusOne = 1;
    long long fibNMinusTwo = 0;
    long long fibN = 0; //此项为我们所求的 f(n)
    for (unsigned int i = 2; i < n; i++)
    {
        fibN = fibNMinusOne + fibNMinusTwo;

        fibNMinusTwo = fibNMinusOne; // 想象为两根指针fibone指向后边元素，fibtwo指向前面元素
        fibNMinusOne = fibN;         //累加和
    }
    return fibN;
}

//引申问题，青蛙跳台阶