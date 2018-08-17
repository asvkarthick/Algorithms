#include <stdio.h>
#include <stdlib.h>

int parent(int n)
{
    return n >> 1;
}

int left(int n)
{
    return (2 * (n + 1)) - 1;
}

int right(int n)
{
    return 2 * (n + 1);
}

void minHeapify(int *a, int n, int heap_size)
{
    int smallest = n;
    int l = left(n);
    int r = right(n);

    if(l < heap_size && a[n] > a[l])
        smallest = l;
    if(r < heap_size && a[smallest] > a[r])
        smallest = r;

    if(smallest != n)
    {
        int tmp = a[smallest];
        a[smallest] = a[n];
        a[n] = tmp;
        minHeapify(a, smallest, heap_size);
    }
}

void heapsort(int *a, int n)
{
    int i;
    int heap_size = n;

    // Build min heap
    for(i = n / 2; i >= 0; i--)
    {
        printf("a[%d] = %d\n", i, a[i]);
        minHeapify(a, i, n);
        printf("a[%d] = %d\n", i, a[i]);
    }

    for(i = n - 1; i >= 1; i--)
    {
        int tmp = a[i];
        a[i] = a[0];
        a[0] = tmp;

        --heap_size;
        minHeapify(a, 0, heap_size);
    }
}

int main(void)
{
    // int a[] = { 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
    int i;

    printf("Before sorting...\n");
    for(i = 0; i < sizeof(a) / sizeof(a[0]); i++)
        printf("%d ", a[i]);
    printf("\n\n");

    heapsort(a, sizeof(a) / sizeof(a[0]));

    printf("After sorting...\n");
    for(i = 0; i < sizeof(a) / sizeof(a[0]); i++)
        printf("%d ", a[i]);
    printf("\n\n");

    return 0;
}
