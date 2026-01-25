#include <iostream>
#include <algorithm>
#include <utility>

int main() {
    int a = 10;
    int b = 20;
    std::cout << "Before std::swap" << std::endl;
    std::cout << "a = " << a << " b = " << b << std::endl;

    std::swap(a, b);
    std::cout << "After std::swap" << std::endl;
    std::cout << "a = " << a << " b = " << b << std::endl;

    return 0;
}
