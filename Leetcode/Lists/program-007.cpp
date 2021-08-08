/* Program to remove Nth element from the end of the list
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) return NULL;
        ListNode *start = head;
        ListNode *startPlusN = head;
        /* Move 'n' positions from the start of the list */
        while (startPlusN && n--) {
            startPlusN = startPlusN->next;
        }
        /* Now move startPlusN till end so that start will now be at nth pos when startPlusN at end */
        ListNode *prev = NULL;
        while (startPlusN != NULL) {
            prev = start;
            start = start->next;
            startPlusN = startPlusN->next;
        }
        if (prev) {
            prev->next = start->next;
        } else {
            head = head->next;
        }
        return head;
    }
};
