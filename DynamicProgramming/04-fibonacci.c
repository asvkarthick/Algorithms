#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n)
{
    int i, result, n0 = 0, n1 = 1;

    if(n < 2)
        return n;

    for(i = 2; i <= n; i++)
    {
        result = n0 + n1;
        n0 = n1;
        n1 = result;
    }

    return result;
}

int main(void)
{
    int n;

    printf("Enter n: ");
    scanf("%d", &n);
    printf("Fibonacci of %d = %d\n", n, fibonacci(n));

    return 0;
}
