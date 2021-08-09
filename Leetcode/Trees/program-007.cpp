/* Program to print level order traversals
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

#include <iostream>
#include <vector>

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

Tree* createBinaryTree(std::vector<int>& nums, int start, int end)
{
    if (start > end) return NULL;
    int mid = (start + end) / 2;
    Tree *t = new Tree;
    t->data = nums[mid];
    t->left = createBinaryTree(nums, start, mid - 1);
    t->right = createBinaryTree(nums, mid + 1, end);
    return t;
}

Tree* createBinaryTree(std::vector<int> &nums)
{
    return createBinaryTree(nums, 0, nums.size() - 1);
}

static int treeHeight(Tree *t)
{
    if (t == nullptr) return 0;
    return std::max(treeHeight(t->left), treeHeight(t->right)) + 1;
}

void printLevels(std::vector<std::vector<int>>& v)
{
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            std::cout << v[i][j] << " - ";
        }
	std::cout << std::endl;
    }
}

void fillLevels(Tree *t, std::vector<std::vector<int>>& v, int level)
{
    if (t == nullptr) return;
    v[level].push_back(t->data);
    fillLevels(t->left, v, level + 1);
    fillLevels(t->right, v, level + 1);
}

std::vector<std::vector<int>> levelOrder(Tree *t)
{
    std::vector<std::vector<int>> v;
    int height = treeHeight(t);
    for (int i = 0; i < height; i++) {
        v.push_back(std::vector<int>{});
    }
    fillLevels(t, v, 0);
    return v;
}

int main(void)
{
    std::vector<int> v;
    for (int i = 1; i < 16; i++) v.push_back(i);
    for (auto x : v) std::cout << x << std::endl;

    Tree *t = createBinaryTree(v);

    std::cout << "Tree Height = " << treeHeight(t) << std::endl;

    std::cout << "Level order traversals" << std::endl;
    auto tv = levelOrder(t);
    printLevels(tv);

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
