#include <iostream>
#include <unordered_set>

// Simple unordered set program to insert and print elements
// This program demonstrates that the order of elements that stored in
// the set is random and also removes duplicates

int main(void)
{
    std::unordered_set<int> s;
    int i;

    for(i = 10; i > 0; i--)
    {
        std::cout << "Insert " << i << std::endl;
        s.insert(i);
    }
    for(i = 10; i > 0; i--)
    {
        std::cout << "Insert " << i << std::endl;
        s.insert(i);
    }

    std::cout << "Printing set elements using range based for loop" << std::endl;
    for(auto x : s)
        std::cout << x << std::endl;

    std::cout << "Printing set elements using iterator" << std::endl;
    for(auto x = s.begin(); x != s.end(); x++)
        std::cout << *x << std::endl;

    return 0;
}
