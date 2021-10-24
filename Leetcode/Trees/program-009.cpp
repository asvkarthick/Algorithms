/* Program: Level order traversal of a binary tree
 * Weblink: https://leetcode.com/problems/binary-tree-level-order-traversal/
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
    void levelOrder(TreeNode* root, std::vector<std::vector<int>>& v, int level)
    {
        if (root == nullptr) return;
        if (v.size() <= level) {
            v.push_back(std::vector<int>{});
        }
        v[level].push_back(root->val);
        levelOrder(root->left, v, level + 1);
        levelOrder(root->right, v, level + 1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> v;
        levelOrder(root, v, 0);
        return v;
    }
};
