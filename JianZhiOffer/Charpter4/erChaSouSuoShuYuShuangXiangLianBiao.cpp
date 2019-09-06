//二叉搜索树和双向链表
//剑指offer第36题
//输入一颗二叉搜索树，将二叉搜索树转换成一个排序的双向链表，不能创建新节点，仅能调节树中节点的指向

struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;
};
//二叉搜索树即中序遍历节点元素是排序的，那么除叶节点外，每个节点都有指向左右子节点的两根指针
//而双向链表的特点是有指向前一节点的指针和后一节点的指针
//考虑如何转换，先遍历左子树，当遍历至根节点时，左子树已经有序，此时将左子树最大值指向根节点，根节点连接左子树最大值节点
//同理，右子树最小值节点与根节点连接，此时有序
//递归处理

BinaryTreeNode *Convert(BinaryTreeNode *pRootOfTree)
{
    BinaryTreeNode *pLastNodeInList = nullptr;
    ConvertNode(pRootOfTree, &pLastNodeInList);

    //pLastNodeInList指向双向链表的尾节点
    //我们需要返回头节点
    BinaryTreeNode *pHeadOfList = pLastNodeInList;
    while (pHeadOfList != nullptr && pHeadOfList->m_pLeft != nullptr)
    {
        pHeadOfList = pHeadOfList->m_pLeft;
    }
    return pHeadOfList;
}

void ConvertNode(BinaryTreeNode *pNode, BinaryTreeNode **pLastNodeInList) //不断将pLastNodeInList作为参数传入函数，它是不断变长的始终指向排好序链表的尾部
{
    if (pNode == nullptr)
    {
        return;
    }

    BinaryTreeNode *pCurrent = pNode;

    if (pCurrent->m_pLeft != nullptr)
    {
        ConvertNode(pCurrent->m_pLeft, pLastNodeInList);
    }

    pCurrent->m_pLeft = *pLastNodeInList;
    if (*pLastNodeInList != nullptr)
    {
        (*pLastNodeInList)->m_pRight = pCurrent;
    }

    *pLastNodeInList = pCurrent;

    if (pCurrent->m_pRight != nullptr)
    {
        ConvertNode(pCurrent->m_pRight, pLastNodeInList);
    }
}