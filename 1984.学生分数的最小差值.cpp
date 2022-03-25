/*
 * @lc app=leetcode.cn id=1984 lang=cpp
 *
 * [1984] 学生分数的最小差值
 */

// @lc code=start
class Solution
{
public:
    int minimumDifference(vector<int> &nums, int k)
    {
        if (k == 1)
            return 0;
        deque<int> de;
        sort(nums.begin(), nums.begin()+k-1);
        for (int i = 0; i < k; ++i)
            de.push_back(nums[i]);
        int max = de.back();
        int min = de.front();
        for (int i = k; i < nums.size(); ++i)
        {
            if (nums[k] < max && nums[k] > min)
            {
                
            }
        }
        return max - min;
    }
};
// @lc code=end
