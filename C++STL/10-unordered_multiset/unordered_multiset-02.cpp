#include <iostream>
#include <unordered_set>

// Simple set program to insert and print elements
// This program demonstrates that the order of elements that stored in
// the set is random and keeps duplicates

int main(void)
{
    std::unordered_multiset<int> s;
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

    for(auto x : s)
        std::cout << x << std::endl;

    return 0;
}
