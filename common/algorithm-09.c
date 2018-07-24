#include <stdio.h>
#include <stdlib.h>

/*
    Algorithm:

    Given two sorted input arrays A[] and B[] with n1 and n2 elements respectively
    Construct an output array C[] with both the elements of A and B in sorted order
*/

void merge(int *A, int n1, int *B, int n2, int *C)
{
    // Here the assumption is array C will have space to store n1 + n2 elements
    int i, j, k;

    i = 0;
    j = 0;

    for(k = 0; k < n1 + n2; k++)
    {
        if(i >= n1)
        {
            C[k] = B[j++];
        }
        else if(j >= n2)
        {
            C[k] = A[i++];
        }
        else if(A[i] <= B[j])
        {
            C[k] = A[i++];
        }
        else
        {
            C[k] = B[j++];
        }
    }
}

void print(char *s, int *a, int n)
{
    int i;

    printf("%s\n", s);
    for(i = 0; i < n; i++)
        printf("%3d ", a[i]);
    printf("\n");
}

int main(void)
{
    int A1[] = { 1, 2, 3, 4, 5 };
    int B1[] = { 1, 2, 3, 4, 5 };
    int A2[] = { 1, 2, 3, 4, 5, 6 };
    int B2[] = { 7, 8, 9, 10 };
    int A3[] = { 1, 3, 5, 7, 9 };
    int B3[] = { 2, 4, 6, 8, 10 };
    int A4[] = { 1, 2, 3, 10, 11 };
    int B4[] = { 0, 5, 6, 7, 8, 9 };
    int n1, n2;
    int *C;

    n1 = sizeof(A1) / sizeof(A1[0]);
    n2 = sizeof(B1) / sizeof(B1[0]);
    C = (int*) malloc(sizeof(int) * (n1 + n2));
    print("Array A1", A1, n1);
    print("Array B1", B1, n2);
    merge(A1, n1, B1, n2, C);
    print("Array C", C, n1 + n2);
    free(C);

    n1 = sizeof(A2) / sizeof(A2[0]);
    n2 = sizeof(B2) / sizeof(B2[0]);
    C = (int*) malloc(sizeof(int) * (n1 + n2));
    print("Array A2", A2, n1);
    print("Array B2", B2, n2);
    merge(A2, n1, B2, n2, C);
    print("Array C", C, n1 + n2);
    free(C);

    n1 = sizeof(A3) / sizeof(A3[0]);
    n2 = sizeof(B3) / sizeof(B3[0]);
    C = (int*) malloc(sizeof(int) * (n1 + n2));
    print("Array A3", A3, n1);
    print("Array B3", B3, n2);
    merge(A3, n1, B3, n2, C);
    print("Array C", C, n1 + n2);
    free(C);

    n1 = sizeof(A4) / sizeof(A4[0]);
    n2 = sizeof(B4) / sizeof(B4[0]);
    C = (int*) malloc(sizeof(int) * (n1 + n2));
    print("Array A4", A4, n1);
    print("Array B4", B4, n2);
    merge(A4, n1, B4, n2, C);
    print("Array C", C, n1 + n2);
    free(C);

    return 0;
}
