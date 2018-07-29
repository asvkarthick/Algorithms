#include <iostream>

/*

Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5

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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *prev = NULL, *node = head, *curr;
        
        if(head == nullptr)
            return nullptr;
        
        while(node != nullptr) {
            if(node->val == val) {
                if(prev == NULL) {
                    head = node->next;
                    node = node->next;
                } else {
                    prev->next = node->next;
                    curr = node;
                    node = node->next;
                    delete curr;
                }
            } else {
                prev = node;
                node = node->next;
            }
        };
        
        return head;
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

    head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(6);

    std::cout << "Original list:" << std::endl;
    s.printNodes(head);

    ListNode *node = s.removeElements(head, 6);
    std::cout << "List after removing 6:" << std::endl;
    s.printNodes(node);

    return 0;
}
