/* Problem: Binary Tree Vertical Order Traversal
 * Weblink: https://leetcode.com/problems/binary-tree-vertical-order-traversal/
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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        std::map<int, std::vector<int>> hashMap;
        std::queue<std::pair<TreeNode*, int>> q;

        if (root == nullptr) return std::vector<std::vector<int>> {};

        int column = 0;
        q.push(std::make_pair(root, column));
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            TreeNode *node = p.first;
            column = p.second;
            if (node != nullptr) {
                hashMap[column].push_back(node->val);
                q.push(std::make_pair(node->left, column - 1));
                q.push(std::make_pair(node->right, column + 1));
            }
        }

        std::vector<std::vector<int>> result;
        for (auto it = hashMap.begin(); it != hashMap.end(); it++) {
            result.push_back(it->second);
        }

        return result;
    }
};
