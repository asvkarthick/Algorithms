/* Program: Reorder Lists
 * Weblink: https://leetcode.com/explore/interview/card/facebook/6/linked-list/3021/
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        std::stack<ListNode*> s;
        ListNode *l = head;
        int numNodes = 0;
        while (l != nullptr) {
            s.push(l);
            l = l->next;
            ++numNodes;
        }

        l = head;
        for (int i = 0; i < numNodes / 2; i++) {
            ListNode *t = l->next;
            l->next = s.top();
            s.pop();
            l = l->next;
            l->next = t;
            l = l->next;
        }
        if (numNodes % 2) {
            l->next = s.top();
            s.pop();
            l = l->next;
        }
        l->next = nullptr;
    }
};
