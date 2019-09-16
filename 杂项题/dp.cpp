#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 1010;
int dp[MAX][MAX];
int longestSubSeq(vector<int> nums)
{
    int sz = nums.size();
    if (sz <= 1)
        return sz;

    sort(nums.begin(), nums.end());

    int ans = 1;
    int i, j;
    for (int i = 0; i < MAX; ++i)
    {
        for (int j = 0; i < MAX; ++j)
        {
            dp[i][j] = 1;
        }
    }
    for (i = 1; i < sz; ++i)
    {
        for (j = i - 1; j >= 0; --j)
        {
            int diff = nums[i] - nums[j];
            dp[i][diff] = dp[j][diff] + 1;
            ans = max(ans, dp[i][diff]);
        }
    }
    return ans;
}