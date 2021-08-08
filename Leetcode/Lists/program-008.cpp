/* Program to check if the linked list is palindrome
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

#include <iostream>

struct Node
{
    int data;
    Node *next;
};

static void printList(Node *n)
{
    while (n != NULL) {
        if (n->next != NULL)
            std::cout << n->data << " -> ";
        else
            std::cout << n->data << std::endl;
	n = n->next;
    }
}

static Node* reverseList(Node *n)
{
    Node *prev = NULL;
    Node *next = n, *curr = n;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool isPalindrome(Node *n)
{
    if (n == NULL) return false;
    /* Find the center of the list */
    Node *head = n;
    Node *mid = n;
    Node *slow = n, *fast = n;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    mid = reverseList(slow);
    while (head && mid && head != slow) {
        if (head->data != mid->data) return false;
        head = head->next;
        mid = mid->next;
    }
    return true;
}

int main(void)
{
    Node *l1;

    l1 = new Node;
    l1->data = 9;
    l1->next = new Node;
    l1->next->data = 0;
    l1->next->next = new Node;
    l1->next->next->data = 0;
    l1->next->next->next = new Node;
    l1->next->next->next->data = 9;
    l1->next->next->next->next = NULL;

    printList(l1);
    if (isPalindrome(l1))
        std::cout << "l1 is palindrome" << std::endl;
    else
        std::cout << "l1 is not palindrome" << std::endl;

    Node *l2;
    l2 = new Node;
    l2->data = 1;
    l2->next = new Node;
    l2->next->data = 2;
    l2->next->next = new Node;
    l2->next->next->data = 3;
    l2->next->next->next = new Node;
    l2->next->next->next->data = 2;
    l2->next->next->next->next = new Node;
    l2->next->next->next->next->data = 1;
    l2->next->next->next->next->next = NULL;

    printList(l2);
    if (isPalindrome(l2))
        std::cout << "l2 is palindrome" << std::endl;
    else
        std::cout << "l2 is not palindrome" << std::endl;

    Node *l3;
    l3 = new Node;
    l3->data = 1;
    l3->next = new Node;
    l3->next->data = 2;
    l3->next->next = new Node;
    l3->next->next->data = 3;
    l3->next->next->next = NULL;

    printList(l3);
    if (isPalindrome(l3))
        std::cout << "l3 is palindrome" << std::endl;
    else
        std::cout << "l3 is not palindrome" << std::endl;
    return 0;
}
