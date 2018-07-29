#include <iostream>

/*

Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 ≤ m ≤ n ≤ length of list.

Example:

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int number_of_nodes = n - m + 1;
        ListNode *node = head;
        int count = 1;
        ListNode *first, *second, *curr, *prev = NULL;
        
        while(node != NULL && count != m) {
            prev = node;
            node = node->next;
            ++count;
        };
        
        first = prev;
        second = node;
        
        while(node != NULL && number_of_nodes--) {
            curr = node;
            node = node->next;
            curr->next = prev;
            prev = curr;
        }
        
        if(m == 1)
            head = prev;
        
        if(first)
            first->next = prev;
        second->next = node;
        
        return head;
    }
};
