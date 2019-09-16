//n节车厢从A方向驶入，按进站顺序编号1-n，能否按照某种顺序进入B方向，有一中转站C，可以停放任意节车厢
//每一车厢有两种选择，一旦从A进入C就不能在退回A了，一但从C进入B，就不能在回到C了
//中转站C中，车厢符合后进先出原则，因此式一个栈
#include <cstdio>
#include <stack>

using namespace std;
const int MAXN = 1000 + 10; //定义常量

int n, target[MAXN]; //n是n节车厢，target数组代表我输入用来判断的序列

int main()
{
    while (scanf("%d", &n) == 1) //scanf有返回值
    {
        stack<int> s; //开辟栈
        int A = 1, B = 1;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &target[i]); //输入序列保存在target中
        }
        int ok = 1;
        while (B <= n)
        {
            if (A == target[B]) //第一种情况，如果A
            {
                A++;
                B++;
            }
            else if (!s.empty() && s.top() == target[B])
            {
                s.pop();
                B++;
            }
            else if (A <= n)
            {
                s.push(A++);
            }
            else
            {
                ok = 0;
                break;
            }
        }
        printf("%s\n", ok ? "yes" : " No");
    }
    return 0;
}
