#include <iostream>
#include <utility>
#include <algorithm>
#include <functional>

double divide(double a, double b) {
    return a / b;
}

int main() {
    std::function<double(double, double)> div = std::bind(divide, std::placeholders::_1, std::placeholders::_2);
    std::cout << "div(5.0, 2.0) = " << div(5.0, 2.0) << std::endl;

    return 0;
}
