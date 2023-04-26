#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

void td_mergesort(int *array, int *b, size_t size);
void td_split_merge(int *b, size_t start, size_t end, int *array);
void td_merge(int *array, size_t start, size_t mid, size_t end, int *b);
void copy_array(int *array, size_t start, size_t end, int *b);

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

void td_mergesort(int *array, int *b, size_t size)
{
	copy_array(array, 0, size, b);
	td_split_merge(b, 0, size, array);
}

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

void copy_array(int *array, size_t start, size_t end, int *b)
{
	size_t k;

	for (k = start; k < end; k++)
		b[k] = array[k];
}
