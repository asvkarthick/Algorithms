#include <stdio.h>

/* Algorithm:
   You have an integer and you can flip exactly one bit from a 0 to a 1.
   Write code to find the length of the longest sequence of 1s you could create.

   Example:
   Input: 1775 (or: 11011101111)
   Output: 8
*/

int count_max1s(unsigned int n)
{
    unsigned int numberof1smsb[32], numberof1slsb[32];
    int i, count1s;
    int max1s = 0;

    count1s = 0;
    for(i = 0; i < 32; i++)
    {
        if(n & (1 << i))
        {
            count1s++;
        }
        else
        {
            count1s = 0;
        }
        numberof1slsb[i] = count1s;
    }

    count1s = 0;
    for(i = 31; i >= 0; i--)
    {
        if(n & (1 << i))
        {
            count1s++;
        }
        else
        {
            count1s = 0;
        }
        numberof1smsb[i] = count1s;
    }

    for(i = 31; i >= 2; i--)
    {
        if(numberof1smsb[i] != 0 && numberof1smsb[i - 1] == 0 && numberof1slsb[i - 2] != 0)
        {
            int numberof1s = numberof1smsb[i] + 1 + numberof1slsb[i - 2];

            if(numberof1s > max1s)
            {
                max1s = numberof1s;
            }
        }
    }

    return max1s;
}

int main(void)
{
    printf("Max 1s = %d\n", count_max1s(1775));

    return 0;
}
