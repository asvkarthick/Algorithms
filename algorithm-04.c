#include <stdio.h>

/*
    Algorithm: Problem
    Write a function to determine the number of bits you would need to flip to convert integer A to integer B

    Input: 29 (11101) , 15 (01111)
    Output: 2
*/

int find_number_of_bits_to_flip(unsigned int a, unsigned int b)
{
    unsigned int c = a ^ b;
    int i, numberof1s = 0;

    // Count the number of 1s
    for(i = 0; i < 32; i++)
    {
        if(c & (1 << i))
        {
            numberof1s++;
        }
    }

    return numberof1s;
}

int main(void)
{
    printf("Number of bits to flip = %d\n", find_number_of_bits_to_flip(29, 15));

    return 0;
}
