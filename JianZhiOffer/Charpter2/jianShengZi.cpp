//剪绳子
//剑指offer第14题
//动态规划典型题目
//给你一根长度为n的绳子，请把绳子剪成m段（m，n都是整数且都大于1），每段绳子的长度记为k[0],k[1],k[2]...k[m];
//请问k[0]*k[1]*k[2]..*k[m]最大乘积为多少；

//两种思路，一种动态规划，一种贪婪算法

//动态规划
//时间复杂度O(N*2)，空间复杂度O(N)
//当一道题是求一个问题的最优解(通常是最大值最小值问题)，且该问题可以分解成若干个子问题，且子问题之间还存在更小的子问题，可以考虑用动态规划解决；
//本题中，把长度为n的绳子剪成诺干段，使得各个段乘积最大，这是求一个问题的最优解，这是可以用动态规划的第一个特点；
//我们把绳子剪成诺干段得到乘积最大值定义为函数f(n)，我们把第一刀剪在长度为i（0<i<n）的位置，于是把长度剪为i和n-i的两段；
//如果我们想得到f(n)，要用同样的方法把i和n-i剪成诺干段，使得他们各自剪出每段绳子的长度乘积最大，即整体问题最优解依赖于子问题最优解，这是动态规划的第二个特点；
//大问题可分解成小问题，小问题还有互相重叠的更小问题，这是能应用动态规划的第三个特点；
//子问题在大问题的分解过程中重复出现，为了避免重复求解子问题，可以从下往上的顺序计算小问题的解并存储下来，可以再此基础上求取大问题的解；
//从上往下分析问题，从下往上求解，这是应用动态规划的第四个特点；
//解决子问题的最优解一般使用一维或二维数组里；
//本题中，每一步都有很多选择，第一刀有n-1选择，我们可以在1，2，...n-1的任意位置，因为事先不知道哪个位置是最优解的解法，
//只好把所有可能都尝试一遍，比较出最优解法，可表示为f(n) = max(f(i)*f(n-i)) ,0<i<n;

//当长度为2时只能剪为2段各1m的，f(2) = 1 ，当长度为3的时候，可能剪为1，和2两段或长度为1，1，1的三段，即f(3) = 2;

int maxProductAfterCutting_solution1(int length)
{
    if (length == 2)
    {
        return 1;
    }

    if (length == 3)
    {
        return 2;
    }
    if (length < 2)
    {
        return 0;
    }

    int *products = new int[length + 1];
    products[0] = 0; //数组中第i个元素表示把长度为i的绳子剪成诺干段之后各段长度乘积的最大值；
    products[1] = 1;
    products[2] = 2;
    products[3] = 3;

    int max = 0;

    for (int i = 4; i <= length; ++i) //这个循环是递增的，说明是自下向上求解问题
    {
        max = 0;
        for (int j = 1; j < i / 2; ++j) //防止重复计算，算前一半的product[i]即可，后边重复计算了
        {
            int product = products[j] * products[i - j]; //当我求product[i]是，我己经知道比它下标低时的最优值了，能得到现在最优解
            if (max < product)
            {
                max = product; //更新最优解
            }

            products[i] = max; //数组中存储最优值
        }
    }
    max = products[length]; //最优值
    delete[] products;

    return max;
}

//贪心算法
//当绳子长度大于5时，尽可能多剪长度为3的绳子，当长度为4的时候，尽可能多剪成两段长度为2的绳子
//因为products[3] = 3   ,  products[2] = 2 均为最优解；
#include <cmath>

int maxProductAfterCutting_solution2(int length)
{
    if (length == 2)
    {
        return 1;
    }

    if (length == 3)
    {
        return 2;
    }
    if (length < 2)
    {
        return 0;
    }

    //尽可能多剪长度为3的绳子
    int timesOf3 = length / 3;

    //当长度剩下最后长度为4的时候，不能在减去长度为3的绳子段
    //此时应该剪成长度为2的两段
    if (length - timesOf3 * 3 == 1)
    {
        timesOf3 -= 1;
    }

    int timesOf2 = (length - timesOf3 * 3) / 2;

    return (int)(pow(3, timesOf3)) * (int)(pow(2, timesOf2));
}

//解析：
//