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

    void AddToFront(int data)
    {
        addFront(&head, data);
    }

    void AddAfter(int after, int data)
    {
        Node *node = head;

        while(node != NULL)
        {
            if(node->data == after)
            {
                Node *curr = GetNode(data);
                curr->next = node->next;
                node->next = curr;
                break;
            }
            node = node->next;
        }
    }

    void AddAt(int index, int data)
    {
        int number_of_nodes = 0;
        Node *node = head;

        if(index == 0)
        {
            AddToFront(data);
            return;
        }

        while(node != NULL)
        {
            ++number_of_nodes;
            if(number_of_nodes == index)
            {
                Node *curr = GetNode(data);
                curr->next = node->next;
                node->next = curr;
                return;
            }
            node = node->next;
        }

        if(number_of_nodes < index)
        {
            std::cout << "Number of nodes in the list is less than index" << std::endl;
            return;
        }
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

    void Delete(int data)
    {
        deleteNode(&head, data);
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
    void addFront(Node **head, int data)
    {
        Node *node = *head;
        *head = GetNode(data);
        (*head)->next = node;
    }

    bool deleteNode(Node **head, int data)
    {
        if(!head || !*head)
            return false;

        while(*head)
        {
            if((*head)->data == data)
            {
                Node *node = *head;
                *head = node->next;
                delete node;
                return true;
            }
            head = &((*head)->next);
        }

        return false;
    }

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
    s->ReverseList();
    s->PrintList();
    s->AddToFront(40);
    s->PrintList();
    s->AddAfter(20, 15);
    s->PrintList();
    s->AddAt(1, 35);
    s->PrintList();
    s->AddAt(0, 50);
    s->PrintList();
    s->AddAfter(30, 25);
    s->PrintList();
    s->Delete(25);
    s->PrintList();

    delete s;

    return 0;
}
