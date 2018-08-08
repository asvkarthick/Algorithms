#include <iostream>

/*

Given a linked list, determine if it has a cycle in it.

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
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;

        do
        {
            if(slow == nullptr || fast == nullptr || fast->next == nullptr)
                return false;

            slow = slow->next;
            fast = fast->next;
            fast = fast->next;
        } while(slow != fast);

        return true;
    }
};
