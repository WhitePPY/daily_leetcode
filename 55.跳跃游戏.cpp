/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int N = nums.size();
        vector<bool> dp(N, false);
        dp[0] = true;
        for(int i = 0; i < N; ++i){
            if(dp[i]){
                if(nums[i]+i >=N)
                    return true;
                if(dp[nums[i]+i])
                    continue;
                for(int j = 1; j <= nums[i] && i+j < N;++j)
                    dp[i + j] = true;
            }
        }
        return dp[N-1];
    }
};
// @lc code=end

