//链表
#include <malloc.h>
#define NULL 0

typedef struct LNode *List;
#define MAXSIZE 1000 //预定义
struct LNode
{
    ElementType Data[MAXSIZE];
    List next;
};

struct LNode L;
List PtrL;

//求表长
int Length(List PtrL)
{
    List p = PtrL; //指向第一个节点
    int j = 0;
    while (p)
    {
        p = p->next;
        p++;
    }
    return j;
}

//查找第K个元素
List findKth(List PtrL, int k)
{
    List p = PtrL; //无论下面什么操作 都要将链表先指向头在继续操作

    int i = 1;
    while (p != NULL && i < k)
    {
        p = p->next;
        i++;
    }

    if (i == k)
    {
        return p;
    }
    else
    {
        return NULL;
    }
}

//按值查找
List find(ElementType x, List PtrL)
{
    List p = PtrL;

    while (p != NULL && p->Data != x)
    {
        p = p->next;
    }
    return p;
}

//插入
//1.先构造一个新节点用s指向
//2.在找到链表第i-1个节点，用p指向
//3.然后修改指针插入节点

List Insert(ElementType x, int i, List PtrL)
{
    List p, s;
    if (i == 1)
    {
        s = (List)malloc(sizeof(struct LNode));
        //插在链表头上
        (s->Data) = x;
        s->next = PtrL;
        return s;
    }
    p = findKth(i - 1, PtrL);
    if (p == NULL)
    {
        return NULL;
    }
    else
    {
        s = (List)malloc(sizeof(struct LNode)); //开辟临时节点 并让s指向p的下一个节点；
        s->Data = x;
        s->next = p->next;
        p->next = s; //再把原来p节点的下一个节点指向指向s，这样就成功插入了s节点；
        return PtrL;
    }
}

//删除第i个节点
//1.找到链表的第i-1个节点，用p指向
//2.再用指针s指向要被删除的节点（p的下一个节点）
//3.修改指针，删除s所指节点
//4.释放s节点的空间
List Delete(int i, List PtrL)
{
    List p, s;
    if (i == 1) //若删除的节点是链表的第一个节点
    {
        s = PtrL;
        if (PtrL != NUll)
            PtrL = PtrL->next;
        else
            return NULL;
        free(s);
        return PtrL;
    }
    p = findKth(i - 1, PtrL); //查找第i-1个节点
    if (p == NULL)
    {
        return NULL;
    }
    else if (p->next == NULL)
    {
        return NULL;
    }
    else
    {
        s = p->next;
        s->next = p->next;
        free(s);
        return PtrL;
    }
}