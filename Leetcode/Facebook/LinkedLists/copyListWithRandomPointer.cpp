/* Program: Copy List with Random Pointer
 * Weblink: 
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        Node *newHead = head;
        while (newHead != nullptr) {
            Node *t = newHead->next;
            newHead->next = new Node(newHead->val);
            newHead = newHead->next;
            newHead->next = t;
            newHead = newHead->next;
        }

        // Set random
        newHead = head;
        while (newHead != nullptr) {
            if (newHead->random != nullptr) {
                Node *r = newHead->random->next;
                newHead->next->random = r;
            } else {
                newHead->next->random = nullptr;
            }
            newHead = newHead->next->next;
        }

        // Set next properly
        newHead = head->next;
        Node *n = newHead;
        Node *oldHead = head;
        Node *n1 = oldHead;
        Node *n2 = newHead;
        while (oldHead != nullptr) {
            n1 = oldHead->next ? oldHead->next->next : nullptr;
            n2 = newHead->next ? newHead->next->next : nullptr;
            oldHead->next = n1;
            newHead->next = n2;
            oldHead = oldHead->next;
            newHead = newHead->next;
        }
        return n;
    }
};
