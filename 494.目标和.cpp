/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
class Solution {
private:
    int N;
    int ans;
    int total;
public:
    void backTracking(const vector<int>& nums, int index,int sum){
        if(index == N-1){
            if(sum + nums[index] == total)
                ++ans;
            if(sum - nums[index] == total)
                ++ans;
        }else{
            backTracking(nums,index+1, sum+nums[index]);
            backTracking(nums,index+1, sum-nums[index]);
        }
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        this->ans = 0;
        this->N = nums.size();
        this->total = target;
        backTracking(nums,0,0);
        return this->ans;
    }
};
// @lc code=end

