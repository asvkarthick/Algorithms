#include <iostream>

/*

Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.

Follow up:
Can you solve it without using extra space?

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
    ListNode *detectCycle(ListNode *head) {
        // Using Floyd Cycle Detection algorithm
        ListNode *slow = head, *fast = head;

        do
        {
            if(slow == nullptr || fast == nullptr || fast->next == nullptr)
                return NULL;

            slow = slow->next;
            fast = fast->next;
            fast = fast->next;
        } while(slow != fast);

        // Move slow to the start position
        slow = head;
        while(slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};
