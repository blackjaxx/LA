//和为s的数字
//输入一个递增排序的数组和数字s，在数组中查找两个数使他们的和为s，如果多对数字的和为s则输出一对即可
//剑指offer第57题

//如果我们先固定一个数字，在剩下的n-1个数字中穷举，那么最后找到和为s的时间复杂度为O（n*2）
//应该注意题中关键字，数组是递增排序的，此式考虑利用数组的特性
//如果我们考虑如下方式，定义两根指针，一根指向数组第一个数字，一根指向最后一个数字，看二者之和sum和我们输入的数字s比较
//如果sum > s说明选择的元素大了，此式后边指针应向前挪动一位
//反之，则前面指针向后挪动一位，继续比较，时间复杂度变为o（n）
#include <iostream>
#include <cstdio>

bool FindNumbersWithSum(int data[], int length, int sum, int *num1, int *num2)
{
    bool found = false;

    if (length <= 1 || num1 == nullptr || num2 == nullptr)
    {
        return found;
    }

    int ahead = length - 1;
    int behind = 0;

    while (behind < ahead)
    {
        long long curSum = data[ahead] + data[behind];

        if (curSum == sum)
        {
            *num1 = data[behind];
            *num2 = data[ahead];
            found = true;
            return;
        }
        if (curSum < sum)
        {
            behind++;
        }
        else
        {
            ahead--;
        }
    }
    return found;
}

//题目变形
//和为s的连续正数序列，打印出所有和为s的连续正数序列（至少含有两个数）。
//如： 1+2+3+4+5 = 4+5+6 = 7+8 = 15
//
void PrintContinuousSequence(int small, int big) //输出序列函数
{
    for (int i = small; i <= big; i++)
    {
        printf("%d", i);
        printf("\n");
    }
}

void FindContinuousSequence(int sum)
{
    if (sum < 3) //题意说最小需要两位数字，那么如果最小是1和2的话最小sum也要3
    {
        return;
    }

    int small = 1;
    int big = 2;
    int middle = (1 + sum) / 2; //连续序列的话，small最大不会超过sum一半的左边那个数，否则不符合题意
    int curSum = small + big;

    while (small < middle)
    {
        if (curSum == sum)
        {
            PrintContinuousSequence(small, big);
        }

        while (small < middle && curSum > sum) //如果下标小于一半的左边那个元素且目前和大于给定的目标和
        {
            curSum -= small;
            small++;

            if (curSum == sum)
            {
                PrintContinuousSequence(small, big);
            }
        }
        //while执行完毕，说明small和big重合了还没有找到合适的序列或者是curSum < sum，此式需要扩充big了
        big++;
        curSum += big;
    }
}