#include <iostream>

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

void print(Node *root, int level)
{
    if(root == nullptr)
        return;

    print(root->left, level + 1);
    std::cout << "Level = " << level << " Data = " << root->data << std::endl;
    print(root->right, level + 1);
}

void printNode(Node *root)
{
    print(root, 0);
}

int main(void)
{
    Node *root;
    Node *node;

    root = new Node(8);
    root->left = new Node(4);
    root->right = new Node(12);

    node = root->left;
    node->left = new Node(2);
    node->right = new Node(6);

    node = root->right;
    node->left = new Node(10);
    node->right = new Node(14);

    node = root->left->left;
    node->left = new Node(1);
    node->right = new Node(3);

    node = root->left->right;
    node->left = new Node(5);
    node->right = new Node(7);

    node = root->right->left;
    node->left = new Node(9);
    node->right = new Node(11);

    node = root->right->right;
    node->left = new Node(13);
    node->right = new Node(15);

    printNode(root);

    return 0;
}
