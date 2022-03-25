/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
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
public:
//res[0]是当前取了，res[1]是当前没有取
    vector<int> dfs(TreeNode* root){
        if(!root) return {0,0};
        vector<int> left=dfs(root->left);
        vector<int> right=dfs(root->right);
        return {root->val+left[1]+right[1],max(left[1],left[0])+max(right[1],right[0])};
    }
    int rob(TreeNode* root) {
        vector<int> res(2);
        res=dfs(root);
        return max(res[0],res[1]);

    }
};
// @lc code=end

