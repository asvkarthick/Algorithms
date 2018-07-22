#include <iostream>

class Node
{
public:
    Node() = delete;

    Node(int d) : next(nullptr), data(d) {}

    Node *next;
    int data;
};

class SingleLinkedList
{
public:
    SingleLinkedList() : head(nullptr) {}

    Node *GetNode(int data)
    {
        return new Node(data);
    }

    void PrintList()
    {
        Node *node = head;

        while(node != nullptr)
        {
            std::cout << node->data << " -> ";
            node = node->next;
        }
        std::cout << "NULL" << std::endl;
    }

    void AddNode(int data)
    {
        Node *node = GetNode(data);

        if(head == nullptr)
        {
            head = node;
        }
        else
        {
            tail->next = node;
        }
        tail = node;
    }

    ~SingleLinkedList()
    {
        Node *prev, *node = head;

        while(node != nullptr)
        {
            prev = node;
            node = node->next;
            delete prev;
        }

        head = tail = nullptr;
    }

private:
    Node *head;
    Node *tail;
};

int main(void)
{
    SingleLinkedList *s;

    s = new SingleLinkedList();

    s->AddNode(10);
    s->AddNode(20);
    s->AddNode(30);
    s->PrintList();

    delete s;

    return 0;
}
