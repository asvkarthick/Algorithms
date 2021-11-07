/* Problem: Clone Graph
 * Weblink: https://leetcode.com/problems/clone-graph/
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        Node *head = nullptr;
        std::queue<Node*> q;
        std::unordered_map<Node*, Node*> processed;

        if (node == nullptr) return node;

        q.push(node);
        head = new Node(node->val);
        processed[node] = head;

        while (!q.empty()) {
            Node *tmp = q.front();
            q.pop();

            Node *newNode = processed[tmp];
            for (auto x : tmp->neighbors) {
                if (processed.find(x) == processed.end()) {
                    processed[x] = new Node(x->val);
                    q.push(x);
                }
                newNode->neighbors.push_back(processed[x]);
            }
        }

        return head;
    }
};
