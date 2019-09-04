//线性表定义

#include <malloc.h>

typedef struct LNode *List;
#define MAXSIZE 1000 //预定义
struct LNode
{
    ElementType Data[MAXSIZE];
    int Last;
};

struct LNode L;
List PtrL;

//初始化操作

List MakeEmpty()
{
    List PtrL;
    PtrL = (List)malloc(sizeof(struct LNode)); //开辟空间 注意返回的类型 malloc返回 void * 根据不同指针转换成相应类型 有的编译器需要强制转换
    PtrL->Last = -1;                           //没有元素
    return PtrL;
}

//查找
int find(ElementType x, List PtrL)
{
    int i = 0;
    while (i <= PtrL->Last && PtrL->Data[i] != x)
        i++;

    if (i > PtrL->Last)
        return -1; //没找到
    else
        return i;
}

//插入

void Insert(ElementType x, int i, List PtrL) //插入的元素x 插入的位置 i
{
    //判断表满，用last指针判断
    if (PtrL->Last == MAXSIZE - 1)
        return;

    //检查输入合法性
    if (i < 1 || i > PtrL->Last + 2) //最后还有一个\0
        return;

    for (int j = PtrL->Last; j >= i - 1; j--) //从插入的i的位置后边所有的元素向后挪一位
        PtrL->Data[j + 1] = PtrL->Data[j];

    PtrL->Data[i - 1] = x; //下标从0开始，所以data[i]应写为data[i-1]
    PtrL->Last++;          //last指向最后
    return;
}

//删除
void Delete(List PtrL, int i)
{
    //删除位置的合法性
    if (i < 1 || i > PtrL->Last + 1)
        return;
    for (int j = i; j <= PtrL->Last; j++)
        PtrL->Data[j - 1] = PtrL->Data[j]; //注意数组的下标表示 一定比当前小一位
    PtrL->Last--;
    return;
}