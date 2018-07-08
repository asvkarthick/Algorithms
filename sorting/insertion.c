#include <stdio.h>
#include <stdlib.h>

void insertion(int *a, int n)
{
    int i, elem, j;

    for(i = 1; i < n; i++)
    {
        elem = a[i];
        for(j = i - 1; j >= 0; j--)
        {
            if(a[j] > elem)
                a[j + 1] = a[j];
            else
                break;
        }
        a[j + 1] = elem;
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

    insertion(a, sizeof(a) / sizeof(a[0]));

    printf("After sorting...\n");
    for(i = 0; i < sizeof(a) / sizeof(a[0]); i++)
        printf("%d ", a[i]);
    printf("\n\n");

    return 0;
}
