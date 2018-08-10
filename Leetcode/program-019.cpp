#include <iostream>

/*

Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.

Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?

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

    int remove(ListNode *head, int n)
    {
        if(head == NULL)
            return 0;
        int count = 1 + remove(head->next, n);

        if(count == (n + 1))
        {
            ListNode *next = head->next;
            head->next = next->next;
            delete next;
        }

        return count;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *start = new ListNode(0);
        start->next = head;
        remove(start, n);
        ListNode *curr = start->next;
        delete start;
        return curr;
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
    ListNode *list;
    list = new ListNode(1);
    list->next = new ListNode(2);
    list->next->next = new ListNode(3);
    list->next->next->next = new ListNode(4);
    list->next->next->next->next = new ListNode(5);

    std::cout << "Original list" << std::endl;
    printNode(list);

    ListNode *removed = s.removeNthFromEnd(list, 2);
    std::cout << "Removed list" << std::endl;
    printNode(removed);

    removed = s.removeNthFromEnd(list, 1);
    std::cout << "Removed list" << std::endl;
    printNode(removed);

    removed = s.removeNthFromEnd(list, 3);
    std::cout << "Removed list" << std::endl;
    printNode(removed);

    return 0;
}
