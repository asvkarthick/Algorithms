#include <iostream>
#include <vector>

// Simple vector program to push elements and print elements using iterator

int main(void)
{
    std::vector<int> v;
    int i;

    for(i = 0; i < 10; i++)
        v.push_back(i);

    for(auto x = v.begin(); x != v.end(); x++)
        std::cout << *x << std::endl;

    return 0;
}
