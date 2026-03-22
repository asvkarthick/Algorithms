#include <iostream>
#include <functional>
#include <utility>
#include <map>

int main() {
    std::map<char, std::function<double(double, double)>> m;
    m.insert(std::make_pair('+', [](double a, double b) { return a + b; }));
    m.insert(std::make_pair('-', [](double a, double b) { return a - b; }));
    m.insert(std::make_pair('*', [](double a, double b) { return a * b; }));
    m.insert(std::make_pair('/', [](double a, double b) { return a / b; }));

    std::cout << m['+'](3.0, 2.0) << std::endl;
    std::cout << m['-'](3.0, 2.0) << std::endl;
    std::cout << m['*'](3.0, 2.0) << std::endl;
    std::cout << m['/'](3.0, 2.0) << std::endl;

    return 0;
}
