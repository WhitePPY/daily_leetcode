/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
private:
    int sum = 0;
    TreeNode *rightMost;

public:
    void preSum(TreeNode *root)
    {
        if (!root)
            return;
        preSum(root->right);
        if (root != this->rightMost)
        
        {root->val += this->sum;
        this->sum = root->val;}
        preSum(root->left);
    }
    TreeNode *convertBST(TreeNode *root)
    {
        if (!root)
            return root;
        TreeNode *tmp = root;
        TreeNode *tmp2 = root;
        while (tmp->right)
        {
            tmp = tmp->right;
        }
        if (tmp==root)
        {
            this->sum = root->val;
            this->rightMost = root;
        }
        else
        {
            this->sum = tmp->val;
            this->rightMost = tmp;
        }
        tmp2 = root;
        preSum(tmp2);
        return root;
    }
};
// @lc code=end
