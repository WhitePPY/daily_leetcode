/*
 * @lc app=leetcode.cn id=399 lang=cpp
 *
 * [399] 除法求值
 */

// @lc code=start
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int N = values.size();
        unordered_map<string, int> hash;
        int index = 0;
        for(int i = 0; i < N; ++i){
            if(hash.find(equations[i][0]) == hash.end()){
                hash.emplace(equations[i][0], index++);
            }
            if(hash.find(equations[i][1]) == hash.end()){
                hash.emplace(equations[i][1], index++);
            }
        }
        int mapSize = hash.size();
        vector<vector<double>> map(mapSize, vector<double>(mapSize, -1));
        for(int i = 0; i < N; ++i){
            auto l = hash.find(equations[i][0]);
            auto r = hash.find(equations[i][1]);
            map[l->second][r->second] = values[i];
            map[r->second][l->second] = 1.0/values[i];
            map[i][i] = 1.0;
        }
        for(int i = 0; i < mapSize; ++i){
            for(int j = 0; j < mapSize; ++j){
                for(int k = 0;k < mapSize; ++k){
                    if(map[j][i]>0 && map[i][k] >0)
                        map[j][k] = map[j][i]*map[i][k];
                }
            }
        }
        vector<double> result;
        for(int i = 0; i < queries.size(); ++i){
            auto l = hash.find(queries[i][0]);
            auto r = hash.find(queries[i][1]);
            if(l == hash.end() || r == hash.end()){
                result.emplace_back(-1);
                continue;
            }
            result.emplace_back(map[l->second][r->second]);
        }
        return result;
    }
};
// @lc code=end

