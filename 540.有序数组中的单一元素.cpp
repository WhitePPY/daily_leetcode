/*
 * @lc app=leetcode.cn id=540 lang=cpp
 *
 * [540] 有序数组中的单一元素
 */

// @lc code=start
class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int ret = 0;
        for(auto const &i:nums){
            ret^=i;
        }
        return ret;
    }
};
// @lc code=end
