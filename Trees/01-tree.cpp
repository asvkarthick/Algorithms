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

    void insert(int data)
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

    void inorder_traverse(Node *node)
    {
        if(node == nullptr)
            return;

        inorder_traverse(node->left);
        std::cout << node->data << " " ;
        inorder_traverse(node->right);
    }

    void preorder_traverse(Node *node)
    {
        if(node == nullptr)
            return;

        std::cout << node->data << " ";
        preorder_traverse(node->left);
        preorder_traverse(node->right);
    }

    void postorder_traverse(Node *node)
    {
        if(node == nullptr)
            return;

        postorder_traverse(node->left);
        postorder_traverse(node->right);
        std::cout << node->data << " ";
    }

    void print()
    {
        std::cout << "Inorder: ";
        inorder_traverse(root);
        std::cout << std::endl;

        std::cout << "Preorder: ";
        preorder_traverse(root);
        std::cout << std::endl;

        std::cout << "Postorder: ";
        postorder_traverse(root);
        std::cout << std::endl;
    }

    void delete_node(int data)
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

        t.insert(data);
        t.print();
    }

    return 0;
}
