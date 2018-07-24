#include <stdio.h>

#define N 4

void transpose(int *a, int n)
{
    int i, j;

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < i; j++)
        {
            int t = a[i * n + j];
            a[i * n + j] = a[j * n + i];
            a[j * n + i] = t;
        }
    }
}

int main(void)
{
    int i, j;
    int a[N * N] = {  1,  2,  3,  4,
                      5,  6,  7,  8,
                      9, 10, 11, 12,
                     13, 14, 15, 16
                   };

    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            printf("%2d ", a[i * N + j]);
        }
        printf("\n");
    }

    printf("\n");
    transpose(a, N);
    printf("\n");

    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            printf("%2d ", a[i * N + j]);
        }
        printf("\n");
    }

    return 0;
}
