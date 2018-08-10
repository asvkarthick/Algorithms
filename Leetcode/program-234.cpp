#include <iostream>

/*

Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false

Example 2:

Input: 1->2->2->1
Output: true

Follow up:
Could you do it in O(n) time and O(1) space?

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool checkPalindrome(ListNode *list1)
    {
        if(list1 == NULL)
            return true;

        bool flag = checkPalindrome(list1->next);
        flag = flag & (list1->val == start->val);
        start = start->next;
        return flag;
    }

    bool isPalindrome(ListNode* head) {
        start = head;
        if(head == NULL)
            return true;

        return checkPalindrome(head);
    }
    ListNode *start;
};

int main(void)
{
    Solution s;
    ListNode *list1, *list2;

    list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(3);

    list2 = new ListNode(1);
    list2->next = new ListNode(2);
    list2->next->next = new ListNode(1);

    std::cout << s.isPalindrome(list1) << std::endl;
    std::cout << s.isPalindrome(list2) << std::endl;

    return 0;
}

