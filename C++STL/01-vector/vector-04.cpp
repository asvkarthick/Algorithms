#include <iostream>
#include <vector>

// Simple vector program to push elements and print elements using const iterator

int main(void)
{
    std::vector<int> v;
    int i;

    for(i = 0; i < 10; i++)
        v.push_back(i);

    for(auto x = v.cbegin(); x != v.cend(); x++)
        std::cout << *x << std::endl;

    return 0;
}
