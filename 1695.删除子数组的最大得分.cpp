/*
 * @lc app=leetcode.cn id=1695 lang=cpp
 *
 * [1695] 删除子数组的最大得分
 */

// @lc code=start
class Solution
{
public:
    int maximumUniqueSubarray(vector<int> &nums)
    {
        int maxN = 0;
        int l = 0, r = 0;
        int N = nums.size();
        int count = 0;
        int hash[10001];
        memset(hash, 0, sizeof(hash));
        while (l < N && r < N)
        {
            while (r < N)
            {
                if (!hash[nums[r]])
                    hash[nums[r]] = 1, count += nums[r];
                else
                    break;
                ++r;
            }
            maxN = max(count, maxN);
            while (r < N && hash[nums[r]])
            {
                count-=nums[l];
                hash[nums[l]]=0;
                ++l;
            }
        }
        return maxN;
    }
};
// @lc code=end
