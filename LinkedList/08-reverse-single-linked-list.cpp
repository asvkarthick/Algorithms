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

    void PrintList(Node *head)
    {
        while(head != nullptr)
        {
            std::cout << head->data << " -> ";
            head = head->next;
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

    void ReverseList()
    {
        Node *prev, *next, *node = head;

        prev = nullptr;
        while(node != nullptr)
        {
            next = node->next;
            node->next = prev;
            prev = node;
            node = next;
        }
        head = prev;
    }       

    Node *CreateReverseList(Node *head)
    {
        if(head == nullptr)
            return nullptr;

        Node *curr = head, *reversed = nullptr;

        while(curr != nullptr)
        {
            Node *node = GetNode(curr->data);
            node->next = reversed;
            reversed = node;
            curr = curr->next;
        }
        return reversed;
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

    Node *GetHead()
    {
        return head;
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
    s->AddNode(40);
    s->AddNode(50);
    s->PrintList();
    s->ReverseList();
    s->PrintList();

    Node *original = s->GetHead();
    Node *reversed = s->CreateReverseList(original);

    std::cout << "Original list" << std::endl;
    s->PrintList(original);
    std::cout << "Reversed list" << std::endl;
    s->PrintList(reversed);

    delete s;

    return 0;
}
