#include "sort.h"

/**
 * swap - swap two integers
 * @a: pointer to integer
 * @b: pointer to integer
 *
 * Return: void.
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * mx_heapify - build a max-heap from an array
 * @array: pointer to an array of integers
 * @size: length of buffer pointed to by @array
 * @i: initial value with which to set the largest index
 *
 * Return: void.
 */
void mx_heapify(int *array, size_t size, size_t i)
{
	size_t largest = i;
	size_t l = 2 * i + 1;
	size_t r = (2 * i) + 2;

	if (l < size && array[l] > array[largest])
	{
		largest = l;
	}

	if (r < size && array[r] > array[largest])
	{
		largest = r;
	}

	if (largest != i)
	{
		swap(&(array[largest]), &(array[i]));
		print_array(array, size);
		mx_heapify(array, size, largest);
	}
}

/**
 * heap_sort - sort an array of integers in ascending order using
 * the heap sort algorithm
 * @array: pointer to array of integers
 * @size: size of array
 *
 * Return: void.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	for (i = size / 2 - 1; i >= 0; i--)
	{
		mx_heapify(array, size, i);
	}

	for (i = size - 1; i >= 0; i--)
	{
		swap(&array[0], &(array[i]));
		print_array(array, size);
		mx_heapify(array, i, 0);
	}
}
