/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
private:
    int N;
    vector<int> visited;
    vector<int> list;
    vector<vector<int>> result;
public:
    void backTracking(const vector<int>& nums){
        if(this->list.size() == this->N){
            result.emplace_back(this->list);
            return;
        }else if(list.size() < N){
            for(int i = 0; i < N; ++i){
                if(!this->visited[i]){
                    this->list.emplace_back(nums[i]);
                    this->visited[i] =1;
                    backTracking(nums);
                    this->list.pop_back();
                    this->visited[i]=0;
                }
            }
        }else
            return;
    }
    vector<vector<int>> permute(const vector<int>& nums) {
        this->N = nums.size();
        this->visited = *(new vector<int>(this->N, 0));
        backTracking(nums);
        return this->result;
    }
};
// @lc code=end

