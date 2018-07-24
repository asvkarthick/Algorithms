#include <iostream>
#include <unordered_set>

// Simple unordered_set program to insert and print elements
// This program demonstrates that the order of elements that stored in
// the unordered set is random

int main(void)
{
    std::unordered_set<int> s;
    int i;

    for(i = 10; i > 0; i--)
    {
        std::cout << "Insert " << i << std::endl;
        s.insert(i);
    }

    for(auto x : s)
        std::cout << x << std::endl;

    std::cout << "Inserting an element again" << std::endl;
    // Adding one more element to the set
    s.insert(i);

    for(auto x : s)
        std::cout << x << std::endl;

    return 0;
}
