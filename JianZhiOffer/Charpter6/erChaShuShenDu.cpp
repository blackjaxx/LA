//题目一：求二叉树的深度
//输入一棵二叉树的根节点，求该树的深度，从根节点到叶子节点依次经过的节点形成树的一条路径，最长路径为树的深度
struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;
};

//如果树只有一个节点，那么深度为1
//如果有左子树没有右子树，深度是左子树的深度+1，右边同理，如果有左子树和右子树，那么树的深度是其左右子树较大深度+1
//同样递归处理
int TreeDepth(BinaryTreeNode *pRoot)
{
    if (pRoot == nullptr) //空树或者走到了叶子节点，作为递归的出口
    {
        return 0;
    }

    int nLeft = TreeDepth(pRoot->m_pLeft);
    int nRight = TreeDepth(pRoot->m_pRight);

    return (nLeft > nRight) ? (nLeft + 1) : (nRight + 1);
}

//题目二：平衡二叉树
//输入一棵平衡二叉树的根节点，判断该树是不是平衡二叉树，如果二叉树的任意节点左右子树的深度差不超过1，那么它就是一颗平衡二叉树
//此题的方法和上面一样，遍历每个节点的时候调用TreeDepth（）得到左右子树深度，这种方法需要重复遍历节点，效率不高，考录不重复遍历的方法
//使用常规思路的解决办法：

bool IsBalanced(BinaryTreeNode *pRoot)
{
    if (pRoot == nullptr)
    {
        return true;
    }

    int left = TreeDepth(pRoot->m_pLeft);
    int right = TreeDepth(pRoot->m_pRight);
    int diff = right - left;

    if (diff > 1 || diff < -1)
    {
        return false;
    }

    return IsBalanced(pRoot->m_pLeft) && IsBalanced(pRoot->m_pRight); //这里为什么用&&
}

//只需要遍历依次的解法，此时后续遍历用处显现出来
//因为我们用后续遍历方式遍历依次二叉树的每个节点，那么遍历到一个节点之前，我们已经遍历了它的左右子树
//只要遍历每个节点的时候记录它的深度，我们就可以判断每一个节点是不是平衡的

bool IsBalanced_Changed(BinaryTreeNode *pRoot, int *pDepth)
{
    if (pRoot == nullptr)
    {
        *pDepth = 0;
        return true;
    }

    int left, right;
    if (IsBalanced_Changed(pRoot->m_pLeft, &left) && IsBalanced_Changed(pRoot->m_pRight, &right))
    {
        int diff = left - right;
        if (diff <= 1 && diff >= -1)
        {
            *pDepth = 1 + (left > right ? left : right);
            return true;
        }
    }
    return false;
}

//当我们遍历到整个二叉树的根节点的时候就知道它是不是平衡的，并得到当前节点的深度
//因此我们只需要传入二叉树的根节点及一个表示节点深度的整型变量即可
bool IsBalanced_Changed(BinaryTreeNode *pRoot)
{
    int depth = 0;
    return IsBalanced_Changed(pRoot, &depth);
}