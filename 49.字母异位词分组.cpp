/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        if(strs.size()==1)
        {result.push_back({}); result[0].push_back(strs[0]);return result;}
        int count = 0;
        unordered_map<string, int> hash;
        for(auto &i:strs){
            string tmp = i;
            sort(tmp.begin(),tmp.end());
            if(hash.find(tmp) == hash.end())
                {hash.emplace(tmp,count);++count;result.push_back({i});}
            else
                result[hash.find(tmp)->second].push_back(i);
        }
        return result;
    }
};
// @lc code=end

