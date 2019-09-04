//链表是一种动态数据结构

//单向链表的节点定义
struct ListNode
{
    int m_nValue;
    ListNode *m_pNext;
};

//链表末尾添加一个节点
void AddToTail(ListNode **pHead, int value)
{
    ListNode *pNew = new ListNode();
    pNew->m_nValue = value;
    pNew->m_pNext = nullptr;

    if (*pHead == nullptr)
    {
        *pHead = pNew; //链表为空的时候插入节点则为头节点,pHead是指针的指针
    }
    else
    {
        ListNode *pNode = *pHead; //先让节点指向链表头节点

        while (pNode->m_pNext != nullptr)
        {
            pNode = pNode->m_pNext; //找尾节点
        }

        pNode->m_pNext = pNew; //这个尾节点的下一个节点指向插入的节点
    }
}

//删除链表的节点

void RemoveNode(ListNode **pHead, int value)
{
    if (pHead == nullptr || *pHead == nullptr) //???????????
    {
        return;
    }

    ListNode *pToBeDelete = nullptr; //创建一个删除元素的指针
    if ((*pHead)->m_nValue == value) //找到要删除的元素
    {
        pToBeDelete = *pHead;
        *pHead = (*pHead)->m_pNext; //
    }
    else
    {
        ListNode *pNode = *pHead;
        while (pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue != value) //当节点指向下一元素指针不为空，下一元素的值不为空
        {
            pNode = pNode->m_pNext;
        }

        if (pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue == value)
        {
            pToBeDelete = pNode->m_pNext;
            pNode->m_pNext = pNode->m_pNext->m_pNext;
        }
    }
    if (pToBeDelete != nullptr)
    {
        delete pToBeDelete;
        pToBeDelete = nullptr;
    }
}

/*
结构数组：

struct inflable{

    char name[20];
    float volume;
    double price;
};

inflable gifts[100];
cin >> gifts[0].volume;
//定义了结构数组，注意gifts本身是一个数组，而不是结构，所以像gifts.price这种表述是无效的
//数组中存放的是结构对象（inflable类型）
*/