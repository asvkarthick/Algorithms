#include <stdio.h>
#include <stdlib.h>

void merge(int *output, int *input1, int n1, int *input2, int n2)
{
    int i = 0, j = 0, k = 0;

    while(i < n1 && j < n2)
    {
        if(input1[i] <= input2[j])
        {
            output[k++] = input1[i++];
        }
        else
        {
            output[k++] = input2[j++];
        }
    }
    while(i < n1)
    {
        output[k++] = input1[i++];
    }
    while(j < n2)
    {
        output[k++] = input2[j++];
    }
}

void mergesort(int *array, int n)
{
    int *left;
    int *right;
    int i, n1, n2;

    if(n <= 1)
        return;

    n1 = n / 2;
    n2 = n - n1;

    left = (int*) malloc(n1 * sizeof(int));
    right = (int*) malloc(n2 * sizeof(int));

    for(i = 0; i < n1; i++)
        left[i] = array[i];

    for(i = 0; i < n2; i++)
        right[i] = array[n1 + i];

    mergesort(left, n1);
    mergesort(right, n2);
    merge(array, left, n1, right, n2);
}

int main(void)
{
    int a[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
    int i;

    printf("Before sorting...\n");
    for(i = 0; i < sizeof(a) / sizeof(a[0]); i++)
        printf("%d ", a[i]);
    printf("\n\n");

    mergesort(a, sizeof(a) / sizeof(a[0]));

    printf("After sorting...\n");
    for(i = 0; i < sizeof(a) / sizeof(a[0]); i++)
        printf("%d ", a[i]);
    printf("\n\n");

    return 0;
}
