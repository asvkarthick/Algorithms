#include <stdio.h>
#include <stdlib.h>

void swap(int *array, int pos1, int pos2)
{
    int tmp = array[pos1];
    array[pos1] = array[pos2];
    array[pos2] = tmp;
}

int partition(int *array, int left, int right)
{
    int pivot = array[(left + right) / 2];

    while(left <= right)
    {
        while(array[left] < pivot) left++;
        while(array[right] > pivot) right--;
        if(left <= right)
        {
            swap(array, left, right);
            left++;
            right--;
        }
    }
    return left;
}

void quicksort(int *array, int low, int high)
{
    if(low < high)
    {
        int mid = partition(array, low, high);
        quicksort(array, low, mid - 1);
        quicksort(array, mid + 1, high);
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

    quicksort(a, 0, sizeof(a) / sizeof(a[0]) - 1);

    printf("After sorting...\n");
    for(i = 0; i < sizeof(a) / sizeof(a[0]); i++)
        printf("%d ", a[i]);
    printf("\n\n");

    return 0;
}
