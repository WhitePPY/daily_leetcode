/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(!prerequisites.size())
            return true;
        vector<int> ready(numCourses + 1, 0);
        for(auto &i : prerequisites){
            ++ready[i[0]];
        }
        bool flag = false;
        while(1){
            for(int i = 0; i < prerequisites.size();++i){
                if(!ready[prerequisites[i][1]]){
                    --ready[prerequisites[i][0]];
                    prerequisites.erase(prerequisites.begin()+i);
                    flag = true;
                }
            }
            if(!flag)
                break;
            flag=false;
        }
        for(auto &i : ready){
            if(i)
                return false;
        }
        return true;
    }
};
// @lc code=end

