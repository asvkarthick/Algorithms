/* Program to right shift linked list by k
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

static Node *rightShiftList(Node *n, int k)
{
    Node *head = n;
    Node *shiftedList = n;
    while (k-- && shiftedList != NULL) {
        shiftedList = shiftedList->next;
    }
    Node *last, *prev;
    while (shiftedList != NULL) {
        last = shiftedList;
        shiftedList = shiftedList->next;
        prev = head;
        head = head->next;
    }
    last->next = n;
    prev->next = NULL;
    return head;
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
    l1 = rightShiftList(l1, 2);
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
    l2 = rightShiftList(l2, 4);
    printList(l2);

    return 0;
}
