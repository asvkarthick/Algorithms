#include <iostream>

template<typename T>
class Node
{
public:
    Node() = delete;

    Node(int d) : next(nullptr), data(d) {}

    Node<T> *next;
    T data;
};

template<typename T>
class SingleLinkedList
{
public:
    SingleLinkedList() : head(nullptr) {}

    Node<T> *GetNode(T data)
    {
        return new Node<T>(data);
    }

    void PrintList()
    {
        Node<T> *node = head;

        while(node != nullptr)
        {
            std::cout << node->data << " -> ";
            node = node->next;
        }
        std::cout << "NULL" << std::endl;
    }

    void AddNode(T data)
    {
        Node<T> *node = GetNode(data);

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
        Node<T> *prev, *node = head;

        while(node != nullptr)
        {
            prev = node;
            node = node->next;
            delete prev;
        }

        head = tail = nullptr;
    }

private:
    Node<T> *head;
    Node<T> *tail;
};

int main(void)
{
    SingleLinkedList<int> *s;

    s = new SingleLinkedList<int>();

    s->AddNode(10);
    s->AddNode(20);
    s->AddNode(30);
    s->PrintList();

    delete s;

    return 0;
}
