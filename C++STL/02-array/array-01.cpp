#include <iostream>
#include <array>

int main(void)
{
    std::array<int,10> arr;
    int i;

    for(i = 0; i < arr.size(); i++)
        arr[i] = i;

    for(auto x : arr)
        std::cout << x << std::endl;

    return 0;
}
