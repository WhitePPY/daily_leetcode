/*
 * @lc app=leetcode.cn id=1020 lang=cpp
 *
 * [1020] 飞地的数量
 */

// @lc code=start
class UnionFind
{
public:
    UnionFind(const vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        this->parent = vector<int>(m * n);
        this->onEdge = vector<bool>(m * n, false);
        this->rank = vector<int>(m * n);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    int index = i * n + j;
                    parent[index] = index;
                    if (i == 0 || i == m - 1 || j == 0 || j == n - 1)
                    {
                        onEdge[index] = true;
                    }
                }
            }
        }
    }

    int find(int i){
        if(parent[i]!=i)
            parent[i] = find(parent[i]);
        return parent[i];
    }
    
    void uni(int x, int y)
    {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty)
        {
            if (rank[rootx] > rank[rooty])
            {
                parent[rooty] = rootx;
                onEdge[rootx] = onEdge[rootx] | onEdge[rooty];
            }
            else if (rank[rootx] < rank[rooty])
            {
                parent[rootx] = rooty;
                onEdge[rooty] = onEdge[rooty] | onEdge[rootx];
            }
            else
            {
                parent[rooty] = rootx;
                onEdge[rootx] = onEdge[rootx] | onEdge[rooty];
                rank[rootx]++;
            }
        }
    }

    bool isOnEdge(int i)
    {
        return onEdge[find(i)];
    }

private:
    vector<int> parent;
    vector<bool> onEdge;
    vector<int> rank;
};
class Solution
{
public:
    int numEnclaves(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        UnionFind uf(grid);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    int index = i * n + j;
                    if (j + 1 < n && grid[i][j + 1] == 1)
                    {
                        uf.uni(index, index + 1);
                    }
                    if (i + 1 < m && grid[i + 1][j] == 1)
                    {
                        uf.uni(index, index + n);
                    }
                }
            }
        }
        int enclaves = 0;
        for (int i = 1; i < m - 1; i++)
        {
            for (int j = 1; j < n - 1; j++)
            {
                if (grid[i][j] == 1 && !uf.isOnEdge(i * n + j))
                {
                    enclaves++;
                }
            }
        }
        return enclaves;
    }
};
// @lc code=end
