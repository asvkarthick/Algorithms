/* Problem: Maximum Path Sum of a Tree
 * Weblink: https://leetcode.com/problems/binary-tree-maximum-path-sum/
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
    int maxPathSum(TreeNode *root, int& maxSum)
    {
        if (root == nullptr) return 0;

        int ld = std::max(0, maxPathSum(root->left, maxSum));
        int rd = std::max(0, maxPathSum(root->right, maxSum));
        int sum = ld + rd + root->val;
        maxSum = std::max(maxSum, sum);

        return std::max(ld, rd) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        if (root == nullptr) return 0;
        maxPathSum(root, maxSum);
        return maxSum;
    }
};
