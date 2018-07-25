#include <iostream>

int factorial(int n)
{
    if(n == 0)
        return 1;

    return n * factorial(n - 1);
}

int main(void)
{
    int n;

    std::cout << "Enter n : ";
    std::cin >> n;
    std::cout << "Factorial of " << n << " is " << factorial(n) << std::endl;

    return 0;
}
