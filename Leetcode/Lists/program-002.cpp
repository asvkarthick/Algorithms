/* Program to find if the list is circular
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
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
        ListNode *slow = head;
        ListNode *fast = head;
        if (head == NULL) return false;
        fast = fast->next;
        while (slow != NULL && fast != NULL && fast->next != NULL) {
            if (slow == fast || slow == fast->next) return true;
            slow = slow->next;
            fast = fast->next->next;
        }
        return false;
    }
};
