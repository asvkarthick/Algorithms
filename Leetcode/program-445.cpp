#include <iostream>
#include <stack>

/*

You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7

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
    int countNodes(ListNode *head)
    {
        int count = 0;

        while(head != NULL)
        {
            ++count;
            head = head->next;
        }

        return count;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        std::stack<int> s1, s2, s3;
        ListNode *list1 = l1;
        ListNode *list2 = l2;

        while(list1 != nullptr)
        {
            s1.push(list1->val);
            list1 = list1->next;
        }
        while(list2 != nullptr)
        {
            s2.push(list2->val);
            list2 = list2->next;
        }

        int sum = 0, carry = 0;
        while(!s1.empty() && !s2.empty())
        {
            sum = s1.top() + s2.top() + carry;
            s1.pop();
            s2.pop();
            carry = sum / 10;
            sum = sum % 10;
            s3.push(sum);
        }

        while(!s1.empty())
        {
            sum = s1.top() + carry;
            s1.pop();
            carry = sum / 10;
            sum = sum % 10;
            s3.push(sum);
        }

        while(!s2.empty())
        {
            sum = s2.top() + carry;
            s2.pop();
            carry = sum / 10;
            sum = sum % 10;
            s3.push(sum);
        }

        if(carry)
            s3.push(carry);

        ListNode *start = new ListNode(0);
        ListNode *node = start;
        while(!s3.empty())
        {
            node->next = new ListNode(s3.top());
            s3.pop();
            node = node->next;
        }
        node = start->next;
        delete start;
        return node;
    }
};

void printNode(ListNode *head)
{
    while(head != NULL)
    {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "NULL" << std::endl;
}

int main(void)
{
    Solution s;
    ListNode *list1;
    ListNode *list2;

    list1 = new ListNode(7);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);
    list1->next->next->next = new ListNode(3);

    list2 = new ListNode(5);
    list2->next = new ListNode(6);
    list2->next->next = new ListNode(4);

    std::cout << "List-1" << std::endl;
    printNode(list1);
    std::cout << "List-2" << std::endl;
    printNode(list2);

    ListNode *list3 = s.addTwoNumbers(list1, list2);

    std::cout << "Added list" << std::endl;
    printNode(list3);

    return 0;
}
