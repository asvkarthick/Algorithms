#include <iostream>

int updateBits(int n, int m, int i, int j)
{
    n = n & ~(((1 << (j - i + 1)) - 1) << i);
    n = n | (m << i);

    return n;
}

int main(void)
{
    int n = 0x400;
    int m = 0x13;

    std::cout << "m = " << std::hex << m << std::endl;
    std::cout << "n = " << std::hex << n << std::endl;
    std::cout << "result = " << std::hex << updateBits(n, m, 2, 6) << std::endl;

    return 0;
}
