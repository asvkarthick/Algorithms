/* Program: Inorder successor in BST
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void next(TreeNode *root, TreeNode *p, bool &flag, TreeNode **result)
    {
        if (root == nullptr) {
            return;
        }
        next(root->left, p, flag, result);
        if (flag) {
            *result = root;
            flag = false;
            return;
        }
        if (root == p) {
            flag = true;
        }
        next(root->right, p, flag, result);
    }
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        bool flag = false;
        TreeNode *result = nullptr;
        next(root, p, flag, &result);
        return result;
    }
};
