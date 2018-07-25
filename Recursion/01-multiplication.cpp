#include <iostream>

int multiply(int x, int n)
{
    if(n <= 0)
        return 0;
    else if(n == 1)
        return x;
    return x + multiply(x, n - 1);
}

int main(void)
{
    std::cout << multiply(6, 3) << std::endl;
    std::cout << multiply(5, 5) << std::endl;

    return 0;
}
