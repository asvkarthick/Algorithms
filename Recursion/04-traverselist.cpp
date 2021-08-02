#include <iostream>

struct Node
{
    int data;
    struct Node *next;
};

static Node* findNode(Node *n, int data)
{
    if (n == NULL) return NULL;
    if (n->data == data)
        return n;
    else
        return findNode(n->next, data);
}

static void printList(Node *n)
{
    while (n != NULL) {
        std::cout << n->data;
        if (n->next != NULL) std::cout << " -> ";
        n = n->next;
    }
    std::cout << std::endl;
}

int main(void)
{
    Node *n;
    n = (Node*) malloc(sizeof(Node));
    n->data = 10;
    n->next = (Node*) malloc(sizeof(Node));
    n->next->data = 20;
    n->next->next = (Node*) malloc(sizeof(Node));
    n->next->next->data = 30;
    n->next->next->next = (Node*) malloc(sizeof(Node));
    n->next->next->next->data = 40;
    n->next->next->next->next = NULL;
    printList(n);
    std::cout << findNode(n, 20)->data << std::endl;
    return 0;
}
