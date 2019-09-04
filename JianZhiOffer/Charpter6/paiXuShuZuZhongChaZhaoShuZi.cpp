//剑指offer第53题
//三道题目

//题目一：数字在排序数组中出现的次数
//统计一个数字在排序数组中出现的次数，输入数组{1，2，3，3，3，3，4，5}和数字3，数字3出现了4次，输出4；

//常规想法，使用二分查找，找到一个3，顺序查找3的左右两边，找到第一个3和最后一个3
//时间复杂度是O（n），可以优化

//换一种思路，二分定位，找到一个K，把找到的K值和输入的值比较大小，能确定目标元素在左半边还是右半边
//如果K正好等于输入元素，那么看这个K是不是目标值的左边界第一个元素，如果中间数字前面一个数字不是K，那么这个K正好是第一个目标元素
//否则，查找左半边，递归

int GetFirstK(int *data, int length, int k, int start, int end)
{
    if (start > end)
    {
        return -1; //返回 -1
    }

    int middleIndex = (start + end) / 2;
    int middleData = data[middleIndex];
    if (middleData == k)
    {
        if ((middleIndex > 0 && data[middleIndex - 1] != k) || middleIndex == 0)
        {
            return middleIndex; //数组中间元素的前一个元素不是K，说明middleIndex的值是第一个K值，返回其下标
        }
        else
        {
            end = middleIndex - 1; //如果是K，把end变为middleIndex前一个值，看看在和K比较
        }
    }

    else if (middleData > k) //说明所求的值在左半边
    {
        end = middleIndex - 1;
    }

    else //在右半边
    {
        start = middleIndex + 1;
    }

    return GetFirstK(data, length, k, start, end); //递归处理
}

//同样思路找到最后一个K

int GetLastK(int *data, int length, int k, int start, int end)
{
    if (start > end)
    {
        return -1; //返回 -1
    }

    int middleIndex = (start + end) / 2;
    int middleData = data[middleIndex];
    if (middleData == k)
    {
        if (middleIndex < length - 1 && data[middleIndex + 1] != k)
        {
            return middleIndex; //数组中间元素的后一个元素不是K，说明middleIndex的值是第一个K值，返回其下标
        }
        else
        {
            start = middleIndex + 1; //如果是K，把end变为middleIndex后一个值，看看在和K比较
        }
    }

    else if (middleData < k) //说明所求的值在右半边
    {
        start = middleIndex + 1;
    }

    else //在左半边
    {
        end = middleIndex - 1;
    }

    return GetLastK(data, length, k, start, end); //递归处理
}

//合并代码，找到并返回了第一个和最后一个K的下标后，计算K出现的次数

int GetNumberOfK(int *data, int length, int k)
{
    int number = 0;

    if (data != nullptr && length > 0)
    {
        int first = GetFirstK(data, length, k, 0, length - 1);
        int last = GetLastK(data, length, k, 0, length - 1);

        if (first > -1 && last > -1)
        {
            number = last - first + 1;
        }

        return number;
    }
}

//时间复杂度 O（log n）

//题目二：0 - n-1中缺失的数字
//一个长度为n-1的递增排序数组中所有数字都是唯一的，每个数字都在0 - n-1范围内，在范围内的n个数字有且只有一个数字不在该数组中，找出这个数字

//本题的关键就是因为0 - n-1 这些数字是排序的，因此数组中开始的一些数字与他们的下标相同，依次类推，当发现不在数组中的那个数字m，那么所有比m小的数字
//下标都与他们本身相同，这样又可以应用到二分查找法

int GetMissingNumber(const int *numbers, int length)
{
    if (numbers == nullptr || length <= 0)
    {
        return -1;
    }

    int left = 0;
    int right = length - 1;

    while (left <= right)
    {
        int middle = (right + left) >> 1;
        if (numbers[middle] != middle)
        {
            if (middle == 0 || numbers[middle - 1] == middle - 1)
            {
                return middle; //说明元素不相等的就在这个位置；
            }
            right = middle - 1; //前一个元素还相等，那说明不相等的元素还在前面，左半部分
        }
        else
        {
            left = middle + 1; //否则在右半部分
        }
    }

    if (left == length)
    {
        return length;
    }

    //无效输入，或者数组不按要求排序，或者有数字不再0 - n-1 范围内
    return -1;
}

//题目三：数组中的数值和下标相等的元素
//单调递增的数组中每个元素都是整数且唯一
//{-3，-1，1，3，5}，数字3和他的下标相等
//使用二分查找法进行优化
//如何快速获取查找范围，假设数字为m，数字的值大于它的下标，由于数组中数字单调且递增，对于任意大于0的k，位于下标i+k的数字值大于或等于m+k
//m + k > i + k   即第i个数字的值大于i右边的值全部忽略，去左半部分查找

int GetNumberSameAsIndex(const int *numbers, int length)
{
    if (numbers == nullptr || length <= 0)
    {
        return -1;
    }

    int left = 0;
    int right = length - 1;
    while (left <= right)
    {
        int middle = left + ((left + right) >> 1);
        if (numbers[middle] == middle)
        {
            return middle;
        }

        if (numbers[middle] > middle)
        {
            right = middle - 1;
        }
        else
        {
            left = middle + 1;
        }
        return -1;
    }
}