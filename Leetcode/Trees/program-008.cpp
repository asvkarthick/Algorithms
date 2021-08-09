/* Program to print level order traversal
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

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
    int treeHeight(TreeNode *root)
    {
        if (root == nullptr) return 0;
        return std::max(treeHeight(root->left), treeHeight(root->right)) + 1;
    }
    void fillLevels(TreeNode *root, vector<vector<int>>& v, int level)
    {
        if (root == nullptr) return;
        v[level].push_back(root->val);
        fillLevels(root->left, v, level + 1);
        fillLevels(root->right, v, level + 1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        int height = treeHeight(root);
        for (int i = 0; i < height; i++) v.push_back(vector<int>{});
        fillLevels(root, v, 0);
        return v;
    }
};
