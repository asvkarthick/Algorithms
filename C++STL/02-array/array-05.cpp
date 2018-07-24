#include <iostream>
#include <array>

// Simple array program to add and print elements

int main(void)
{
    std::array<int,10> arr;
    int i;

    for(i = 0; i < arr.size(); i++)
        arr[i] = i;

    std::cout << "Print array elements using range based for loop" << std::endl;
    for(auto x : arr)
        std::cout << x << std::endl;

    std::cout << "Print array elements using []" << std::endl;
    for(i = 0; i < arr.size(); i++)
        std::cout << arr[i] << std::endl;

    std::cout << "Print array elements using iterator" << std::endl;
    for(auto x = arr.begin(); x != arr.end(); x++)
        std::cout << *x << std::endl;

    std::cout << "Print array elements using const iterator" << std::endl;
    for(auto x = arr.cbegin(); x != arr.cend(); x++)
        std::cout << *x << std::endl;

    return 0;
}
