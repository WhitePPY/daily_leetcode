/*
 * @lc app=leetcode.cn id=1380 lang=cpp
 *
 * [1380] 矩阵中的幸运数
 */

// @lc code=start
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        set<int> sMin;
        set<int> sMax;
        vector<int> re;
        int Max = 0;
        int Min = INT_MAX;
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0;i < m;++i){
            Min = *min_element(matrix[i].begin(),matrix[i].end());
            sMin.insert(Min);
            // cout <<"min"<< Min << endl;
        }
        for(int j = 0;j < n;++j){
            for(int i = 0;i < m;++i){
                Max = max(Max, matrix[i][j]);
            }
            sMax.insert(Max);
            // cout << "max"<<Max <<endl;
            Max = 0;
        }
        sMin.merge(sMax);
        if(sMax.empty())
            return {};
        for(auto i = sMax.begin(); i!= sMax.end();++i){
            re.push_back(*i);
        }
        return re;
    }
};
// @lc code=end

