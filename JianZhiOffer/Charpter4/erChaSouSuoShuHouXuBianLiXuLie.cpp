//二叉搜索树后续遍历序列

//输入一个整数数组，判断该数组是不是某二叉树的后续遍历结果，如果是返回true，否则返回false；输入数组的任意两个数字不相同
//输入{5，7，6，9，11，10，8}，返回true，因为整个数组序列是二叉树后续遍历的结果
//{7，4，6，5}，没有这种序列，因为5是根节点，7，4，6是它的右子树，但是右子树中4比5小，不满足二叉排序树的条件
bool VerifySquenceOfBST(int sequence[], int length)
{
    if (sequence == nullptr || length <= 0)
    {
        return false;
    }
    int root = sequence[length - 1]; // 根节点是数组中最后一个数字

    int i = 0;
    for (; i < length - 1; ++i) //二叉树左子树节点值小于根节点
    {
        if (sequence[i] > root)
        {
            break;
        }
    }

    int j = i;

    for (; j < length - 1; ++j)
    {
        if (sequence[j] < root) //右子节点全都大于根节点
        {
            return false;
        }
    }

    bool left = true; //判断左子树是不是二叉搜索树

    if (i > 0)
    {
        left = VerifySquenceOfBST(sequence, i); //数组做函数参数，传递数组名
    }

    bool right = true;

    if (i < length - 1)
    {
        right = VerifySquenceOfBST(sequence + i, length - i - 1);
    }

    return (left && right);
}

/*
    函数处理复杂的参数，比如数组或结构

    数组做函数参数，传递的是数组名，为了使函数通用，还要传入数组长度

    int sum_arr(int arr[] , int length)  //声明
    int sum_arr(int *arr ,int length) //也可以这样声明，因为参数传递的是地址，所以arr类型必须是指针 int *
    当且仅当用于函数声明的时候，此二者才是相等的

    但是其中的arr并不是数组，是一根指针
    但是在其余用到此函数的部分你可以把它看作是数组

    sum_arr(sequence,length);  //使用函数

    c++中将数组名解释为第一个元素的地址
    sequence == &sequence[0]
    请注意！！！
    对数组名使用sizeof（）将得到整个数组的长度
    将&地址运算符用于数组名时，返回整个数组的地址，返回整个数组的内存块地址

    所以在上题中
    arr[i] == *(ar + i) //值
    &arr[i] == ar + i  //地址
    此式为恒等式

*/
