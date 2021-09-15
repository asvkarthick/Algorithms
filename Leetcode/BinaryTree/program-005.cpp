/* Program: Maximum depth of a binary tree
 * Weblink: https://leetcode.com/explore/learn/card/data-structure-tree/17/solve-problems-recursively/535/
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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int l = maxDepth(root->left);
        int r = maxDepth(root->right);
        int d = std::max(l, r);
        return 1 + d;
    }
};
