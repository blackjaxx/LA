//把一个有序数组的最开始诺干元素搬到数组的末尾，称之为数组的旋转，求出旋转后数组的最小元素
//如{3,4,5,1,2}是{1,2,3,4,5}的一个旋转

//从头到尾遍历数组一次，能找到这个最小元素，但是时间复杂度为O(n),没有利用旋转数组的特性
//我们注意到数组旋转之后部分元素还是有序的，所以利用二分查找法速度更快；

int Min(int *numbers, int length)
{
    if (numbers == nullptr || length <= 0)
    {
        throw exception("Invid Parameters"); //输入边界排除
    }
    int index1 = 0;                            //设为数组的第一个元素
    int index2 = length - 1;                   //数组的最后一个元素
    int indexMid = index1;                     //mid首先设置为首元素
    while (numbers[index1] >= numbers[index2]) //如果while不成立，说明数组本身就是有序数组，也就不需要二分查找了，第一个元素就是最小元素
    {
        if (index2 - index1 == 1)
        {
            indexMid = index2; //二个指针之差为1，说明最小元素是index2，因为index1是有序数组的最后一个元素
            break;
        }

        indexMid = (index1 + index2) / 2;
        if (numbers[indexMid] >= numbers[index1])
        {
            index1 = indexMid; //如果我中间的元素比左边元素大，说明我最小的元素在右半边有序数组中，所以将mid设置为左边index1，重新进行二分
        }
        else if (numbers[indexMid] <= numbers[index2])
        {
            index2 = indexMid;
        }
    }
    return numbers[indexMid];
}

//但是有特例的情况
//数组{0，1，1，1，1}，当出现变形{1，0，1，1，1}和{1，1，1，0，1}的时候
//也满足题中的条件但是此时index1，indexMid,index2都是1，无法继续使用二分法，此时只能顺序查找

int Min_Change(int *numbers, int length)
{
    if (numbers == nullptr || length <= 0)
    {
        throw exception("Invid Parameters"); //输入边界排除
    }
    int index1 = 0;                            //设为数组的第一个元素
    int index2 = length - 1;                   //数组的最后一个元素
    int indexMid = index1;                     //mid首先设置为首元素
    while (numbers[index1] >= numbers[index2]) //如果while不成立，说明数组本身就是有序数组，也就不需要二分查找了，第一个元素就是最小元素
    {
        if (index2 - index1 == 1)
        {
            indexMid = index2; //二个指针之差为1，说明最小元素是index2，因为index1是有序数组的最后一个元素
            break;
        }

        indexMid = (index1 + index2) / 2;
        if (numbers[index1] == numbers[index2] && numbers[indexMid] == numbers[index1])
        {
            return MinInOrder(numbers, index1, index2);
        }

        if (numbers[indexMid] >= numbers[index1])
        {
            index1 = indexMid; //如果我中间的元素比左边元素大，说明我最小的元素在右半边有序数组中，所以将mid设置为左边index1，重新进行二分
        }
        else if (numbers[indexMid] <= numbers[index2])
        {
            index2 = indexMid;
        }
    }
    return numbers[indexMid];
}

int MinInOrder(int *numbers, int index1, int index2)
{
    int result = numbers[index1];
    for (int i = index1 + 1; i <= index2; ++i)
    {
        if (result > numbers[i])
        {
            result = numbers[i];
        }
    }
    return result;
}