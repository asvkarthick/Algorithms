/* Problem: Flatten Binary Tree to a Linked List
 * Weblink: https://leetcode.com/explore/interview/card/facebook/52/trees-and-graphs/322/
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
    void flatten(TreeNode* root) {
        TreeNode *node = root;

        while (node != nullptr) {
            if (node->left != nullptr) {
                TreeNode *rightMost = node->left;
                while (rightMost->right != nullptr) {
                    rightMost = rightMost->right;
                }
                rightMost->right = node->right;
                node->right = node->left;
                node->left = nullptr;
            }
            node = node->right;
        }
    }
};
