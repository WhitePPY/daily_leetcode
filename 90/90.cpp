class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtrack(nums, path, 0);
        return res;
    }
    void backtrack(const vector<int>& nums, vector<int>& path, int index){
        res.push_back(path);
        for(int i = index; i < nums.size(); i++){
            if(i!=index && nums[i] == nums[i-1]) 
                continue;
            path.push_back(nums[i]);
            backtrack(nums, path, i + 1);
            path.pop_back();
        }
    }
};