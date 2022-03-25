/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    queue<pair<TreeNode*,int>> q;
    vector<vector<int>> result;
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
            return {};
        q.push(make_pair(root,0));
        while(!q.empty()){
            auto tmp = q.front();
            if(tmp.first->left)
                q.push(make_pair(tmp.first->left, tmp.second+1));
            if(tmp.first->right)
                q.push(make_pair(tmp.first->right, tmp.second+1));
            q.pop();
            if(result.size() <= tmp.second)
                result.push_back({});
            result[tmp.second].emplace_back(tmp.first->val);
        }
        return result;
    }
};
// @lc code=end

