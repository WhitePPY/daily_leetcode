/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
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
    int count = 0;
    void dfs(TreeNode* root,int sum, int curSum){
        if(!root) return;
        if(curSum+root->val == sum)
            count++;
        dfs(root->left,sum,curSum+root->val);
        dfs(root->right,sum,curSum+root->val);
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(!root)
            return 0;
        dfs(root, targetSum,0);
        pathSum(root->left,targetSum);
        pathSum(root->right,targetSum);
        return this->count;
    }
};
// @lc code=end




