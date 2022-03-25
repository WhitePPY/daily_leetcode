/*
 * @lc app=leetcode.cn id=917 lang=cpp
 *
 * [917] 仅仅反转字母
 */

// @lc code=start
class Solution {
public:
    string reverseOnlyLetters(string &s) {
        int l = 0;
        int r = s.length()-1;
        while(l<r){
            while(l < r && !isalpha(s[l])) ++l;
            while(l < r && !isalpha(s[r])) --r;
            if(r<=l) break;
            swap(s[l++],s[r--]);
        }
        return s;
    }
};
// @lc code=end

