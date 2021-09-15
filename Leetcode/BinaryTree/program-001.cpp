/* Program: Has tree path sum equals targetsum
 * Weblink: https://leetcode.com/explore/learn/card/data-structure-tree/17/solve-problems-recursively/537/
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
    bool hasPathSum(TreeNode* root, int targetSum, int currentSum)
    {
        if (root == nullptr) return false;
        if (targetSum == currentSum + root->val && root->left == nullptr && root->right == nullptr) return true;
        return hasPathSum(root->left, targetSum, currentSum + root->val) ||
            hasPathSum(root->right, targetSum, currentSum + root->val);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return hasPathSum(root, targetSum, 0);
    }
};
