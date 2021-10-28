/* Problem: Delete a node in BST
 * Weblink: https://leetcode.com/explore/learn/card/introduction-to-data-structure-binary-search-tree/141/basic-operations-in-a-bst/1006/
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
    TreeNode* inorderSuccessor(TreeNode *root)
    {
        root = root->right;
        while (root != nullptr && root->left != nullptr) {
            root = root->left;
        }
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return root;

        if (root->val == key) {
            if (root->left == nullptr) {
                return root->right;
            }
            if (root->right == nullptr) {
                return root->left;
            }
            TreeNode *p = inorderSuccessor(root);
            root->val = p->val;
            root->right = deleteNode(root->right, p->val);
        } else {
            if (root->val < key) {
                root->right = deleteNode(root->right, key);
            } else {
                root->left = deleteNode(root->left, key);
            }
        }
        return root;
    }
};
