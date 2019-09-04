//复杂链表的复制
//剑指offer第35题
//请实现函数ComplexListNode *Clone(ComplexListNode *pHead),
//复制一个复杂链表，此链表节点除了有一个m_pNext指针指向下一个节点，还有一个m_pSibling指针指向链表的任意节点过着nullptr

struct ComplexListNode
{
    int m_nValue;
    ComplexListNode *m_pNext;
    ComplexListNode *m_pSibling;
};

ComplexListNode *Clone(ComplexListNode *pHead)