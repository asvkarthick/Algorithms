#include <iostream>
#include <stack>
#include <vector>

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

    void dfs(TreeNode *root, std::vector<int>& v)
    {
        if(root == nullptr)
            return;

        if(root->left == nullptr && root->right == nullptr)
            v.push_back(root->val);
        dfs(root->left, v);
        dfs(root->right, v);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        std::vector<int> v1;
        std::vector<int> v2;

        dfs(root1, v1);
        dfs(root2, v2);

        std::cout << "Vector-1" << std::endl;
        for(auto elem : v1)
            std::cout << elem << std::endl;
        std::cout << "Vector-2" << std::endl;
        for(auto elem : v2)
            std::cout << elem << std::endl;

        if(v1.size() != v2.size())
            return false;

        for(int i = 0; i < v1.size(); i++)
            if(v1[i] != v2[i])
                return false;

        return true;
    }
};

int main(void)
{
    
}
