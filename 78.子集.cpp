/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
private:
    int N;
    vector<int> list;
    vector<vector<int>> ans;
public:
    void backTracking(const vector<int>& nums, int index){
        ans.emplace_back(list);
        for(int i = index; i < N;++i){
            list.emplace_back(nums[i]);
            backTracking(nums, i+1);
            list.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        this->N = nums.size();
        backTracking(nums,0);
        return this->ans;
    }
};
// @lc code=end

