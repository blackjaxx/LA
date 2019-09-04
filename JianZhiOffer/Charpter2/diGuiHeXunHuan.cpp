//算法和数据结构
//排序和查找问题
//熟练写出二分查找，归并排序和快速排序的代码

//当要求在二维数组中搜索路径，尝试使用回溯法，回溯法很适合用递归，当条件不可以使用递归时，我们可以考虑用栈模拟递归；
//如果遇到求某个问题最优解，且此问题可以分为多个子问题，那么可使用动态规划；
//为了减少递归中不必要的重复计算，可以使用自下而上的循环代码实现，即将子问题最优解先算出来并用数组保存下来，基于子问题在计算大问题的解；
//如果动态规划中分解子问题是不是存在某个选择，选用这个选择一定能得到最优解！！！此时使用贪婪算法；

//计算1+2+3+4+...+n

//递归版本
int AddFrom1ToN_Recursive(int n)
{
    return n <= 0 ? 0 : AddFrom1ToN_Recursive(n - 1) + n;
}
//or
int AddFrom1ToN_Recursive_2(int n)
{
    if (n <= 0)
    {
        return 0;
    }
    else
    {
        return AddFrom1ToN_Recursive_2(n - 1) + n;
    }
}

//非递归

int AddFrom1ToN_Iterative(int n)
{
    int result = 0;
    for (int i = 1; i <= n; i++)
    {
        result += i;
    }
    return result;
}
