//调整数组顺序使得奇数位于偶数前面
//输入一个整数数组，实现一个函数使得该整数中数字的顺序，使得所有的奇数位于数字的前半部分，偶数位于数组的后半部分
//剑指offer第21题

//常规想法是从前向后遍历，当碰到偶数就将其挪到数组的最后一位，这位数字后边的数字都向前挪动一位
//时间复杂度是O(N*2)，这种解法可行但是效率不够

//使用两根指针，第一根指向第一个数字，只从前向后移动，另一个指向最后一个数字，只从后向前移动
//当两根指针相遇之前，第一根指针一定位于第二根之前，当第一根指针指向偶数，第二根指向奇数，那么交换这两个数字

void ReorderOddEven(int *pData, unsigned int length)
{
    if (pData == nullptr || length == 0)
    {
        return;
    }

    int *pBegin = pData;
    int *pEnd = pData + length - 1;

    while (pBegin < pEnd)
    {
        while (pBegin < pEnd && (*pBegin & 0x1) != 0)
        {
            pBegin++; //向后移动pBegin直到它指向偶数
        }

        while (pBegin < pEnd && (*pBegin & 0x1) == 0)
        {
            pEnd--; //向前移动pEnd直到它指向奇数
        }

        if (pBegin < pEnd) //交换值
        {
            int temp = *pBegin;
            *pBegin = *pEnd;
            *pEnd = temp;
        }
    }
}

//如果我解决一类问题，比如把数组的大小分为两部分，非负数在负数的后边，或者能被3整除的放在前边，不能被整除的放在后边
//这一类类似的问题，如何提高代码重用性！！！！！！！！！
//此时用到了解耦思想
//分解为几部分，一部分是大框架，和上面程序一样不用动，剩下一部分是拆分数组的操作，另一部分是判断数字在前面还是后面的标准

void Reorder(int *pData, unsigned int length, bool (*func)(int))
{
    if (pData == nullptr || length == 0)
    {
        return;
    }
    int *pBegin = pData;
    int *pEnd = pData + length - 1;

    while (pBegin < pEnd)
    {
        while (pBegin < pEnd && !func(*pBegin))
        {
            pBegin++; //向后移动pBegin直到它指向偶数
        }

        while (pBegin < pEnd && func(*pEnd)) //把判断标准变为一个函数指针，用一个单独函数判断是否符合标准
        {
            pEnd--; //向前移动pEnd直到它指向奇数
        }

        if (pBegin < pEnd) //交换值
        {
            int temp = *pBegin;
            *pBegin = *pEnd;
            *pEnd = temp;
        }
    }
}

bool isEven(int n) //函数具体判断标准！！！
{
    return (n & 1) == 0;
}

void ReorderOddEven_Change(int *pData, unsigned int length)
{
    Reorder(pData, length, isEven); //注意这个调用，用到了函数指针
    //如果满足前边所述，负数移动到正数前面，或能被3整除或不能整除的，那么仅需要修改修改isEven，其余地方不用动，这样提升了代码的复用性
}