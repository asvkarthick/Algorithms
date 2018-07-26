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

    Node *search_data(Node *node, int data)
    {
        if(node == nullptr || node->data == data)
            return node;

        if(data < node->data)
            return search_data(node->left, data);
        else
            return search_data(node->right, data);
    }

    Node *search(int x)
    {
        return search_data(root, x);
    }

    Node *search_iterative(int x)
    {
        Node *node = root;

        while(node != nullptr)
        {
            if(node->data == x)
                return node;
            else if(node->data < x)
                node = node->right;
            else
                node = node->left;
        };

        return node;
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
        t.insert(i);
        t.print();
    }

    for(int i = 9; i >= 0; i--)
    {
        Node *node = t.search(i);
        if(node != nullptr)
            std::cout << i << " found " << node->data << std::endl;
        else
            std::cout << i << " not found" << std::endl;
    }

    for(int i = 0; i < 10; i++)
    {
        Node *node = t.search_iterative(i);
        if(node != nullptr)
            std::cout << i << " found " << node->data << std::endl;
        else
            std::cout << i << " not found" << std::endl;
    }

    return 0;
}
