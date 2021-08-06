/* Program to merge two sorted array
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

#include <iostream>

struct Node
{
    int data;
    struct Node *next;
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

static Node *mergeList(Node *n1, Node *n2)
{
    Node *n = new Node;
    Node *tail = n;
    while (n1 != NULL && n2 != NULL) {
        if (n1->data < n2->data) {
            tail->next = n1;
	    n1 = n1->next;
        } else {
            tail->next = n2;
	    n2 = n2->next;
        }
        tail = tail->next;
    }
    tail->next = n1 ? n1 : n2;
    return n->next;
}

int main(void)
{
    Node *l1;
    Node *l2;
    l1 = new Node;
    l1->data = 1;
    l1->next = new Node;
    l1->next->data = 2;
    l1->next->next = new Node;
    l1->next->next->data = 2;
    l1->next->next->next = new Node;
    l1->next->next->next->data = 4;
    l1->next->next->next->next = new Node;
    l1->next->next->next->next->data = 6;
    l1->next->next->next->next->next = NULL;

    l2 = new Node;
    l2->data = 2;
    l2->next = new Node;
    l2->next->data = 3;
    l2->next->next = new Node;
    l2->next->next->data = 30;
    l2->next->next->next = NULL;

    printList(l1);
    printList(l2);
    printList(mergeList(l1, l2));
    return 0;
}
