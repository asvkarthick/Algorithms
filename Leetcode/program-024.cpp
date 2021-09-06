/* Program-024 : Swap nodes in pairs
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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode();
        ListNode* start = dummy;
        start->next = head;
        while (head != nullptr && head->next != nullptr) {
            auto tmp = head->next->next;
            head->next->next = head;
            start->next = head->next;
            head->next = tmp;
            head = tmp;
            start = start->next->next;
        }
        return dummy->next;
    }
};
