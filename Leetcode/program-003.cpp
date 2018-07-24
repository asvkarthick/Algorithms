#include <iostream>

/*

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *last, *list = nullptr, *ln;
        int carry = 0, sum;

        while(l1 != nullptr && l2 != nullptr) {
            sum = carry + l1->val + l2->val;
            if(sum >= 10) {
                carry = 1;
                sum -= 10;
            } else {
                carry = 0;
            }
            ln = new ListNode(sum);
            if(list == nullptr)
            {
                list = last = ln;
            }
            else
            {
                last->next = ln;
                last = ln;
            }
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1 != nullptr)
        {
            sum = carry + l1->val;
            if(sum >= 10)
            {
                carry = 1;
                sum -= 10;
            }
            else
            {
                carry = 0;
            }
            ln = new ListNode(sum);
            last->next = ln;
            last = ln;
            l1 = l1->next;
        };

        while(l2 != nullptr)
        {
            sum = carry + l2->val;
            if(sum >= 10)
            {
                carry = 1;
                sum -= 10;
            }
            else
            {
                carry = 0;
            }
            ln = new ListNode(sum);
            last->next = ln;
            last = ln;
            l2 = l2->next;
        };

        if(carry)
        {
            ln = new ListNode(carry);
            last->next = ln;
            last = ln;
        }

        return list;
    }
};

int main(void)
{
    Solution s;
    ListNode l11(2), l12(4), l13(3);
    ListNode l21(5), l22(6), l23(4);
    ListNode *ln;

    l11.next = &l12;
    l12.next = &l13;
    l21.next = &l22;
    l22.next = &l23;

    ln = s.addTwoNumbers(&l11, &l21);

    while(ln != NULL)
    {
        std::cout << ln->val << " -> ";
        ln = ln->next;
    };
    std::cout << "NULL" << std::endl;

    return 0;
}
