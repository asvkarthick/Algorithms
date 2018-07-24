#include <iostream>
#include <array>

// Simple array program to add and print elements using iterators

int main(void)
{
    std::array<int,10> arr;
    int i;

    for(i = 0; i < arr.size(); i++)
        arr[i] = i;

    for(auto x = arr.begin(); x != arr.end(); x++)
        std::cout << *x << std::endl;

    return 0;
}
