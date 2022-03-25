/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
class Solution {
private:
    int max_depth = 0;
    void dfs(int depth, TreeNode* node){
        if(!node)
            max_depth = (max_depth > depth) ? max_depth : depth;
        else{
            dfs(depth + 1, node->left);
            dfs(depth + 1, node->right);
        }
    }
public:
    int maxDepth(TreeNode* root) {
        dfs(0,root);
        return this->max_depth;
    }
};
// @lc code=end

