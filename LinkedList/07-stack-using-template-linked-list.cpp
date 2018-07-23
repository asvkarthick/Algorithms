#include <iostream>

template<typename T>
class Node
{
public:
    Node() = delete;

    Node(T d) : next(nullptr), data(d) {}

    Node *next;
    T data;
};

template<typename T>
class Stack
{
public:
    Stack() : head(nullptr) {}

    Node<T> *GetNode(int data)
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

    void Push(T data)
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

    T Pop()
    {
        T data;
        Node<T> *prev, *node = head;

        if(!head)
            return -1;

        // If there is only one node in the list
        if(node->next == nullptr)
        {
            data = node->data;
            delete node;
            head = tail = nullptr;
            return data;
        }

        while(node->next != nullptr)
        {
            prev = node;
            node = node->next;
        }
        data = node->data;
        tail = prev;
        prev->next = nullptr;
        delete node;

        return data;
    }

    ~Stack()
    {
        Node<T> *prev, *node = head;

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

    Node<T> *head;
    Node<T> *tail;
};

int main(void)
{
    Stack<int> *s;
    int data;

    s = new Stack<int>();

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
    data = s->Pop();
    std::cout << "Popped: " << data << std::endl;
    s->PrintList();
    data = s->Pop();
    std::cout << "Popped: " << data << std::endl;
    s->PrintList();
    data = s->Pop();
    std::cout << "Popped: " << data << std::endl;
    s->PrintList();

    delete s;

    return 0;
}
