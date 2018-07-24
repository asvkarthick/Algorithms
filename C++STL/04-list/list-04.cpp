#include <iostream>
#include <list>

// Simple list program to push and print elements
// This program has been written to show that the list elements cannot be accessed randomly like array
// This program will not compile as list elements cannot be accessed randomly

int main(void)
{
    std::list<int> l;
    int i;

    for(i = 0; i < 10; i++)
        l.push_back(i);

    std::cout << "Print list elements using range based for loop" << std::endl;
    for(auto x : l)
        std::cout << x << std::endl;

    std::cout << "Print list elements using iterator" << std::endl;
    for(auto x = l.begin(); x != l.end(); x++)
        std::cout << *x << std::endl;

    std::cout << "Print list elements using const iterators" << std::endl;
    for(auto x = l.cbegin(); x != l.cend(); x++)
        std::cout << *x << std::endl;

    return 0;
}
