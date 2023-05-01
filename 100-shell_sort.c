#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

size_t *knuth_seq(size_t size);

/**
 * shell_sort - Sort an array of integers in ascending order using
 * the insertion sort algorithm.
 *
 * @array: Pointer to the array to be sorted
 * @size: Size of array pointed to by @array
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, gap = 1;
	int temp;

	if (array == NULL || size < 2)
		return;

	while (gap < size / 3)
		gap = gap * 3 + 1;
	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];

			j = i;
			while ((j >= gap) && (array[j - gap] > temp))
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = temp;
		}
		print_array(array, size);
	}
}
