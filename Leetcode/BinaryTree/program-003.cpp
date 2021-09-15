/* Program: Inorder traversal of a tree
 * Weblink: https://leetcode.com/explore/learn/card/data-structure-tree/134/traverse-a-tree/929/
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
    void inorderTraversal(TreeNode* root, std::vector<int>& v)
    {
        if (root == nullptr) return;
        inorderTraversal(root->left, v);
        v.push_back(root->val);
        inorderTraversal(root->right, v);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> v;
        inorderTraversal(root, v);
        return v;
    }
};
