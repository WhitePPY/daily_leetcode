/*
 * @lc app=leetcode.cn id=421 lang=cpp
 *
 * [421] 数组中两个数的最大异或值
 */

// @lc code=start
class Trie
{
private:
    Trie *next[2] = {nullptr};

public:
    Trie(){};
    void insert(int x)
    {
        Trie *root = this;
        for (int i = 30; i >= 0; --i)
        {
            int bit = (x >> i) & 1;
            if (!root->next[bit])
                root->next[bit] = new Trie();
            root = root->next[bit];
        }
    }

    int search(int x)
    {
        Trie *root = this;
        int re = 0;
        for (int i = 30; i >= 0; --i)
        {
            int bit = (x >> i) & 1;
            if (root->next[!bit])
                root = root->next[!bit], re = re * 2 + !bit;
            else
                root = root->next[bit], re = re * 2 + bit;
        }
        re ^= x;
        return re;
    }
};
class Solution
{
public:
    int findMaximumXOR(vector<int> &nums)
    {
        Trie *root = new Trie();
        for (const auto &i : nums)
            root->insert(i);
        int Max = 0;
        for (const auto &i : nums)
        {
            int tmp = root->search(i);
            if (Max < tmp)
                Max = tmp;
        }
        return Max;
    }
};
// @lc code=end
