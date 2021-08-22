/* Count the number of bits set to 1 consecutively with 1 flip
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

#include <iostream>

int countBits(unsigned int num)
{
    int max1Bits = 0;
    int cur1Bits = 0;
    int numPrev0 = 0;
    if (~num == 0) return sizeof(num) * 8;
    while (num) {
        if (num & 1) {
            cur1Bits++;
            numPrev0 = 0;
            if (cur1Bits > max1Bits) max1Bits = cur1Bits;
        } else {
            if (numPrev0) {
                cur1Bits = 0;
            }
            numPrev0++;
        }
        num = num >> 1;
    }
    return max1Bits + 1;
}

void printBits(unsigned int n)
{
    if (n == 0) return;
    int d = n & 1;
    printBits(n >> 1);
    std::cout << d;
}

int main(void)
{
    unsigned int n;
    std::cout << "Enter number : ";
    std::cin >> n;
    printBits(n);
    std::cout << std::endl;
    std::cout << "Max 1 bits = " << countBits(n) << std::endl;
    return 0;
}
