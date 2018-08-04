#include <iostream>

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = nullptr, *node, *list;
        
        if(l1 != nullptr || l2 != nullptr) {    
            head = new ListNode(0);
            node = head;
            
            while((l1 != NULL) && (l2 != NULL)) {
                if(l1->val <= l2->val) {
                    list = new ListNode(l1->val);
                    l1 = l1->next;
                }
                else {
                    list = new ListNode(l2->val);
                    l2 = l2->next;
                }
                node->next = list;
                node = node->next;
            }
            
            while(l1 != nullptr) {
                list = new ListNode(l1->val);
                node->next = list;
                node = node->next;
                l1 = l1->next;
            }
            
            while(l2 != nullptr) {
                list = new ListNode(l2->val);
                node->next = list;
                node = node->next;
                l2 = l2->next;
            }
        }
        
        if(head != nullptr) {
            list = head;
            head = head->next;
            delete list;
        }
        
        return head;
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
    ListNode *l1, *l2, *l3;

    l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);
    std::cout << "List-1" << std::endl;
    s.printNodes(l1);

    l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);
    std::cout << "List-2" << std::endl;
    s.printNodes(l2);

    l3 = s.mergeTwoLists(l1, l2);
    std::cout << "Merged list:" << std::endl;
    s.printNodes(l3);

    return 0;
}
