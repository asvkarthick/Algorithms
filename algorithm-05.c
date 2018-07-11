#include <stdio.h>

/*
    Algorithm: Problem
    Write a program to swap odd and even bits in an integer with as few instructions as possible
    eg., bit 0 and bit 1 are swapped, bit 2 and bit 3 are swapped and so on
*/

unsigned int swap_odd_even(unsigned int n)
{
    return ((n & 0xAAAAAAAA) >> 1) | ((n & 0x55555555) << 1);
}

int main(void)
{
    printf("%x\n", swap_odd_even(0xAAAAAAAA));
    printf("%x\n", swap_odd_even(0x55555555));

    return 0;
}
