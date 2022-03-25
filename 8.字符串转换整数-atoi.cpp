/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
class Solution
{
public:
    int myAtoi(string s)
    {
        int i = 0;
        int upper = s.size() - 1;
        int isPositive = 1;
        int result = 0;
        for (; i <= upper; ++i)
        {
            if (s[i] != ' ')
            {
                break;
            }
        }
        if (s[i] == '-')
        {
            isPositive = -1;
            ++i;
        }
        else if (s[i] == '+')
        {
            ++i;
        }
        for (; i <= upper; ++i)
        {
            if (s[i] > '9' || s[i] < '0')
                break;
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && s[i]-'0' >= INT_MAX % 10))
                return INT_MAX;
            if (result < INT_MIN / 10 || (result == INT_MIN / 10 && s[i]-'0' >= -1*(INT_MIN % 10)))
                return INT_MIN;
            result = result * 10 + isPositive*(s[i] - '0');
        }
        return result;
    }
};
// @lc code=end
