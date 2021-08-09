/* Program to convert sorted array to Binary search tree
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
    TreeNode* sortedArrayToBST(vector<int>& nums, int start, int end)
    {
        if (start > end) return NULL;
        int mid = (start + end) / 2;
        TreeNode *t = new TreeNode(nums[mid]);
        t->left = sortedArrayToBST(nums, start, mid - 1);
        t->right = sortedArrayToBST(nums, mid + 1, end);
        return t;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size() - 1);
    }
};
