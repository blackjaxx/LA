//求链表倒数第k个节点
//面试题22
//输入一个链表，输出链表倒数第k个节点，注意本题从1开始计数，即链表尾节点是倒数第一个节点
struct ListNode
{
    int m_nValue;
    ListNode *m_pNext;
}; //节点定义已经给出

//一种思路是从前向后遍历，再从尾巴向前回溯K步，但是本体中是单链表，没有指向前一节点的指针

//如果整个链表有n个节点，那么倒数第k个节点就是正数第n-k+1个节点
//此时我可以遍历链表一次，看看一共有多少个节点n
//第二次遍历就能找到第n-k+1个节点

//但是有有一种办法，只要遍历一次链表即可
//设置两根指针，一根指向头，另一根指向正数第k-1个节点，当第二个指针走到末尾的时候，从头走的那根指针正好走到第n-k+1个位置

//会造成程序崩溃的几种情况
//1.输入的pListHead是空指针
//2.以pListHead为头节点的链表节点数少于k，由于for循环中走k-1步，还是会崩溃
//3.输入k的参数是0，因为k是unsigned int 所以k-1是（0xFFFFFFFF），for循环仍然会崩溃

ListNode *FindKThToTail(ListNode *pListHead, unsigned int k)
{
    if (pListHead == nullptr || k == 0)
    {
        return nullptr; //解决情况1，3
    }

    ListNode *pAhead = pListHead; //右边指针
    ListNode *pBehind = nullptr;

    for (unsigned int i = 0; i < k - 1; ++i)
    {
        if (pAhead->m_pNext != nullptr) //解决情况2
        {
            pAhead = pAhead->m_pNext;
        }
        else
        {
            return nullptr; //解决情况2
        }
    }

    pBehind = pListHead;               //左边指针
    while (pAhead->m_pNext != nullptr) //右边指针没有走到末尾
    {
        pAhead = pAhead->m_pNext;
        pBehind = pBehind->m_pNext;
    }
    return pBehind;
}

//同理变形题，如果求链表中点节点
//那么可以设置两个指针，一个走的速度是另一个二倍