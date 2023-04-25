#include "sort.h"

void swap(int *a, int *b);
int partition(int *arr, int l, int r, size_t size);
void quicksort_recursive(int *arr, int l, int r, size_t size);

/**
 * quick_sort - function that sorts an array of integers in ascending order
 * @array: array of integers
 * @size: number of elements in `array`
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort_recursive(array, 0, size - 1, size);
}

/**
 * swap - swap integers
 * @a: integer pointer
 * @b: integer pointer
 *
 * Return: void
 */
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
 * partition - partition an array of integers
 * @arr: integer array segment
 * @l: start of segment
 * @r: end of segment
 * @size: size of array
 *
 * Return: partition index
 */
int partition(int *arr, int l, int r, size_t size)
{
	int pivot = arr[r];
	int i = l, j;

	for (j = l; j < r; ++j)
	{
		if (arr[j] < pivot)
		{
			if (i != j)
			{
				swap(&arr[i], &arr[j]);
				print_array(arr, size);
			}
			++i;
		}
	}
	if (i != j)
	{
		swap(&arr[i], &arr[r]);
		print_array(arr, size);
	}
	return (i);
}

/**
 * quicksort_recursive - implement quicksort algorithm
 * @arr: integer array segment
 * @l: start of segment
 * @r: end of segment
 * @size: size of array
 *
 * Return: void
 */
void quicksort_recursive(int *arr, int l, int r, size_t size)
{
	int i;

	if (l >= r)
		return;

	i = partition(arr, l, r, size);
	quicksort_recursive(arr, l, i - 1, size);
	quicksort_recursive(arr, i + 1, r, size);
}
