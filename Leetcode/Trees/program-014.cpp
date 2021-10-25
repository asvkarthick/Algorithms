/* Program: Populating next right pointers in each node
 * Weblink: https://leetcode.com/explore/learn/card/data-structure-tree/133/conclusion/994/
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* helper(Node *root)
    {
        std::queue<Node*> q;
        if (root) {
            q.push(root);
        }

        while (!q.empty()) {
            int size = q.size();
            Node *curr, *prev = nullptr;
            for (int i = 0; i < size; i++) {
                curr = q.front();
                q.pop();
                if (prev != nullptr) prev->next = curr;
                prev = curr;
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            curr->next = nullptr;
        }
        return root;
    }
    Node* connect(Node* root) {
        if (root == nullptr) return root;
        return helper(root);
    }
};
