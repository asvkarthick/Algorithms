/* Program: Maximum Depth of a Binary Tree
 * Weblink: https://leetcode.com/explore/learn/card/recursion-i/256/complexity-analysis/2375/
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
