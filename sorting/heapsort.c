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

void maxHeapify(int *a, int n, int heap_size)
{
    int largest = n;
    int l = left(n);
    int r = right(n);

    if(l < heap_size && a[n] < a[l])
        largest = l;
    if(r < heap_size && a[largest] < a[r])
        largest = r;

    if(largest != n)
    {
        int tmp = a[largest];
        a[largest] = a[n];
        a[n] = tmp;
        maxHeapify(a, largest, heap_size);
    }
}

void heapsort_descending(int *a, int n)
{
    int i;
    int heap_size = n;

    // Build min heap
    for(i = n / 2; i >= 0; i--)
        minHeapify(a, i, n);

    for(i = n - 1; i >= 1; i--)
    {
        int tmp = a[i];
        a[i] = a[0];
        a[0] = tmp;

        --heap_size;
        minHeapify(a, 0, heap_size);
    }
}

void heapsort_ascending(int *a, int n)
{
    int i;
    int heap_size = n;

    // Build max heap
    for(i = n / 2; i >= 0; i--)
        maxHeapify(a, i, n);

    for(i = n - 1; i >= 1; i--)
    {
        int tmp = a[i];
        a[i] = a[0];
        a[0] = tmp;

        --heap_size;
        maxHeapify(a, 0, heap_size);
    }
}

int main(void)
{
    int b[] = { 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
    int i;

    printf("Before sorting...\n");
    for(i = 0; i < sizeof(a) / sizeof(a[0]); i++)
        printf("%d ", a[i]);
    printf("\n\n");

    heapsort_descending(a, sizeof(a) / sizeof(a[0]));

    printf("After sorting...\n");
    for(i = 0; i < sizeof(a) / sizeof(a[0]); i++)
        printf("%d ", a[i]);
    printf("\n\n");

    printf("Before sorting...\n");
    for(i = 0; i < sizeof(b) / sizeof(b[0]); i++)
        printf("%d ", b[i]);
    printf("\n\n");

    heapsort_ascending(b, sizeof(b) / sizeof(b[0]));

    printf("After sorting...\n");
    for(i = 0; i < sizeof(b) / sizeof(b[0]); i++)
        printf("%d ", b[i]);
    printf("\n\n");

    return 0;
}
