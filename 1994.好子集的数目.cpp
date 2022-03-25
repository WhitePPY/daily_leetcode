/*
 * @lc app=leetcode.cn id=1994 lang=cpp
 *
 * [1994] 好子集的数目
 */

// @lc code=start
class Solution {
public:
    int numberOfGoodSubsets(vector<int>& nums) {
        vector<int> numCount(31, 0);
        for(int i=0; i < nums.size(); ++i){
            if(nums[i]%9 == 0 || nums[i]%4 == 0 || nums[i] == 16 || nums[i] == 25)
                break;
            ++numCount[nums[i]];
        }
        vector<int> dp(1<<10,0);
        vector<int> transfer{2,3,5,7,11,13,17,19,23,29};
        for(int i = 0;i <=9;++i){
            dp[1<<i] = numCount[transfer[i]];
        }

    }
};
// @lc code=end

