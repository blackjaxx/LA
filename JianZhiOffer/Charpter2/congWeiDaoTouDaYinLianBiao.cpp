//从尾到头打印链表
//剑指offer第六题
//输入链表头节点，从尾到头打印链表的值

//很自然想到把链表的指针反向过来，但是是否可以改动指针，需要问清楚

#include <stack>
#include <cstdio> //printf用到
struct ListNode
{
    int m_nKey;
    ListNode *m_pNext;
};

//非递归版本
void PrintListReverse_Iteratively(ListNode *pHead)
{
    std::stack<ListNode *> nodes;
    ListNode *pNode = pHead;
    while (pNode != nullptr)
    {
        nodes.push(pNode);
        pNode = pNode->m_pNext;
    }

    while (!nodes.empty())
    {
        pNode = nodes.top();
        printf("%d\t", pNode->m_nKey);
        nodes.pop();
    }
}

/*
思路：
非递归，常用，不会导致栈溢出
创建stack，stack中泛型为listNode *

while(链表不空)
{
    往stack中push节点； 
    节点向下移动一位；
}
元素都压入栈中后
while(栈不空)
{
    节点头等于栈顶元素 nodes.top()；
    输出节点（）；
    nodes.pop();
}

*/

//递归版本
void PrintListReverse_Recurisively(ListNode *pHead)
{
    if (pHead != nullptr)
    {
        if (pHead->m_pNext != nullptr) //递归出口
        {
            PrintListReverse_Recurisively(pHead->m_pNext);
        }
        printf("%d\t", pHead->m_nKey);
    }
}

//递归版本存在一个问题，链表非常长的时候会导致栈溢出

/*
思路：
递归版本：
函数（）{
if（链表不空）
{
    if（链表下一个节点不空，作为递归出口）
    {
        递归调用函数（）；
    }
    printf（结点值）；
}
}
*/