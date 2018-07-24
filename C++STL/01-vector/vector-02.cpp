#include <iostream>
#include <vector>

// Simple vector program to push elements and print elements using []

int main(void)
{
    std::vector<int> v;
    int i;

    for(i = 0; i < 10; i++)
        v.push_back(i);

    for(i = 0; i < 10; i++)
        std::cout << v[i] << std::endl;

    return 0;
}
