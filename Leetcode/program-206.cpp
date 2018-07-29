#include <iostream>

/*

Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL

Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both?

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL, *curr = head, *node = head;
        
        while(node != NULL) {
            curr = node->next;
            node->next = prev;
            prev = node;
            node = curr;
        };
        
        return prev;
    }

    void printNodes(ListNode* head)
    {
        while(head != nullptr) {
            std::cout << head->val << " -> ";
            head = head->next;
        }
        std::cout << "NULL" << std::endl;
    }
};

int main(void)
{
    Solution s;
    ListNode *head;

    head = new ListNode(10);
    head->next = new ListNode(20);
    head->next->next = new ListNode(30);
    head->next->next->next = new ListNode(40);
    head->next->next->next->next = new ListNode(50);

    std::cout << "Original list:" << std::endl;
    s.printNodes(head);

    ListNode *reverse = s.reverseList(head);
    std::cout << "Reversed list:" << std::endl;
    s.printNodes(reverse);

    return 0;
}
