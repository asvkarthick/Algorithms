#include <iostream>

// Program to create BST with sorted input array and
// to print all the nodes with the level of the nodes

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

Node *createMinimalBST(int *arr, int start, int end)
{
    int mid;

    if(start > end)
        return nullptr;

    mid = (start + end) / 2;
    Node *node = new Node(arr[mid]);
    node->left = createMinimalBST(arr, start, mid - 1);
    node->right = createMinimalBST(arr, mid + 1, end);

    return node;
}

Node *createMinimalBST(int *arr, int n)
{
    return createMinimalBST(arr, 0, n - 1);
}

int main(void)
{
    Node *root;
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
    int n;

    n = sizeof(arr) / sizeof(arr[0]);

    root = createMinimalBST(arr, n);

    printNode(root);

    return 0;
}
