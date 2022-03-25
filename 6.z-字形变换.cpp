/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        vector<string> res(numRows, "");
        string re;
        int zone = 2*numRows - 2;
        for(int i = 0; i < s.size();++i){
            res[-1*abs(i%zone-zone/2) + zone/2] += s[i];
        }
        for(int i = 0; i < numRows;++i)
            re+=res[i];
        return re;
    }
};
// @lc code=end

