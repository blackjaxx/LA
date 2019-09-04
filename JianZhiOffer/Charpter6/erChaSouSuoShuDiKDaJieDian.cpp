//二叉搜索树第K大的节点 （搜索二叉树的中序遍历）
//给定一颗搜索二叉树，请找出其中第K大的节点
//如果中序遍历一颗二叉搜索树，那么节点是递增排序的
//二叉搜索树的特点是 左子节点 < 根节点 < 右子节点 访问的时候递归访问左子树，访问根节点，递归访问右子树，所以遍历后是递增序列

struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;
};

BinaryTreeNode *KthNode(BinaryTreeNode *pRoot, unsigned int k)
{
    if (pRoot == nullptr || k == 0)
    {
        return nullptr;
    }

    return KthNodeCore(pRoot, k); //判断不为空且节点不为0后
}

BinaryTreeNode *KthNodeCore(BinaryTreeNode *pRoot, unsigned int &k)
{
    BinaryTreeNode *target = nullptr;

    if (pRoot->m_pLeft != nullptr)
    {
        target = KthNodeCore(pRoot->m_pLeft, k);
    }

    if (target == nullptr)
    {
        if (k == 1)
        {
            target = pRoot;
        }

        k--;
    }

    if (target == nullptr && pRoot->m_pRight != nullptr)
    {
        target = KthNodeCore(pRoot->m_pRight, k);
    }
    return target;
}