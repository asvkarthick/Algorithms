#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v1(5, 10);
    std::cout << "Print v1 before std::move" << std::endl;
    for (int i = 0; i < v1.size(); i++) {
        std::cout << "v1[" << i << "] = " << v1[i] << std::endl;
    }
    std::vector<int> v2;
    v2 = std::move(v1);

    std::cout << "Print v1 after std::move" << std::endl;
    for (int i = 0; i < v1.size(); i++) {
        std::cout << "v1[" << i << "] = " << v1[i] << std::endl;
    }
    std::cout << "Print v2 after std::move" << std::endl;
    for (int i = 0; i < v2.size(); i++) {
        std::cout << "v2[" << i << "] = " << v2[i] << std::endl;
    }
    std::cout << "v1.size() = " << v1.size() << std::endl;
    std::cout << "v2.size() = " << v2.size() << std::endl;

    return 0;
}
