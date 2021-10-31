/* Problem: Serialize and Deserialize Binary Tree
 * Weblink: https://leetcode.com/explore/interview/card/facebook/56/design-3/271/
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
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
class Codec {
public:

    void serialize(TreeNode *root, std::string &s)
    {
        if (root == nullptr) {
            s += "N";
            return;
        }
        s += std::to_string(root->val) + ",";
        serialize(root->left, s);
        serialize(root->right, s);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        std::string s = "";
        if (root == nullptr) return s;
        serialize(root, s);
        return s;
    }

    int deserindex;
    TreeNode* helperDeserialize(std::string &s)
    {
        if (deserindex >= s.size()) return nullptr;
        if (s[deserindex] == 'N') {
            deserindex++;
            return nullptr;
        }
        int num = 0;
        bool sign = false; // false for +ve, true for -ve
        while (s[deserindex] != ',') {
            if (s[deserindex] == '-') {
                sign = true;
            } else {
                num = num * 10 + s[deserindex] - '0';
            }
            deserindex++;
        }
        deserindex++; // for comma
        if (sign) num = -1 * num;

        TreeNode *root = new TreeNode(num);
        root->left = helperDeserialize(s);
        root->right = helperDeserialize(s);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        deserindex = 0;
        return helperDeserialize(data);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
