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

    for(auto x : l)
        std::cout << x << std::endl;

    for(i = 0; i < l.size(); i++)
        std::cout << l[i] << std::endl;

    return 0;
}
