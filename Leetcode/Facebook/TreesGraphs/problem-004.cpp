/* Problem: Diameter of Binary Tree
 * Weblink: 
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
    int computeDiameter(TreeNode *root, int& diameter)
    {
        if (root == nullptr) return 0;
        int ld = computeDiameter(root->left, diameter);
        int rd = computeDiameter(root->right, diameter);
        if (ld + rd > diameter) {
            diameter = ld + rd;
        }
        return std::max(ld, rd) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        if (root != nullptr) {
            computeDiameter(root, diameter);
        }
        return diameter;
    }
};
