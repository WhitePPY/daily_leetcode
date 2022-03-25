/*
 * @lc app=leetcode.cn id=1938 lang=cpp
 *
 * [1938] 查询最大基因差
 */

// @lc code=start

class Solution
{
public:
    vector<int> maxGeneticDifference(vector<int> &parents, vector<vector<int>> &queries)
    {
        int max = 0;
        int curNode = 0;
        vector<int> re;
        for (int i = 0; i < queries.size(); ++i)
        {
            max = queries[i][1] ^ queries[i][0];
            curNode = queries[i][0];
            while (parents[curNode] != -1)
            {
                curNode = parents[curNode];
                if ((curNode ^ queries[i][1]) > max)
                    max = curNode ^ queries[i][1];
            }
            re.push_back(max);
        }
        return re;
    }
};
// @lc code=end
