/* Program: Count Univalue Subtrees
 * Weblink: https://leetcode.com/problems/count-univalue-subtrees/
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
    bool countUnivalSubtrees(TreeNode* root, int &count)
    {
        if (root == nullptr) return true;
        if (root->left == nullptr && root->right == nullptr) {
            count++;
            return true;
        }
        bool lval = countUnivalSubtrees(root->left, count);
        bool rval = countUnivalSubtrees(root->right, count);
        if (lval && rval) {
            if (root->left && root->right && root->val == root->left->val && root->val == root->right->val) {
                count++;
                return true;
            } else if (root->left && root->right && (root->val != root->left->val || root->val != root->right->val)) {
                return false;
            } else if (root->left && root->val == root->left->val) {
                count++;
                return true;
            } else if (root->right && root->val == root->right->val) {
                count++;
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
    int countUnivalSubtrees(TreeNode* root) {
        if (root == nullptr) return 0;
        int count = 0;
        countUnivalSubtrees(root, count);
        return count;
    }
};
