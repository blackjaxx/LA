//计算左闭右开区间内的元素和（ 两种写法）
int sum(int *begin, int *end)
{
    int n = end - begin;
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += begin[i];
    return ans;
}
//算差值并使用forloop累加

int sum(int *begin, int *end)
{
    int *p = begin;
    int ans = 0;
    for (int *p = begin; p != end; p++)
        ans += *p;
    return ans;
}
