#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

void td_mergesort(int *array, int *b, size_t size);
void td_split_merge(int *b, size_t start, size_t end, int *array);
void td_merge(int *array, size_t start, size_t mid, size_t end, int *b);
void copy_array(int *array, size_t start, size_t end, int *b);

/**
* merge_sort - sorts an array of integers in ascending order
* @array: array to be sorted
* @size: size of array
*
* Return: void
*/
void merge_sort(int *array, size_t size)
{
	int *b;

	if (size < 2)
		return;

	b = malloc(size * sizeof(int));
	if (b == NULL)
		return;

	td_mergesort(array, b, size);
	free(b);
}

/**
* td_mergesort - merge sorting two arrays
* @array: array to be sorted
* @b: pointer to buffer to hold a copy of @array
* @size: size of array
*
* Return: void
*/
void td_mergesort(int *array, int *b, size_t size)
{
	copy_array(array, 0, size, b);
	td_split_merge(b, 0, size, array);
}

/**
* td_split_merge - recursively splits an unsorted array
* @b: pointer to a buffer with a copy of array
* @start: start point of array
* @end: size of array
* @array: pointer to aaray
*
* Return: void
*/
void td_split_merge(int *b, size_t start, size_t end, int *array)
{
	size_t mid;

	if (end - start <= 1)
		return;

	mid = (start + end) / 2;

	td_split_merge(array, start, mid, b);
	td_split_merge(array, mid, end, b);
	td_merge(b, start, mid, end, array);
}

/**
* td_merge - merges two arrays
* @array: pointer to array
* @start: start of left side of array
* @mid: start of right side of array
* @end: size of array
* @b: pointer to buffer into which merging is done
*
* Return: void
*/
void td_merge(int *array, size_t start, size_t mid, size_t end, int *b)
{
	size_t i = start, j = mid, k;

	printf("Merging...\n");
	printf("left]: ");
	print_array(array + start, mid - start);
	printf("[right]: ");
	print_array(array + mid, end - mid);

	for (k = start; k < end; k++)
	{
		if (i < mid && (j >= end || array[i] <= array[j]))
		{
			b[k] = array[i];
			i++;
		}
		else
		{
			b[k] = array[j];
			j++;
		}
	}
	printf("[Done]: ");
	print_array(b + start, end - start);
}

/**
* copy_array - copy from array into b
* @array: pointer to array
* @start: start of array
* @end: size of array
* @b: buffer to hold a copy of array
*
* Return: void
*/
void copy_array(int *array, size_t start, size_t end, int *b)
{
	size_t k;

	for (k = start; k < end; k++)
		b[k] = array[k];
}
