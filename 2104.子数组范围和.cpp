/*
 * @lc app=leetcode.cn id=2104 lang=cpp
 *
 * [2104] 子数组范围和
 */

// @lc code=start
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int N = nums.size();
        long long re = 0;
        for(int i = 0; i < N;++i){
            int minN =nums[i],maxN = nums[i];
            for(int j = i+1; j < N;++j){
                minN = min(minN, nums[j]);
                maxN = max(maxN,nums[j]);
                re+=maxN-minN;
            }
        }
        return re;
    }
};
// @lc code=end

