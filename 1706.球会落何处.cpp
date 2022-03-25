/*
 * @lc app=leetcode.cn id=1706 lang=cpp
 *
 * [1706] 球会落何处
 */

// @lc code=start
class Solution
{
public:
    vector<int> findBall(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> answer(n, 0);
        int xpos = 0, ypos = 0;
        for (int i = 0; i < n; ++i)
        {
            xpos = i;
            ypos = 0;
            for (int j = 0; j < m; ++j)
            {
                if (grid[ypos][xpos] == 1)
                {
                    if (xpos == n - 1)
                    {
                        answer[i] = -1;
                        break;
                    }
                    else
                    {
                        if (grid[ypos][xpos + 1] == -1)
                        {
                            answer[i] = -1;
                            if(!ypos)
                                answer[++i] = -1;
                            break;
                        }
                        ++xpos;
                        if (ypos == m - 1)
                        {
                            answer[i] = xpos;
                            break;
                        }
                        ++ypos;
                    }
                }
                else
                {
                    if (xpos == 0)
                    {
                        answer[i] = -1;
                        break;
                    }
                    else
                    {
                        if (grid[ypos][xpos - 1] == 1)
                        {
                            answer[i] = -1;
                            break;
                        }
                        --xpos;
                        if (ypos == m - 1)
                        {
                            answer[i] = xpos;
                            break;
                        }
                        ++ypos;
                    }
                }
            }
        }
        return answer;
    }
};
// @lc code=end
