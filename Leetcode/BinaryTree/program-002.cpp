/* Program: Tree inorder traversal
 * Weblink: https://leetcode.com/explore/learn/card/data-structure-tree/134/traverse-a-tree/928/
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
    void preorderTraversal(TreeNode* root, std::vector<int>& v)
    {
        if (root == nullptr) return;
        v.push_back(root->val);
        preorderTraversal(root->left, v);
        preorderTraversal(root->right, v);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> v;
        preorderTraversal(root, v);
        return v;
    }
};
