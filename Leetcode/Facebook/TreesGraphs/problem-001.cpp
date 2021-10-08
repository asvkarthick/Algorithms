/* Problem: Iterator for inorder traversal
 * Weblink: https://leetcode.com/problems/binary-search-tree-iterator/
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
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        traverseLeft(root);
    }

    void traverseLeft(TreeNode *root)
    {
        while (root != nullptr) {
            mStack.push(root);
            root = root->left;
        }
    }

    int next() {
        TreeNode* node = mStack.top();
        mStack.pop();
        if (node->right)
            traverseLeft(node->right);
        return node->val;
    }

    bool hasNext() {
        return mStack.size() != 0;
    }
private:
    std::stack<TreeNode*> mStack;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
