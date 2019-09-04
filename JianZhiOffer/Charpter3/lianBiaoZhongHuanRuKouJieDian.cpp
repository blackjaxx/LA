//链表中环的入口节点
//剑指offer第23题
//如果一个链表包含环，如何找到环的入口节点

//第一步，确定链表是否包含环
//具体方法定义两个指针，同时从链表的头出发，一个指针一次走两步，一个指针一次走一步，如果走的快的指针追上了走的慢的指针，那么有环
//此题的要求，一定是链表最后一个节点有环，而不是中间几个节点有环，所以一个走一步一个走两步，二者节点之差是每次递减一个的所以最终一定会相遇

struct ListNode
{
    int m_nValue;
    ListNode *m_pNext;
}; //节点定义已经给出

ListNode *MeetingNode(ListNode *pHead)
{
    if (pHead == nullptr)
    {
        return nullptr; //空链表
    }

    ListNode *pSlow = pSlow->m_pNext;
    if (pSlow == nullptr)
    {
        return nullptr;
    }

    ListNode *pFast = pSlow->m_pNext;
    while (pFast != nullptr && pSlow != nullptr)
    {
        if (pFast == pSlow)
        {
            return pFast; //返回这个相遇的节点
        }

        pSlow = pSlow->m_pNext;

        pFast = pFast->m_pNext;

        if (pFast != nullptr)
        {
            pFast = pFast->m_pNext;
        }
    }
    return nullptr;
}

ListNode *EntryNodeOfLoop(ListNode *pHead)
{
    return;
}