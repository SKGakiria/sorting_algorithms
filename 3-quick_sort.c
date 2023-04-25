#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * quick_sort - function that sorts an array of integers in ascending order
 * @array: array of integers
 * @size: number of elements in `array`
 *
 * Return: void
 */

#include <stdio.h>

void quick_sort(int *array, size_t size);
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int l, int r)
{
    int pivot = arr[r];
    int i = l;
    for (int j = l; j < r; ++j) {
        if (arr[j] < pivot) {
            swap(&arr[i], &arr[j]);
            ++i;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
}

void quicksort_recursive(int *arr, int l, int r)
{
    if (l >= r)
        return;

    int i = partition(arr, l, r);
    for(int i = l; i <= r; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
    quicksort_recursive(arr, l, i - 1);
    quicksort_recursive(arr, i + 1, r);
}

void quick_sort(int *array, size_t size)
{
    quick_sort_recursive(array, 0, size - 1);
}

int main()
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t size = sizeof(array) / sizeof(array[0]);
    quick_sort(array, size);
    printf("Sorted array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}
