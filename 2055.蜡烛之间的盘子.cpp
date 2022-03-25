/*
 * @lc app=leetcode.cn id=2055 lang=cpp
 *
 * [2055] 蜡烛之间的盘子
 */

// @lc code=start
class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int N = s.size();
        vector<int> count(N,0);
        for(int i = 0;i < N;++i){
            if(s[i]=='*'){
                if(!i)
                    count[i]=1;
                else
                    count[i] = count[i-1]+1;
            }
            else{
                if(i)
                    count[i] = count[i-1];
            }
        }
        vector<int> left(N);
        for (int i = 0, l = -1; i < N; i++) {
            if (s[i] == '|') {
                l = i;
            }
            left[i] = l;
        }
        vector<int> right(N);
        for (int i = N - 1, r = -1; i >= 0; i--) {
            if (s[i] == '|') {
                r = i;
            }
            right[i] = r;
        }
        vector<int> ans(queries.size(),0);
        for(int i = 0; i < queries.size(); ++i){
            int l = right[queries[i][0]], r = left[queries[i][1]];
            if(l == -1 || r == -1 || l >= r)
                ans[i]=0;
            else
                ans[i] = count[r] - count[l];
        }
        return ans;
    }
};
// @lc code=end

