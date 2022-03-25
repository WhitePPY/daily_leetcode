/*
 * @lc app=leetcode.cn id=301 lang=cpp
 *
 * [301] 删除无效的括号
 */

// @lc code=start
class Solution {
private:
    vector<string> re;
public:
    bool isvalid(string s){
        int lnum = 0;
        int rnum = 0;
        for(auto&i : s){
            if(i == '(')
                ++lnum;
            else if(i == ')'){
                if(!lnum)
                    return false;
                else
                    --lnum;
            }
        }
        if(lnum||rnum)
            return false;
        return true;
    }
    void backTracking(string str,int index, int lnum, int rnum){
        if(!lnum && !rnum){
            if(isvalid(str))
                re.emplace_back(str);
            return;
        }
         for (int i = index; i < str.size(); ++i) {
            if (i != index && str[i] == str[i - 1]) {
                continue;
            }
            if (lnum + rnum > str.size() - i) {
                return;
            }
            if (lnum > 0 && str[i] == '(') {
                backTracking(str.substr(0, i) + str.substr(i + 1), i, lnum - 1, rnum);
            }
            if (rnum > 0 && str[i] == ')') {
                backTracking(str.substr(0, i) + str.substr(i + 1), i, lnum, rnum - 1);
            }
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        int lnum = 0;
        int rnum = 0;
        for(auto&i : s){
            if(i == '(')
                ++lnum;
            else if(i == ')'){
                if(!lnum)
                    ++rnum;
                else
                    --lnum;
            }
        }
        if(lnum + rnum == s.size())
            return {""};
        backTracking(s,0, lnum, rnum);
        sort(this->re.begin(), this->re.end());
        this->re.erase( unique( re.begin(), re.end() ), re.end() );
        return this->re;
    }
};
// @lc code=end

