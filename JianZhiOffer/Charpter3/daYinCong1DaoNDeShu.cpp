//打印从1到最大的N位数
//输入数字N，顺序打印从1到最大的N位10进制数
//比如输入3，则输出1，2，3，...，999;
//剑指offer第17题

//防止进入陷阱，不能用循环打印数字，不管是long long 或者int 都会超出范围
//需要用数组或字符串模拟大数输出
#include <string.h> // string.h

void PrintToMaxOfNDigits(int n)
{
    if (n <= 0)
    {
        return;
    }

    char *number = new char[n + 1]; //开辟空间
    memset(number, '0', n);         //重置元素
    number[n] = '\0';

    while (!Increment(number))
    {
        PrintNumber(number);
    }

    delete[] number;
}

bool Increment(char *number)
{
    //此函数如何设计，注意到只有对最大数比如999+1的时候，第一个字符会产生进位，此时返回true， while循环终止  O(1)
    bool isOverFlow = false; //标志位是否溢出
    int nTakeOver = 0;
    int nLength = strlen(number);
    for (int i = nLength - 1; i > 0; i--)
    {
        int nSum = number[i] - '0' + nTakeOver;
        if (i == nLength - 1)
        {
            nSum++;
        }
        if (nSum >= 10)
        {
            if (i == 0)
            {
                isOverFlow = true;
            }
            else
            {
                nSum -= 10;
                nTakeOver = 1;
                number[i] = '0' + nSum;
            }
        }
        else
        {
            number[i] = '0' + nSum;
            break;
        }
    }
    return isOverFlow;
}

void PrintNumber(char *number)
{
}