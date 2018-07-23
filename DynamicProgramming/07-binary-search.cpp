#include <iostream>

int binary_search(int *array, int low, int high, int value)
{
    int mid;

    if(low > high)
        return -1;

    mid = (low + high) / 2;
    // std::cout << "low : " << low << " mid : " << mid << " high : " << high << std::endl;

    if(array[mid] == value)
        return mid;
    else if(array[mid] < value)
        return binary_search(array, mid + 1, high, value);
    else
        return binary_search(array, low, mid - 1, value);
}

int main(void)
{
    int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int n;

    n = sizeof(array) / sizeof(array[0]) - 1;

    std::cout << "1 is at position " << binary_search(array, 0, n, 1) << std::endl;
    std::cout << "2 is at position " << binary_search(array, 0, n, 2) << std::endl;
    std::cout << "3 is at position " << binary_search(array, 0, n, 3) << std::endl;
    std::cout << "4 is at position " << binary_search(array, 0, n, 4) << std::endl;
    std::cout << "5 is at position " << binary_search(array, 0, n, 5) << std::endl;
    std::cout << "6 is at position " << binary_search(array, 0, n, 6) << std::endl;
    std::cout << "7 is at position " << binary_search(array, 0, n, 7) << std::endl;
    std::cout << "8 is at position " << binary_search(array, 0, n, 8) << std::endl;
    std::cout << "9 is at position " << binary_search(array, 0, n, 9) << std::endl;
    std::cout << "10 is at position " << binary_search(array, 0, n, 10) << std::endl;

    return 0;
}
