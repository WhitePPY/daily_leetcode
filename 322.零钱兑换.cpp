/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, 10001);
        int N = coins.size();
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                if(i - coins[j] >= 0)
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
        return dp[amount] > 10000 ? -1 : dp[amount];
    }
};
// @lc code=end