/* Program to remove duplicates in sorted linked list
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

static void removeDuplicates(Node *n)
{
    Node *head = n;
    while (head != NULL) {
        if (head->next != NULL && head->data == head->next->data) {
            auto temp = head->next;
            head->next = head->next->next;
            delete temp;
        } else {
            head = head->next;
        }
    }
}

int main(void)
{
    Node *l1;

    l1 = new Node;
    l1->data = 1;
    l1->next = new Node;
    l1->next->data = 3;
    l1->next->next = new Node;
    l1->next->next->data = 3;
    l1->next->next->next = new Node;
    l1->next->next->next->data = 9;
    l1->next->next->next->next = NULL;
    printList(l1);
    removeDuplicates(l1);
    printList(l1);

    Node *l2;
    l2 = new Node;
    l2->data = 1;
    l2->next = new Node;
    l2->next->data = 1;
    l2->next->next = new Node;
    l2->next->next->data = 1;
    l2->next->next->next = new Node;
    l2->next->next->next->data = 7;
    l2->next->next->next->next = new Node;
    l2->next->next->next->next->data = 10;
    l2->next->next->next->next->next = NULL;
    printList(l2);
    removeDuplicates(l2);
    printList(l2);

    return 0;
}
