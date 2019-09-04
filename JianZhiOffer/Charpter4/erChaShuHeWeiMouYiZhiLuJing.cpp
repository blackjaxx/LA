//二叉树中和为某一值的路径
//输入一颗二叉树和一整数，打印出二叉树节点值和为输入整数的所有路径，从树的根节点开始，到叶节点，形成一条路径
#include <iostream>
#include <vector>

struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;
}; //已给出

void FindPath(BinaryTreeNode *pRoot, int expectedSum)
{
    if (pRoot == nullptr)
    {
        return;
    }
    std::vector<int> path;
    int currentSum = 0;
    FindPath(pRoot, expectedSum, path, currentSum);
}

void FindPath(BinaryTreeNode *pRoot, int expectedSum, std::vector<int> &path, int currentSum)
{
    currentSum += pRoot->m_nValue;
    path.push_back(pRoot->m_nValue); //currentsum累加了值之后将这个值压入栈中

    //如果是叶节点，且路径上节点和等于输入的值，打印出这条路径
    bool isLeaf = pRoot->m_pLeft == nullptr && pRoot->m_pRight == nullptr;

    if (currentSum == expectedSum && isLeaf)
    {
        printf("A Path is Found");
        std::vector<int>::iterator iter = path.begin();
        for (; iter != path.end(); ++iter)
        {
            printf("%d\t", *iter); //打印出节点值
        }

        printf("\n");
    }
    //不是叶节点，遍历它的子节点
    if (pRoot->m_pLeft != nullptr)
    {
        FindPath(pRoot->m_pLeft, expectedSum, path, currentSum);
    }
    if (pRoot->m_pRight != nullptr)
    {
        FindPath(pRoot->m_pRight, expectedSum, path, currentSum);
    }

    path.pop_back(); //返回父节点前，删除路径上的当前节点
}