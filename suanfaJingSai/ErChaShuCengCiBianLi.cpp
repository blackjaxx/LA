/*
输入一棵二叉树， 你的任务是按从上到下、 从左到右的顺序输出各个结点的值。 每个结
点都按照从根结点到它的移动序列给出（ L表示左， R表示右） 。 在输入中， 每个结点的左
括号和右括号之间没有空格， 相邻结点之间用一个空格隔开。 每棵树的输入用一对空括
号“()”结束（ 这对括号本身不代表一个结点）

 */

/*

注意， 如果从根到某个叶结点的路径上有的结点没有在输入中给出， 或者给出超过一
次， 应当输出-1。 结点个数不超过256。

样例输入：

(11,LL) (7,LLL) (8,R) (5,) (4,L) (13,RL) (2,LLR) (1,RRR) (4,RR) ()

(3,L) (4,R) ()

样例输出：

5 4 8 11 13 4 7 2 1
-1

 */

/* 需要采用动态结构， 根据需要建立新的结点， 然后将其组织成一棵树。 首先， 编
写输入部分和主程序：
*/

#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

char maxn;
char s[maxn]; //保存读入节点
bool failed = false;

bool read_input()
{
    bool failed = false;

    remove_tree(root); //如果程序动态申请内存， 请注意内存泄漏

    root = newnode(); //创建根节点

    for (;;)
    {
        if (scanf("%s", s) != 1)
            return false; //整个输入的结束
        if (!strcmp(s, "()"))
            break; //读到结束标志，退出循环
        int v;
        sscanf(&s[1], "%d", &v);        //读入结点值
        addnode(v, strchr(s, ',') + 1); //查找逗号， 然后插入结点
    }
    return true;
}
/*

程序不难理解： 不停读入结点， 如果在读到空括号之前文件结束， 则返回0（ 这样， 在
main函数里就能得知输入结束） 。 注意， 这里两次用到了C语言中字符串的灵活性——可以
把任意“指向字符的指针”看成是字符串， 从该位置开始， 直到字符“\0”。 例如， 若读到的结
点是(11,LL)， 则&s[1]所对应的字符串是“11,LL)”。 函数strchr(s, ',’)返回字符串s中从左往右第
一个字符“,”的指针， 因此strchr(s, ',')+1所对应的字符串是“LL)”。 这样， 实际调用的是
addnode(11, "LL)")
 */

//结点类型
struct Node
{
    bool have_value; //是否被赋值过
    int v;           //结点值
    Node *left, *right;
    Node() : have_value(false), left(NULL), right(NULL) {} //构造函数
};
Node *root; //二叉树的根结点

//每次需要一个新的Node时， 都要用new运算符申请内存， 并执行构造函数。 下面把申请
//新结点的操作封装到newnode函数中
Node *newnode() { return new Node(); }

void addnode(int v, char *s)
{
    int n = strlen(s);
    Node *u = root; //从根结点开始往下走
    for (int i = 0; i < n; i++)
        if (s[i] == 'L')
        {
            if (u->left == NULL)
                u->left = newnode(); //结点不存在， 建立新结点
            u = u->left;             //往左走
        }
        else if (s[i] == 'R')
        {
            if (u->right == NULL)
                u->right = newnode();
            u = u->right;
        } //忽略其他情况， 即最后那个多余的右括号
    if (u->have_value)
        failed = true; //已经赋过值， 表明输入有误
    u->v = v;
    u->have_value = true; //别忘记做标记
}

void remove_tree(Node *u)
{
    if (u == NULL)
        return;            //提前判断比较稳妥
    remove_tree(u->left);  //递归释放左子树的空间
    remove_tree(u->right); //递归释放右子树的空间
    delete u;              //调用u的析构函数并释放u结点本身的内存
}

bool bfs(vector<int> &ans)
{
    queue<Node *> q;
    ans.clear();
    q.push(root); //初始时只有一个根结点
    while (!q.empty())
    {
        Node *u = q.front();
        q.pop();
        if (!u->have_value)
            return false;    //有结点没有被赋值过， 表明输入有误
        ans.push_back(u->v); //增加到输出序列尾部
        if (u->left != NULL)
            q.push(u->left); //把左子结点（ 如果有） 放进队列
        if (u->right != NULL)
            q.push(u->right); //把右子结点（ 如果有） 放进队列
    }
    return true; //输入正确
}

/*
二叉树并不一定要用指针实现(无指针版本)。 接下来， 把指针完全去掉。 首先还是给每个结点编号，
但不是按照从上到下从左到右的顺序， 而是按照结点的生成顺序。 用计数器cnt表示已存在的
结点编号的最大值， 因此newnode函数需要改成这样;

const int root = 1;

void newtree(){ 
    left[root] = right[root] = 0;
    have_value[root] = false;
    cnt = root;

}

int newnode(){
    int u = ++cnt;
    left[u] = right[u] = 0;
    have_value[root] = false;
    return u;
}

接下来， 把所有的Node*类型改成int类型， 然后把结点结构中的成员变量改成全局数组
（ 例如， u->left和u->right分别改成left[u]和right[u]） ， 除了char*外， 整个程序就没有任何指
针了

 */

/*

可以用数组来实现二叉树， 方法是用整数表示结点编号， left[u]和right[u]分别表示u的左右子结点的编号。
虽然包括笔者在内的很多选手更喜欢用数组方式实现二叉树（ 因为编程简单， 容易调试），
但仍然需要具体问题具体分析。 例如， 用指针直接访问比“数组+下标”的方式略快，
因此有的选手喜欢用“结构体+指针”的方式处理动态数据结构， 但在申请结点时仍然用这里
的“动态化静态”的思想， 把newnode函数写成：

Node* newnode(){   
    Node* u = &node[++cnt];
    u->left = u->right = NULL;
    u->have_value = false;
    return u;
}
其中， node是静态申请的结构体数组。 这样写的坏处在于“释放内存”很不方便（ 想一
想，为什么）。如果反复执行新建结点和删除结点，cnt会一直增加，但是用完的内存却无法
重用。 在大多数算法竞赛题目中，这并不会引起问题，但也有一些对内存要求极高的题目，
对内存的一点浪费就会引起“内存溢出”错误。 常见的解决方案是写一个简单的内存池
（ memory pool），具体来说就是维护一个空闲列表（ free list），初始时把上述node数组中所
有元素的指针放到该列表中，如下所示：

queue<Node*> freenodes;
Node node[maxn];

void init() {
    for(int i = 0; i < maxn; i++)
    freenodes.push(&node[i]); //初始化内存池
} 

Node* newnode() {
    Node* u = freenodes.front();
    u->left = u->right = NULL;
    u->have_value = false; //重新初始化该结点
    freenodes.pop();
    return u;
}

void deletenode(Node* u) {
    freenodes.push(u);
}

可以用静态数组配合空闲列表来实现一个简单的内存池。 虽然在大多数算
法竞赛题目中用不上， 但是内存池技术在高水平竞赛以及工程实践中都极为重要。
 */