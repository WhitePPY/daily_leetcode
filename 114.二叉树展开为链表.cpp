/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
public:
    void flatten(TreeNode *node)
    {
        if (!node)
            return;
        while (node)
        {
            if (node->left)
            {
                TreeNode *tmp = node->left;
                while (tmp->right)
                    tmp = tmp->right;
                tmp->right = node->right;
                node->right = node->left;
                node->left = nullptr;
            }
            node = node->right;
        }
    }
};
// @lc code=end
