#include <stdio.h>
#include <stdlib.h>

/*
    Algorithm:

    Write a function to find if the given sum value can be obtained by adding any two numbers in the input array
    Assume that the input array is in sorted order
*/

int hasPairEqualsSum(int *a, int n, int sum)
{
    int i, j, k, s;

    j = 0;
    k = n - 1;

    for(i = 0; i < n - 1; i++)
    {
        s = a[j] + a[k];

        if(s == sum)
            return 1;
        else if(s < sum)
            j++;
        else
            k--;
    }

    return 0;
}

int main(void)
{
    char *result[] = { "NO", "YES" };
    int a1[] = { 1, 2, 3, 4 };
    int a2[] = { 1, 2, 3, 4, 4 };
    int sum = 8;
    int res;

    res = hasPairEqualsSum(a1, sizeof(a1) / sizeof(a1[0]), sum);
    printf("A1 has pair sum %d: %s\n", sum, result[res]);

    res = hasPairEqualsSum(a2, sizeof(a2) / sizeof(a2[0]), sum);
    printf("A2 has pair sum %d: %s\n", sum, result[res]);

    sum = 3;
    res = hasPairEqualsSum(a2, sizeof(a2) / sizeof(a2[0]), sum);
    printf("A2 has pair sum %d: %s\n", sum, result[res]);

    return 0;
}
