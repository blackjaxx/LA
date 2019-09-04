//定义一个函数，输入一个链表的头节点，反转链表并输出反转后链表的头节点
//剑指offer第24题

//注意防止链表反转指针出现断裂情况，需要临时变量将节点保存下来
//因此需要三根指针，一根指向当前遍历到的节点，一根指向它的前一个节点，一个指向后一节点

//什么节点是尾节点，当然是m_pNext为nullptr的节点

//测试用例：
//1.输入链表头指针nullptr
//2.输入的链表只有一个节点
//3.链表有多个节点

struct ListNode
{
    int m_nValue;
    ListNode *m_pNext;
}; //节点定义已经给出

ListNode *ReverseList(ListNode *pHead)
{
    ListNode *pReversedHead = nullptr;
    ListNode *pNode = pHead; //pNode指向链表头
    ListNode *pPrev = nullptr;
    while (pNode != nullptr) //链表不为空，链表为空的话直接返回 pReversedHead = nullptr
    {
        ListNode *pNext = pNode->m_pNext;

        if (pNext == nullptr) //只有一个节点，或者走到了最后一个节点
        {
            pReversedHead = pNode;
        }

        pNode->m_pNext = pPrev; //空置

        pPrev = pNode;
        pNode = pNext; //处理pNode的下一个节点
    }
    return pReversedHead;
}