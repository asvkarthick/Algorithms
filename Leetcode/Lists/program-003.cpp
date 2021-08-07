/* Program to add two linked list from left to right
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

#include <iostream>

struct Node
{
    int data;
    Node *next;
};

Node* addList(Node *l1, Node *l2, int carry = 0)
{
    Node *node = NULL;
    if (!l1 && !l2 && !carry) return node;
    node = new Node;
    int data1 = l1 ? l1->data : 0;
    int data2 = l2 ? l2->data : 0;
    int data = data1 + data2 + carry;
    carry = data / 10;
    node->data = data % 10;
    node->next = addList(l1 ? l1->next : NULL, l2 ? l2->next : NULL, carry);
    return node;
}

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

int main(void)
{
    Node *l1, *l2;

    l1 = new Node;
    l1->data = 1;
    l1->next = new Node;
    l1->next->data = 2;
    l1->next->next = new Node;
    l1->next->next->data = 3;
    l1->next->next->next = NULL;

    l2 = new Node;
    l2->data = 5;
    l2->next = new Node;
    l2->next->data = 6;
    l2->next->next = new Node;
    l2->next->next->data = 7;
    l2->next->next->next = NULL;

    printList(l1);
    printList(l2);
    printList(addList(l1, l2));

    return 0;
}
