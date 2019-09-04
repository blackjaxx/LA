//删除链表节点
//在O(1)时间内删除链表的节点，给定一个链表的头指针和节点指针
//链表节点定义如下

struct ListNode
{
    int m_nValue;
    ListNode *m_pNext;
};
void DeleteNode(ListNode **pListHead, ListNode *pToBeDeleted);

//为什么能在O（1）时间内删除节点，链表的删除元素时间复杂度是O（n），因为节点已经给出
//常规删除方法是从头遍历至第（n-1）节点，在将其指针移动至要删除节点指针的next指向，
//此题已经给出要删除的节点，只需将其后边节点覆盖此节点值，再将复制了值的节点的next指针指向删除节点的next，删除节点，即在O（1）时间内完成
//注意特殊情况，一种是只有一头节点，删除之后将其置为nullptr
//另一种是删除尾节点，尾节点没有下一节点，所以只能常规从头顺序查找

void DeleteNode(ListNode **pListHead, ListNode *pToBeDeleted)
{
    if (!pListHead || !pToBeDeleted)
    {
        return;
    }
    if (pToBeDeleted->m_pNext != nullptr) //要删除不是尾节点
    {
        ListNode *pNext = pToBeDeleted->m_pNext;
        pToBeDeleted->m_nValue = pNext->m_nValue;
        pToBeDeleted->m_pNext = pNext->m_pNext;

        delete pNext;
        pNext = nullptr;
    }

    else if (*pListHead == pToBeDeleted) //只有一个节点
    {
        delete pToBeDeleted;
        pToBeDeleted = nullptr;
        *pListHead = nullptr; //头节点也要置空
    }
    else //链表中有多个节点，删除尾节点
    {
        ListNode *pNode = *pListHead;
        while (pNode->m_pNext != pToBeDeleted)
        {
            pNode = pNode->m_pNext; //尾节点没有下一节点，只能从头顺序查找
        }

        pNode->m_pNext = nullptr;
        delete pToBeDeleted;
        pToBeDeleted = nullptr;
    }
}

//以上代码基于一个假设，要删除的节点确实在链表中，我们需要O（n）时间才能确定判断链表是否包含某一节点，受到O（1）时间限制