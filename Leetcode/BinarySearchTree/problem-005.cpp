/* Program: Insert into BST
 * Weblink: https://leetcode.com/explore/learn/card/introduction-to-data-structure-binary-search-tree/141/basic-operations-in-a-bst/1003/
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) return new TreeNode(val);
        TreeNode *cur = root;
        TreeNode *prev = root;
        while (cur != nullptr) {
            prev = cur;
            if (cur->val > val) {
                cur = cur->left;
                if (cur == nullptr) prev->left = new TreeNode(val);
            } else {
                cur = cur->right;
                if (cur == nullptr) prev->right = new TreeNode(val);
            }
        }
        return root;
    }
};
