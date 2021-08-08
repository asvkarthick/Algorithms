/* Program to do list pivoting
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

static Node* listPivot(Node *n, int pivot)
{
    Node *l1, *l2, *l3;
    l1 = new Node;
    l2 = new Node;
    l3 = new Node;
    l1->next = NULL;
    l2->next = NULL;
    l3->next = NULL;
    Node *list1 = l1;
    Node *list2 = l2;
    Node *list3 = l3;

    Node *head = n;
    while (head != NULL) {
        if (head->data < pivot) {
            l1->next = head;
            l1 = l1->next;
        } else if (head->data == pivot) {
            l2->next = head;
            l2 = l2->next;
        } else {
            l3->next = head;
	    l3 = l3->next;
	}
        head = head->next;
    }
    l1->next = list2->next;
    l2->next = list3->next;
    l3->next = NULL;
    return list1->next;
}

int main(void)
{
    Node *l1;

    l1 = new Node;
    l1->data = 1;
    l1->next = new Node;
    l1->next->data = 3;
    l1->next->next = new Node;
    l1->next->next->data = 2;
    l1->next->next->next = new Node;
    l1->next->next->next->data = 9;
    l1->next->next->next->next = NULL;
    printList(l1);
    printList(listPivot(l1, 2));

    Node *l2;
    l2 = new Node;
    l2->data = 1;
    l2->next = new Node;
    l2->next->data = 2;
    l2->next->next = new Node;
    l2->next->next->data = 5;
    l2->next->next->next = new Node;
    l2->next->next->next->data = 7;
    l2->next->next->next->next = new Node;
    l2->next->next->next->next->data = 1;
    l2->next->next->next->next->next = NULL;
    printList(l2);
    printList(listPivot(l2, 5));

    return 0;
}
