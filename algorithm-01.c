/*
There is an array A[N] of N numbers. You have to compose an array Output[N] such that Output[i] will be equal to multiplication 
of all the elements of A[N] except A[i]. For example Output[0] will be multiplication of A[1] to A[N-1] and 
Output[1] will be multiplication of A[0] and from A[2] to A[N-1]. Solve it without division operator and in O(n)
*/

#include <stdio.h>
#include <stdlib.h>

#define N 8

void compute(int *a, int *out, int n)
{
    int *b, *c;
    int i;

    if(n <= 0)
        return;

    b = (int*) malloc(N * sizeof *b);
    if(!b) return;
    c = (int*) malloc(N * sizeof *c);
    if(!c) {
        free(b);
        return;
    }

    b[0] = a[0];
    for(i = 1; i < n; i++)
        b[i] = b[i - 1] * a[i];

    c[n - 1] = a[n - 1];
    for(i = n - 2; i >= 0; i--)
        c[i] = c[i + 1] * a[i];

    for(i = 0; i < N; i++)
        printf("b[%4d] = %8d\n", i, b[i]);
    for(i = 0; i < N; i++)
        printf("c[%4d] = %8d\n", i, c[i]);

    out[0] = c[1];
    out[n - 1] = b[n - 2];
    for(i = 1; i < n - 1; i++)
        out[i] = b[i - 1] * c[i + 1];

    free(b);
    free(c);
}

int main(void)
{
    int a[N];
    int out[N];
    int i;

    // Fill the input array
    for(i = 0; i < N; i++)
        a[i] = i + 1;

    // Print the input array
    for(i = 0; i < N; i++)
        printf("a[%4d] = %8d\n", i, a[i]);

    compute(a, out, N);

    // Print the output array
    for(i = 0; i < N; i++)
        printf("out[%4d] = %8d\n", i, out[i]);

    return 0;
}
