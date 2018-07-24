#include <iostream>
#include <vector>

// Simple vector program to push elements and print elements

int main(void)
{
    std::vector<int> v;
    int i;

    for(i = 0; i < 10; i++)
        v.push_back(i);

    std::cout << "Using Range based for loops" << std::endl;
    for(auto x : v)
        std::cout << x << std::endl;

    std::cout << "Using square brackets" << std::endl;
    for(i = 0; i < v.size(); i++)
        std::cout << v[i] << std::endl;

    std::cout << "Using iterators" << std::endl;
    for(auto x = v.begin(); x != v.end(); x++)
        std::cout << *x << std::endl;

    std::cout << "Using const iterators" << std::endl;
    for(auto x = v.cbegin(); x != v.cend(); x++)
        std::cout << *x << std::endl;

    return 0;
}
