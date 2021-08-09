/* Program to find if a given binary tree is symmetric or not
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
    bool checkSymmetry(TreeNode *root1, TreeNode *root2)
    {
        if (root1 == nullptr && root2 == nullptr) return true;
        if (root1 == nullptr || root2 == nullptr) return false;
        return (root1->val == root2->val) &&
            checkSymmetry(root1->right, root2->left) &&
            checkSymmetry(root1->left, root2->right);
    }
    bool isSymmetric(TreeNode* root) {
        return checkSymmetry(root, root);
    }
};
