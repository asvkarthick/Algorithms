#include <iostream>

/*

Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
Follow up: Recursive solution is trivial, could you do it iteratively?

*/

using namespace std;

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
    vector<int> output;
    void inorderTraverse(TreeNode *root)
    {
        if(root == nullptr)
            return;

        inorderTraverse(root->left);
        output.push_back(root->val);
        inorderTraverse(root->right);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        inorderTraverse(root);
        return output;
    }
};
