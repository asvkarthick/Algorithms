/* Program to create BST with sorted input array and
 * create linked list for each level
 * Breadth First Search (BFS)
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

#include <iostream>
#include <vector>
#include <map>
#include <queue>

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

struct ListNode
{
    int data;
    ListNode *next;
    ListNode(int d) : data(d), next(nullptr) {}
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

void inorder_traversal(Node *root, std::vector<int>& v)
{
    if(root == nullptr)
        return;

    inorder_traversal(root->left, v);
    v.push_back(root->data);
    inorder_traversal(root->right, v);
}

void createLinkedLists(Node *root, std::map<int, ListNode*>& nodeDepthList, int level)
{
    if (root == nullptr) return;
    ListNode *node = new ListNode(root->data);
    node->next = nodeDepthList[level];
    nodeDepthList[level] = node;
    createLinkedLists(root->left, nodeDepthList, level + 1);
    createLinkedLists(root->right, nodeDepthList, level + 1);
}

void createLinkedLists(Node *root, std::map<int, ListNode*>& nodeDepthList)
{
    createLinkedLists(root, nodeDepthList, 0);
}

void printBFS(Node *root)
{
    if (root == nullptr) return;
    std::queue<Node*> q;
    q.push(root);

    std::cout << "Printing Tree using BFS" << std::endl;
    while (!q.empty()) {
        Node* n = q.front();
        q.pop();
        std::cout << n->data << std::endl;
        if (n->left != nullptr)
            q.push(n->left);
        if (n->right != nullptr)
            q.push(n->right);
    }
}

int main(void)
{
    Node *root;
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
    int n;
    std::vector<int> v;

    n = sizeof(arr) / sizeof(arr[0]);

    root = createMinimalBST(arr, n);

    printNode(root);

    inorder_traversal(root, v);

    for(auto elem : v)
        std::cout << elem << std::endl;

    std::map<int, ListNode*> nodeDepthList;
    createLinkedLists(root, nodeDepthList);

    for (auto &x : nodeDepthList) {
        ListNode *node = x.second;
        std::cout << "Level-" << x.first << " : ";
        while (node != nullptr) {
            std::cout << node->data << " -> ";
            node = node->next;
        }
        std::cout << "NULL" << std::endl;
    }

    /* Alternate method of printing level by level */
    printBFS(root);

    return 0;
}
