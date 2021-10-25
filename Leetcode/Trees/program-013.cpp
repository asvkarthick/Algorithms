/* Program: Construct Binary Tree from inorder and preorder traversal
 * Weblink: https://leetcode.com/explore/learn/card/data-structure-tree/133/conclusion/943/
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
    int pre_idx;
    std::unordered_map<int, int> hashMap;
    int *preorder;

    TreeNode* helper(int in_left, int in_right)
    {
        if (in_left > in_right)
            return nullptr;
        int root_val = preorder[pre_idx];
        TreeNode *root = new TreeNode(root_val);
        int index = hashMap[root_val];
        pre_idx++;
        root->left = helper(in_left, index - 1);
        root->right = helper(index + 1, in_right);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        pre_idx = 0;
        this->preorder = preorder.data();
        for (int i = 0; i < inorder.size(); i++) {
            hashMap[inorder[i]] = i;
        }
        return helper(0, inorder.size() - 1);
    }
};
