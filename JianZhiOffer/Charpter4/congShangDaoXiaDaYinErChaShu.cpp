//从上到下打印二叉树
//不分行从上到下打印二叉树，从上到下打印出二叉树每个节点，同一层按照从左到右顺序打印

struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;
};

//层序遍历，即树的BFS，宽度优先遍历

//分析：先打印根节点，根节点左右子树，遍历到根节点的左右子节点，将其二者插入队列中，当遍历左子节点时，再将左子节点的子树插入队列中，
//此时队列中有根节点的右子节点，和左子节点的子树，依次进行，完成层序打印
#include <deque>
#include <cstdio>

void PrintFromTopToBottom(BinaryTreeNode *pTreeRoot)
{
    if (!pTreeRoot)
    {
        return;
    }

    std::deque<BinaryTreeNode *> dequeTreeNode;

    dequeTreeNode.push_back(pTreeRoot);

    while (dequeTreeNode.size())
    {
        BinaryTreeNode *pNode = dequeTreeNode.front(); //pNode不断变换，始终是队列的头节点
        dequeTreeNode.pop_front();                     //头节点的值弹出

        printf("%d", pNode->m_nValue); //输出值

        if (pNode->m_pLeft) //处理左子树
        {
            dequeTreeNode.push_back(pNode->m_pLeft);
        }

        if (pNode->m_pRight)
        {
            dequeTreeNode.push_back(pNode->m_pRight);
        }
    }
}
