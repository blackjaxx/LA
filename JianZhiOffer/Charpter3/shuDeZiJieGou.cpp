//树的子结构
//剑指offer第26题
//输入两棵二叉树A,B，判断B是不是A的子结构
//给出二叉树节点定义
struct BinaryTreeNode
{
    double m_dbValue;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;
};

//分为两步解题，第一步在A中找到与B根节点值一样的节点，树的遍历，有两种方法，可以用递归，也可以用循环的方法

bool HasSubtree(BinaryTreeNode *pRoot1, BinaryTreeNode *pRoot2)
{
    bool result = false;

    if (pRoot1 != nullptr && pRoot2 != nullptr)
    {
        if (Equal(pRoot1->m_dbValue, pRoot2->m_dbValue))
        {
            result = DoesTree1HaveTree2(pRoot1, pRoot2);
        }
        if (!result)
        {
            result = HasSubtree(pRoot1->m_pLeft, pRoot2);
        }
        if (!result)
        {
            result = HasSubtree(pRoot1->m_pRight, pRoot2);
        }
    }
    return result;
}

bool Equal(double num1, double num2) //比较根节点值是不是相等
{
    if ((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001)) //这里注意 double变量在计算机内表示小数时有误差，所以判断二者差值在很小一范围内，二者就相等
    {
        return true; //切记这里不能用pRoot1->m_dbValue == pRoot2->m_dbValue
    }
    else
    {
        return false;
    }
}

bool DoesTree1HaveTree2(BinaryTreeNode *pRoot1, BinaryTreeNode *pRoot2)
{
    if (pRoot1 == nullptr)
    {
        return false; //主树走空了，那么说明B不是A子树
    }

    if (pRoot2 == nullptr)
    {
        return true; // B树走空了，且下面的if条件时满足的，因为时递归求值，说明了B和A的节点一直相等的，这条语句也是个递归语句
    }

    if (!Equal(pRoot1->m_dbValue, pRoot2->m_dbValue))
    {
        return false; //这里如果执行到了p1和p2不相等，那么就说明B不是A的子树
    }

    return DoesTree1HaveTree2(pRoot1->m_pLeft, pRoot2->m_pRight) && DoesTree1HaveTree2(pRoot1->m_pRight, pRoot2->m_pRight);
}
