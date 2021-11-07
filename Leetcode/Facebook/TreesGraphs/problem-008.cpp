/* Problem: Convert BST to Doubly Linked List
 * Weblink: https://leetcode.com/explore/interview/card/facebook/52/trees-and-graphs/544/
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

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    void inOrder(Node* root, std::queue<Node*>& q)
    {
        if (root == nullptr) return;
        inOrder(root->left, q);
        q.push(root);
        inOrder(root->right, q);
    }

    Node* treeToDoublyList(Node* root) {
        if (root == nullptr) return root;
        std::queue<Node*> q;

        inOrder(root, q);

        Node *node = root;
        Node *prevNode = nullptr;
        Node *head = q.front();

        while (!q.empty()) {
            node = q.front();
            q.pop();
            if (prevNode != nullptr) prevNode->right = node;
            node->left = prevNode;
            prevNode = node;
        }
        node->right = head;
        head->left = node;
        return head;
    }
};
