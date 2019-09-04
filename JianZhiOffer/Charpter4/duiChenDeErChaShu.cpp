//对称的二叉树
//请实现一个函数，用来判断一棵二叉树是不是对称的
//定义一种遍历，先访问根节点，递归访问右子树，递归访问左子树，这样相当于前序遍历的对称遍历，如果两个序列一样，那么此二叉树是对称的
//还有一种情况，那就是二叉树节点元素全一样，这种可以在考虑其节点的空指针，遍历出叶子节点的下一层，即可解决是否对称问题

struct BinaryTreeNode
{
    double m_nValue;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;
}; //已给出

bool isSymmetrical(BinaryTreeNode *pRoot)
{
    return isSymmetrical(pRoot, pRoot);
}

bool isSymmetrical(BinaryTreeNode *pRoot1, BinaryTreeNode *pRoot2)
{
    if (pRoot1 == nullptr && pRoot2 == nullptr)
    {
        return true; //空树，说明对称
    }

    if (pRoot1 == nullptr || pRoot2 == nullptr)
    {
        return false; //有一个不为空，不对称，前面的if说p1且p2都为空，在这个if中p1且p2都为空的条件已经被上面的if覆盖了，执行不到
    }

    if (pRoot1->m_nValue != pRoot2->m_nValue)
    {
        return false; //对称节点值不相等，不是对称的
    }

    return isSymmetrical(pRoot1->m_pLeft, pRoot2->m_pRight) && isSymmetrical(pRoot1->m_pRight, pRoot2->m_pLeft); //递归处理，处理原树的左子节点，对应镜像树的右子节点，反而一样成立
}