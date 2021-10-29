/* Program: Binary Tree Right Side View
 * Weblink: https://leetcode.com/explore/interview/card/facebook/52/trees-and-graphs/3023/
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
    vector<int> rightSideView(TreeNode* root) {
        std::vector<int> v;
        if (root == nullptr) return v;
        std::queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            TreeNode *node;
            for (int i = 0; i < size; i++) {
                node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            v.push_back(node->val);
        }
        return v;
    }
};
