#include <iostream>

class Node
{
public:
    Node() = delete;

    Node(int d) : next(nullptr), data(d) {}

    Node *next;
    int data;
};

class Stack
{
public:
    Stack() : head(nullptr) {}

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

    void Push(int data)
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

    int Pop()
    {
        int data;

        if(head)
            data = head->data;
        else
            return -1;

        deleteNode(&head);
        return data;
    }

    ~Stack()
    {
        Node *prev, *node = head;

        while(node != nullptr)
        {
            prev = node;
            node = node->next;
            std::cout << "Deleting " << prev->data << std::endl;
            delete prev;
        }

        head = tail = nullptr;
    }

private:

    bool deleteNode(Node **head)
    {
        Node *node;

        if(!head || !*head)
            return false;

        node = *head;
        *head = node->next;
        delete node;

        return true;
    }

    Node *head;
    Node *tail;
};

int main(void)
{
    Stack *s;
    int data;

    s = new Stack();

    s->Push(10);
    s->Push(20);
    s->Push(30);
    s->PrintList();
    s->Push(40);
    s->Push(50);
    s->PrintList();

    data = s->Pop();
    std::cout << "Popped: " << data << std::endl;
    data = s->Pop();
    std::cout << "Popped: " << data << std::endl;
    s->PrintList();

    delete s;

    return 0;
}
