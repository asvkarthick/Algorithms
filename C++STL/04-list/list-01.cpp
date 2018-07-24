#include <iostream>
#include <list>

// Simple list program to push and print elements

int main(void)
{
    std::list<int> l;
    int i;

    for(i = 0; i < 10; i++)
        l.push_back(i);

    for(auto x : l)
        std::cout << x << std::endl;

    return 0;
}
