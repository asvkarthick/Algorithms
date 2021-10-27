/* Program: Validate BST
 * Weblink: https://leetcode.com/explore/learn/card/introduction-to-data-structure-binary-search-tree/140/introduction-to-a-bst/997/
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
    bool validate(TreeNode *root, TreeNode *low, TreeNode *high)
    {
        if (root == nullptr) return true;
        if ((low != nullptr && low->val >= root->val) || (high != nullptr && high->val <= root->val))
            return false;
        return validate(root->left, low, root) && validate(root->right, root, high);
    }
    bool isValidBST(TreeNode* root) {
        return validate(root, nullptr, nullptr);
    }
};
