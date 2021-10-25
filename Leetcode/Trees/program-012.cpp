/* Program: Construct Binary Tree from inorder and postorder traversal
 * Weblink: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
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
    int post_idx;
    int *postorder;
    std::unordered_map<int, int> hashMap;

    TreeNode* helper(int in_left, int in_right)
    {
        if (in_left > in_right)
            return nullptr;
        int root_val = postorder[post_idx];
        TreeNode *root = new TreeNode(root_val);
        int index = hashMap[root_val];
        post_idx--;
        root->right = helper(index + 1, in_right);
        root->left = helper(in_left, index - 1);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        post_idx = postorder.size() - 1;
        this->postorder = postorder.data();
        for (int i = 0; i < inorder.size(); i++) {
            hashMap[inorder[i]] = i;
        }
        return helper(0, inorder.size() - 1);
    }
};
