//二叉树的递归遍历(DFS-Depth-First-Search)
//先序中序后续遍历

//给定一颗点带权(权值各不相同，都是小于10000的正整数)的二叉树中序和后续遍历，找一个叶子节点使得它到根路径上的权和最小，如果有多解，那么叶子本身的权小优先
//输入中每两行表示一棵树，其中第一行为中序遍历，第二行为后续遍历
/*

样例输入：

3 2 1 4 5 7 6
3 1 2 5 6 7 4

7 8 11 3 5 16 12 18
8 3 11 7 16 18 12 5
255
255

样例输出：
1
3
255
*/

//知道后续和中序遍历的序列，先还原二叉树，在执行遍历，找到最优解

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

//节点权值不同且都是正整数，那么直接用权值来作为节点编号
const int maxv = 1000 + 10; //定义的比1000稍微大一点
int in_order[maxv], post_order[maxv], lch[maxv], rch[maxv];
int n;

bool read_list(int *a)
{
    string line;
    if (!getline(cin, line))
        return false;
    stringstream ss(line);
    n = 0;
    int x;
    while (ss >> x)
    {
        a[n++] = x;
    }
    return n > 0;
}

//把in_order[L1..R1]和post_order[L2..R2]建成一棵二叉树，返回树根
int build(int L1, int R1, int L2, int R2)
{
    if (L1 > R1)
        return 0; //空树
    int root = post_order[R2];
    int p = L1;
    while (in_order[p] != root)
        p++;
    int cnt = p - L1; //左子树节点个数
}
