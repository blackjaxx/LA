//合并两个排序链表
//输入两个递增排序的链表，合并这两个链表并使新链表的节点仍然是递增排序的

struct ListNode
{
    int m_nValue;
    ListNode *m_pNext;
}; //节点定义已经给出

//注意问题，输入的第一个链表是空链表，或第二个链表是空链表，或者1，2，都是空链表

//递归处理问题,因为处理完任意链表中的节点，剩下的链表仍然是排序的，合并过程一样

ListNode *Merge(ListNode *pHead1, ListNode *pHead2)
{
    if (pHead1 == nullptr)
    {
        return pHead2;
    }
    else if (pHead2 == nullptr)
    {
        return pHead1;
    }

    ListNode *pMergeHead = nullptr;

    if (pHead1->m_nValue < pHead2->m_nValue)
    {
        pMergeHead = pHead1;
        pMergeHead->m_pNext = Merge(pHead1->m_pNext, pHead2);
    }
    else
    {
        pMergeHead = pHead2;
        pMergeHead->m_pNext = Merge(pHead1, pHead2->m_pNext);
    }
    return pMergeHead;
}