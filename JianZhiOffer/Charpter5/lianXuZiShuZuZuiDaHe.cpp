//连续子数组最大和
//剑指offer第42题
//输入一个数组，其中有正数也有负数，数组中一个或连续多个整数组成一个子数组，求所有子数组的最大和，时间复杂度为O（n）

//动态规划
//  S定义为以当前元素前一个元素为止，前面子数组最大和是S
//  S如何更新
// S <或= 0 最大值为当前X（X是S和后一位数字）
// S > 0 更新S += x
#include <vector>
#include <cstdio>
#include <algorithm> //max函数
#include <iostream>
int maxSumOfArray(std::vector<int> &nums)
{
    int res = INT_MIN, s = 0;
    for (auto x : nums)
    {
        if (s < 0)
        {
            s = 0;
        }
        s += x;
        res = max(res, s);
    }
    return res;
}