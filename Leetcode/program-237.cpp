#include <iostream>

/*

Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

Given linked list -- head = [4,5,1,9], which looks like following:

    4 -> 5 -> 1 -> 9

Example 1:

Input: head = [4,5,1,9], node = 5
Output: [4,1,9]
Explanation: You are given the second node with value 5, the linked list
             should become 4 -> 1 -> 9 after calling your function.

Example 2:

Input: head = [4,5,1,9], node = 1
Output: [4,5,9]
Explanation: You are given the third node with value 1, the linked list
             should become 4 -> 5 -> 9 after calling your function.

Note:

    The linked list will have at least two elements.
    All of the nodes' values will be unique.
    The given node will not be the tail and it will always be a valid node of the linked list.
    Do not return anything from your function.

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
    void deleteNode(ListNode* node) {
        ListNode *next;
        next = node->next;
        node->val = node->next->val;
        node->next = node->next->next;
        delete next;
    }

    void printNodes(ListNode* head)
    {
        while(head != nullptr) {
            std::cout << head->val << " -> ";
            head = head->next;
        }
        std::cout << "NULL" << std::endl;
    }
};

int main(void)
{
    Solution s;
    ListNode *head;

    head = new ListNode(10);
    head->next = new ListNode(20);
    head->next->next = new ListNode(30);
    head->next->next->next = new ListNode(40);
    head->next->next->next->next = new ListNode(50);

    std::cout << "Original list:" << std::endl;
    s.printNodes(head);

    std::cout << "List after deleting " << head->next->next->next->val << std::endl;
    s.deleteNode(head->next->next->next);
    s.printNodes(head);

    return 0;
}
