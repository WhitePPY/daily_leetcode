/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        if(n==1)
            return 1;
        vector<int> dp(n+1,0);
        dp[1] = 1;
        for(int j = 2; j <= n; ++j){
            dp[j] = n*dp[1];
            for(int i = 1; i*i <= j; ++i){
                dp[j] = min(dp[j-i*i]+1,dp[j]);
            }
        }
        return dp[n];
    }
};
// @lc code=end

