/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        queue<TreeNode*> leftNodes;
        queue<TreeNode*> rightNodes;
        leftNodes.push(root->left);
        rightNodes.push(root->right);
        while(!leftNodes.empty()){
            TreeNode* tmpL = leftNodes.front();
            TreeNode* tmpR = rightNodes.front();
            leftNodes.pop();
            rightNodes.pop();
            if(tmpL && tmpR){
                if(tmpL->val == tmpR->val){
                    leftNodes.push(tmpL->left);
                    leftNodes.push(tmpL->right);
                    rightNodes.push(tmpR->right);
                    rightNodes.push(tmpR->left);
                }else{
                    return false;
                }
            }else if(!tmpL && !tmpR)
                continue;
            else
                return false;
        }
        return true;
    }
};
// @lc code=end

