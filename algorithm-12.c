#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *add1(int *input, int n, int *out_n)
{
    int *result;
    int i;
    int sum, carry = 1;

    result = (int*) malloc(n * sizeof(int));

    for(i = n - 1; i >= 0; i--)
    {
        sum = input[i] + carry;
        if(sum == 10)
            carry = 1;
        else
            carry = 0;
        result[i] = sum % 10;
    }
    *out_n = n;

    if(carry == 1)
    {
        free(result);
        result = (int*) malloc((n + 1) * sizeof(int));
        memset(result, 0, (n + 1) * sizeof(int));
        result[0] = 1;
        *out_n = n + 1;
    }

    return result;
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
    int input1[] = { 1, 2, 3 };
    int input2[] = { 1, 2, 9 };
    int input3[] = { 9, 9, 9 };
    int n, out_n;
    int *result;

    n = sizeof(input1) / sizeof(input1[0]);
    print("Input1", input1, n);
    result = add1(input1, n, &out_n);
    print("Added 1", result, out_n);
    free(result);

    n = sizeof(input2) / sizeof(input2[0]);
    print("Input2", input2, n);
    result = add1(input2, n, &out_n);
    print("Added 1", result, out_n);
    free(result);

    n = sizeof(input3) / sizeof(input3[0]);
    print("Input1", input3, n);
    result = add1(input3, n, &out_n);
    print("Added 1", result, out_n);
    free(result);

    return 0;
}
