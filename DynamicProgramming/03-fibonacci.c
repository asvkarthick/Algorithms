#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n)
{
    int i, result;
    int *cache;

    if(n < 2)
        return n;

    cache = (int*) malloc((n + 1) * sizeof(int));
    cache[0] = 0;
    cache[1] = 1;

    for(i = 2; i <= n; i++)
        cache[i] = cache[i - 1] + cache[i - 2];

    result = cache[n];
    free(cache);

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
