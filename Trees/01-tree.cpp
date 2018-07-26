#include <iostream>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int d) : data(d), left(nullptr), right(nullptr) {}
};

class Tree
{
public:
    Tree() : root(nullptr) {}

    void AddNode(int data)
    {
        Node *node = new Node(data);
        Node *prev, *temp = root;

        if(root == nullptr)
        {
            root = node;
            return;
        }

        while(temp != nullptr)
        {
            prev = temp;
            if(data <= temp->data)
                temp = temp->left;
            else
                temp = temp->right;
        }
        if(data <= prev->data)
            prev->left = node;
        else
            prev->right = node;
    }

    void traverse(Node *node)
    {
        if(node == nullptr)
            return;

        traverse(node->left);
        std::cout << node->data << " " ;
        traverse(node->right);
    }

    void print()
    {
        traverse(root);
        std::cout << std::endl;
    }

    void delete(int data)
    {
        Node *prev, *node = root;

        while(node != nullptr)
        {
            prev = node;
            if(node->data == data)
            {

            }
            else if(node->data > data)
            {
                node = node->left;
            }
            else
            {
                node = node->right;
            }
        }
    }

private:
    Node *root;
};

int main(void)
{
    Tree t;

    for(int i = 0; i < 10; i++)
    {
        int data;
        std::cout << "Enter data: ";
        std::cin >> data;

        t.AddNode(data);
        t.print();
    }

    return 0;
}
