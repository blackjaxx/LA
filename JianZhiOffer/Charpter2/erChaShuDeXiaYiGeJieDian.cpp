//二叉树的下一个节点
//给定二叉树和其中的一个节点，找出中序遍历的下一个节点；树中节点除了指向左右节点的指针，还有指向父节点的指针
//查找二叉树的下一个节点，分为3种情况
//中序遍历是先访问左子节点，访问根节点，访问右子节点，递归进行
struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;
    BinaryTreeNode *m_pParent; //指向父节点的指针，根节点没有父节点指针
};

BinaryTreeNode *GetNext(BinaryTreeNode *pNode)
{
    if (pNode == nullptr)
    {
        return nullptr;
    }

    BinaryTreeNode *pNext = nullptr; //我要查找的下一个节点先置空
    if (pNode->m_pRight != nullptr)  //如果我输入节点的右子节点不为空
    {
        //有右子树的情况
        BinaryTreeNode *pRight = pNode->m_pRight; //我在定义变量pRight，并将其初始化为输入节点的右子节点
        while (pRight->m_pLeft != nullptr)        //当变量的左子树不空
        {
            pRight = pRight->m_pLeft; //一直向下走到最左子树的底层
        }
        pNext = pRight; //这个最下面节点是我最后要找的下一个节点
    }
    else if (pNode->m_pParent != nullptr) //
    {
        BinaryTreeNode *pCurrent = pNode;
        BinaryTreeNode *pParent = pNode->m_pParent;
        while (pParent != nullptr && pCurrent == pParent->m_pRight)
        {
            pCurrent = pParent;
            pParent = pParent->m_pParent;
        }
    }
}