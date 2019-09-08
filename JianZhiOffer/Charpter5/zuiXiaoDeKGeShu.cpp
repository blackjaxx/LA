//最小的K个数
//剑指offer第40题
//输入n个整数，找出其中最小的k个数
//例：4，5，1，6，2，7，3，8，则最小的4个数字是1，2，3，4；

//最简单的想法把输入的整数k进行排序，排序之后位于最前面k个数就是最小的k个数，时间复杂度位O（nlogn）

//有一种解决办法，基于数组第k个数字进行调整，比k个数字大的数字都位于数组的右边，比k个数字小的数字都位于左边（不一定是排序的）

void GetLeastNumbers(int *input, int n, int *output, int k)
{
    if (input == nullptr || output == nullptr || k > n || n <= 0 || k <= 0)
    {
        return;
    }

    int start = 0;
    int end = n - 1;
    int index = Partition(input, n, start, end);
    while (index != k - 1)
    {
        if (index > k - 1) //基于第k个数字进行调整
        {
            end = index - 1;
            index = Partition(input, n, start, end);
        }
        else
        {
            start = index + 1;
            index = Partition(input, n, start, end);
        }
    }
    for (int i = 0; i < k; i++)
    {
        output[i] = input[i];
    }
}

int Partition(int data[], int length, int start, int end)
{
    return 0; //具体参考快速排序代码，第二章；
}

//如果不允许修改数组，那么需要采用其他方法
//时间复杂度为O（nlogk）的算法，适合处理海量数据
