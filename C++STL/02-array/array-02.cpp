#include <iostream>
#include <array>

// Simple array program to add and print elements using []

int main(void)
{
    std::array<int,10> arr;
    int i;

    for(i = 0; i < arr.size(); i++)
        arr[i] = i;

    for(i = 0; i < arr.size(); i++)
        std::cout << arr[i] << std::endl;

    return 0;
}
