/*
 * @lc app=leetcode.cn id=449 lang=cpp
 *
 * [449] 序列化和反序列化二叉搜索树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    // 使用空格隔开
    void dfs(TreeNode* root, string& res){
        if(!root) return;
        res += to_string(root->val) + ' ';
        dfs(root->left, res);
        dfs(root->right, res);
    }
    string serialize(TreeNode* root) {
        string res;
        dfs(root, res);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        //使用stringstream读取按空格分割的字符串
        stringstream ss(data);
        vector<int> pre;
        int x;
        while(ss >> x){
            pre.emplace_back(x);
        }
        int u = 0;
        const int INF = 0x3f3f3f3f;
        return dfs_d(pre, u, -INF, INF);
    }
    TreeNode* dfs_d(vector<int>& pre, int& u, int minv, int maxv) {
        if(u == pre.size()) return nullptr;
        if(pre[u] < minv || pre[u] > maxv) return nullptr;
        auto root = new TreeNode(pre[u++]);
        root->left = dfs_d(pre, u, minv, root->val - 1);
        root->right = dfs_d(pre, u, root->val + 1, maxv);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
// @lc code=end

