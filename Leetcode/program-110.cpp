#include <iostream>

/*

Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

    a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example 1:

Given the following tree [3,9,20,null,null,15,7]:

    3
   / \
  9  20
    /  \
   15   7

Return true.

Example 2:

Given the following tree [1,2,2,3,3,null,null,4,4]:

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4

Return false.

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int height(TreeNode *root)
    {
        if(!root)
            return 0;
        int left_height, right_height;
        
        left_height = height(root->left);
        if(left_height == -1)
            return -1;
        
        right_height = height(root->right);
        if(right_height == -1)
            return -1;
        
        if((left_height - right_height) < -1 || (left_height - right_height) > 1)
            return -1;
        
        return 1 + std::max(left_height, right_height);
    }
    
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        return height(root) != -1;
    }
};

int main(void)
{
    Solution s;

    return 0;
}
