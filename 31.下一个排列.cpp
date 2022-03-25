/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()==1)
            return;
        for(int i = nums.size()-2; i >=0;--i){
            if(nums[i] < nums[i+1]){
                int& min = nums[i+1];
                for(int j = i+1; j < nums.size();++j){
                    if(nums[j] < min && nums[j] > nums[i])
                        min = nums[j];
                }
                swap(nums[i],min);
                sort(nums.begin()+i+1, nums.end());
                return;
            }
        }
        sort(nums.begin(),nums.end(),greater<int>());
    }
};
// @lc code=end

