//重建二叉树
//剑指offer第七题
//输入二叉树的前序和中序遍历结果，重建二叉树；假设输入的前序和中序遍历都不含有重复数字
//假设输入节点前序{1,2,4,7,3,5,6,8}  , 中序{4,7,2,1,5,3,8,6}可唯一确定二叉树
#include <iostream>
#include <exception>
using namespace std;

struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;
};

BinaryTreeNode *Construct(int *preorder, int *inorder, int length) //封装函数
{
    if (preorder == nullptr || inorder == nullptr || length <= 0)
    {
        return nullptr;
    }
    return ConstructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
}

BinaryTreeNode *ConstructCore(int *startPreorder, int *endPreorder, int *startInorder, int *endInorder) //递归调用，就能完成二叉树的构建
{
    int rootValue = startPreorder[0]; //前序遍历第一个节点是根节点，在数组中操作；

    BinaryTreeNode *root = new BinaryTreeNode(); //构建二叉树根节点；
    root->m_nValue = rootValue;
    root->m_pLeft = root->m_pRight = nullptr; //初始化根节点，左右指针先指空
    if (startPreorder == endPreorder)
    {
        if (startInorder == endInorder && *startPreorder == *startInorder)
        {
            return root; //这一步判断，如果中序遍历元素开始节点等于结束节点，先序开始节点(root->m_nValue)等于中序开始节点(root->m_nValue)，说明此树只有一个根节点
        }
        else
        {
            throw exception("Invalid input.");
        }
    }

    //中序遍历中找到根节点的值
    int *rootInorder = startInorder;
    while (rootInorder <= endInorder && *rootInorder != rootValue)
    {
        ++rootInorder; //边界判断，中序的根节点是先序的第一个元素，即rootValue
    }

    if (rootInorder == endInorder && *rootInorder != rootValue)
    {
        throw exception("Invalid input.");
    }

    int leftLength = rootInorder - startInorder;       //左边子树的长度，在数组中
    int *leftPreorderEnd = startPreorder + leftLength; //左边子树最后一个元素，即中序遍历root节点的左边一个元素
    if (leftLength > 0)
    {
        //构建左子树
        root->m_pLeft = ConstructCore(startPreorder + 1, leftPreorderEnd, startInorder, rootInorder - 1);
        //上面四个参数，第一个第二个参数是先序的前半段，第三个第四个参数是中序的开始和中序前半段元素
        //为什么第一个参数是startPreorder + 1，因为第一个元素是根节点，所以+1
    }

    if (leftLength < endPreorder - startPreorder) //说明有右子树
    {
        root->m_pRight = ConstructCore(leftPreorderEnd + 1, endPreorder, rootInorder + 1, endInorder);
    }
}