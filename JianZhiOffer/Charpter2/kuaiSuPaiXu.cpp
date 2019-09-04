//快速排序
#include <iostream>
int Partition(int data[], int length, int start, int end)
{
    if (data == nullptr || length <= 0 || start < 0 || end >= length)
    {
        throw new std::exception("Invid Parameters"); //exception在哪个头文件里？
    }
    int index = RandomInRange(start, end); //随机选取一个值作为基准点
    swap(&data[index], &data[end]);        //把这个选中的值和最后一个元素交换

    int small = start - 1; //
    for (index = start; index < end; ++index)
    {
        if (data[index] < data[end])
        {
            ++small;
            if (small != index)
            {
                swap(&data[index], &data[small]);
            }
        }
    }
    ++small;
    swap(&data[small], &data[end]);

    return small;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int RandomInRange(int start, int end)
{
    int random = rand() % (end - start + 1) + start;
    return random;
}