//重建二叉树
//剑指offer第七题
//输入二叉树的前序和中序遍历结果，重建二叉树；假设输入的前序和中序遍历都不含有重复数字
//假设输入节点前序{1,2,4,7,3,5,6,8}  , 中序{4,7,2,1,5,3,8,6}可唯一确定二叉树
struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;
};

BinaryTreeNode *ConstructCore(int *StartPreorder, int *endPreorder, int *startInorder, int *endInorder)
{
    int rootValue = StartPreorder[0]; //前序遍历第一个节点是根节点，在数组中操作；

    BinaryTreeNode *root = new BinaryTreeNode(); //构建二叉树根节点；
    root->m_nValue = rootValue;
    root->m_pLeft = root->m_pRight = nullptr; //初始化根节点，左右指针先指空
}