/* Program: Level Order Traversal iteratively
 * Weblink: https://leetcode.com/problems/binary-tree-level-order-traversal/
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
    void levelOrder(TreeNode *root, std::vector<std::vector<int>> &v)
    {
        std::queue<TreeNode*> q;
        int level = 0;
        if (root != nullptr) {
            q.push(root);
        }
        while (!q.empty()) {
            v.push_back(std::vector<int>{});
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode *cur = q.front();
                q.pop();
                v[level].push_back(cur->val);
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
            level++;
        }
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> v;
        levelOrder(root, v);
        return v;
    }
};
