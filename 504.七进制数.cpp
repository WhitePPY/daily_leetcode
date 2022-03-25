/*
 * @lc app=leetcode.cn id=504 lang=cpp
 *
 * [504] 七进制数
 */

// @lc code=start
class Solution {
public:
    string convertToBase7(int num) {
        if (!num) 
            return "0";
        int abNum = abs(num);
        int tmp = 0;
        string ans = "";
        while (abNum) {
            tmp = abNum % 7;
            abNum /= 7;
            ans = to_string(tmp) + ans;
        }
        return num < 0 ?  "-" + ans : ans;
    }
};
// @lc code=end

