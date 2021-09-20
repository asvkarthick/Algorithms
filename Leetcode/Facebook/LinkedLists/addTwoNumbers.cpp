/* Program: Add two numbers using linked list
 * Weblink: https://leetcode.com/explore/interview/card/facebook/6/linked-list/319/
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0, carry = 0;
        ListNode *head = new ListNode;
        ListNode *result = head;
        while (l1 != nullptr && l2 != nullptr) {
            sum = l1->val + l2->val + carry;
            l1 = l1->next;
            l2 = l2->next;
            carry = sum / 10;
            sum = sum % 10;
            result->next = new ListNode;
            result->next->val = sum;
            result = result->next;
        }
        while (l1 != nullptr) {
            sum = l1->val + carry;
            l1 = l1->next;
            carry = sum / 10;
            sum = sum % 10;
            result->next = new ListNode;
            result->next->val = sum;
            result = result->next;
        }
        while (l2 != nullptr) {
            sum = l2->val + carry;
            l2 = l2->next;
            carry = sum / 10;
            sum = sum % 10;
            result->next = new ListNode;
            result->next->val = sum;
            result = result->next;
        }
        if (carry) {
            result->next = new ListNode;
            result->next->val = carry;
        }
        return head->next;
    }
};
