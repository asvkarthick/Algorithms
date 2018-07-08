#include <stdio.h>
#include <stdlib.h>

void selection(int *a, int n)
{
    int min, i, j, temp;

    for(i = 0; i < n - 1; i++)
    {
        min = i;
        for(j = i + 1; j < n; j++)
        {
            if(a[j] < a[min])
            {
                min = j;
            }
        }

        temp = a[i];
        a[i] = a[min];
        a[min] = temp;        
    }
}

int main(void)
{
    int a[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
    int i;

    printf("Before sorting...\n");
    for(i = 0; i < sizeof(a) / sizeof(a[0]); i++)
        printf("%d ", a[i]);
    printf("\n\n");

    selection(a, sizeof(a) / sizeof(a[0]));

    printf("After sorting...\n");
    for(i = 0; i < sizeof(a) / sizeof(a[0]); i++)
        printf("%d ", a[i]);
    printf("\n\n");

    return 0;
}
