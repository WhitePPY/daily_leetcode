/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
public:
    void backTracking(const vector<int>& candidates,int num,int index){
        if(num == sum){
            result.push_back(list);
        }else if(num > sum){
            return;
        }else{
            for(int i = index; i < candidates.size();++i){
                list.push_back(candidates[i]);
                backTracking(candidates, num+candidates[i],i);
                list.pop_back();
            }
        }
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        this->sum = target;
        backTracking(candidates, 0, 0);
        return this->result;
    }
private:
    int sum;
    vector<int> list;
    vector<vector<int>> result;
};
// @lc code=end

