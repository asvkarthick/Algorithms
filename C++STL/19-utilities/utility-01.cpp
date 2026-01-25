#include <iostream>
#include <algorithm>

int main() {
    std::cout << "std::min(100, 200) = " << std::min(100, 200) << std::endl;
    std::cout << "std::min({1, 2, 3, -2, -1}) = " << std::min({1, 2, 3, -2, -1}) << std::endl;
    std::cout << "std::min({1, 2, 3, -2, -1}, [](int a, int b) { return std::abs(a) < std::abs(b);}) = " <<
	    std::min({1, 2, 3, -2, -1}, [](int a, int b) { return std::abs(a) < std::abs(b); }) << std::endl;

    auto p1 = std::minmax(200, 100);
    std::cout << "std::minmax(200, 100) = " << p1.first << ", " << p1.second << std::endl;
    auto p2 = std::minmax({1, 2, 3, -2, -1});
    std::cout << "std::minmax({1, 2, 3, -2, -1}) = " << p2.first << ", " << p2.second << std::endl;
    auto p3 = std::minmax({1, 2, 3, -2, -1}, [](int a, int b) { return std::abs(a) < std::abs(b); });
    std::cout << p3.first << ", " << p3.second << std::endl;

    return 0;
}
