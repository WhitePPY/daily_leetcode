/*
 * @lc app=leetcode.cn id=258 lang=cpp
 *
 * [258] 各位相加
 */

// @lc code=start
class Solution
{
public:
    int addDigits(int num)
    {
        if (num / 10 == 0)
            return num;
        return num%9 ? num%9 : 9;
    }
};
// @lc code=end
