//二叉树的镜像
//请完成一个函数，输入一棵二叉树，输出它的镜像

struct BinaryTreeNode
{
    double m_nValue;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;
}; //已给出

//思路：交换根节点两个子树的值，分别交换以子节点为根的子树的值
//递归解决

void MirrowRecursively(BinaryTreeNode *pNode)
{
    if (pNode == nullptr)
    {
        return;
    }
    if (pNode->m_pLeft == nullptr && pNode->m_pRight)
    {
        return; //递归出口
    }

    BinaryTreeNode *pTemp = pNode->m_pLeft;
    pNode->m_pLeft = pNode->m_pRight;
    pNode->m_pRight = pTemp; //交换左右子树

    if (pNode->m_pLeft)
    {
        MirrowRecursively(pNode->m_pLeft); //递归处理问题
    }

    if (pNode->m_pRight)
    {
        MirrowRecursively(pNode->m_pRight);
    }
}