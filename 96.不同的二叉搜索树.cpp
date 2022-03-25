/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
class Solution {
public:
    int numTrees(int n) {
        if(n==1)    return 1;
        vector<int> dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        for(int k = 2; k <=n;++k){
            for(int i = 0; i < k;++i){
                dp[k] += dp[k-i-1]*dp[i];
            }
        }
        return dp[n];
    }
};
// @lc code=end

