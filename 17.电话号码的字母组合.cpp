/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<vector<string>> map = {{"a","b","c"},{"d","e","f"},{"g","h","i"},{"j","k","l"},{"m","n","o"},{"p","q","r","s"},{"t","u","v"},{"w","x","y","z"}};
        if(digits.length()==1)
            return map[mapFind(digits[0])];
        vector<string> re;
        for(auto& i : digits){
            if (!re.size()){
                for(auto &j: map[mapFind(i)]){
                    re.push_back(j);
                }
            }
            else{
                vector<string> tmp(re);
                re.clear();
                for(auto &j: map[mapFind(i)]){
                    for(auto &last: tmp){
                        re.push_back(last+j);
                    }
                }
            }
        }
        return re;
    }
private:
    inline int mapFind(const char &key){
        return key - '2';
    }
};
// @lc code=end

