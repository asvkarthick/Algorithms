/* Implement of binary tree and traversals
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

#include <iostream>

struct Tree
{
    int data;
    Tree *left;
    Tree *right;
};

static void inOrder(Tree *t)
{
   if (t == nullptr) return;
   inOrder(t->left);
   std::cout << t->data << " - ";
   inOrder(t->right);
}

static void preOrder(Tree *t)
{
    if (t == nullptr) return;
    std::cout << t->data << " - ";
    preOrder(t->left);
    preOrder(t->right);
}

static void postOrder(Tree *t)
{
    if (t == nullptr) return;
    postOrder(t->left);
    postOrder(t->right);
    std::cout << t->data << " - ";
}

int main(void)
{
    Tree *t;
    t = new Tree;
    t->data = 8;
    t->left = new Tree;
    t->right = new Tree;
    t->left->data = 4;
    t->left->left = new Tree;
    t->left->right = new Tree;
    t->left->left->data = 2;
    t->left->left->left = new Tree;
    t->left->left->right = new Tree;
    t->left->left->left->data = 1;
    t->left->left->left->left = nullptr;
    t->left->left->left->right = nullptr;
    t->left->left->right->data = 3;
    t->left->left->right->left = nullptr;
    t->left->left->right->right = nullptr;
    t->left->right->data = 6;
    t->left->right->left = new Tree;
    t->left->right->right = new Tree;
    t->left->right->left->data = 5;
    t->left->right->left->left = nullptr;
    t->left->right->left->right = nullptr;
    t->left->right->right->data = 7;
    t->left->right->right->left = nullptr;
    t->left->right->right->right = nullptr;
    t->right->data = 12;
    t->right->left = new Tree;
    t->right->right = new Tree;
    t->right->left->data = 10;
    t->right->left->left = new Tree;
    t->right->left->right = new Tree;
    t->right->left->left->data = 9;
    t->right->left->left->left = nullptr;
    t->right->left->left->right = nullptr;
    t->right->left->right->data = 11;
    t->right->left->right->left = nullptr;
    t->right->left->right->right = nullptr;
    t->right->right->data = 14;
    t->right->right->left = new Tree;
    t->right->right->right = new Tree;
    t->right->right->left->data = 13;
    t->right->right->left->left = nullptr;
    t->right->right->left->right = nullptr;
    t->right->right->right->data = 15;
    t->right->right->right->left = nullptr;
    t->right->right->right->right = nullptr;

    std::cout << "Inorder traversal" << std::endl;
    inOrder(t);
    std::cout << std::endl;

    std::cout << "Preorder traversal" << std::endl;
    preOrder(t);
    std::cout << std::endl;

    std::cout << "Postorder traversal" << std::endl;
    postOrder(t);
    std::cout << std::endl;

    return 0;
}
