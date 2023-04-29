#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

size_t *knuth_seq(size_t size);

/**
 * shell_sort - Sort an array of integers in ascending order using
 * the insertion sort algorithm.
 * @array: Pointer to the array to be sorted
 * @size: Size of array pointed to by @array
 *
 * Return: void.
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, *gaps;
	int temp, gap_idx, k;

	if (array == NULL || size < 2)
		return;

	gaps = knuth_seq(size);
	if (gaps == NULL)
		return;
/*
*	printf("Knuth sequence: [");
*	for (k = 0; gaps[k]; k++)
*		printf("%lu ", gaps[k]);
*	puts("]");
*/
	for (gap_idx = 0; gaps[gap_idx]; gap_idx++)
	{
		for (i = gaps[gap_idx]; i < size; i++)
		{
			temp = array[i];

			for (j = i; (j >= gaps[gap_idx]) && (array[j - gaps[gap_idx]] > temp); j--)
			{
				array[j] = array[j - gaps[gap_idx]];
			}
			array[j] = temp;
		}
		print_array(array, size);
	}

	free(gaps);
}

/**
 * knuth_seq - generate a knuth sequence
 * @size: upper limit on the largest number in the sequence
 *
 * Return: pointer to the knuth sequence, or NULL (failure).
 */
size_t *knuth_seq(size_t size)
{
	size_t i = 0, j = 1, k = 1, gap = 0, x;
	size_t *gaps, temp;

	while (k < size)
	{
		k = k * 3 + 1;
		i++;
	}

	gaps = malloc((i + 1) * sizeof(size_t));
	if (gaps == NULL)
		return (NULL);

	gaps[0] = 0;
	while (j < i)
	{
		gap = gap * 3 + 1;
		gaps[j] = gap;
		j++;
	}

	for (x = 0; x < (i + 1) / 2; x++)
	{
		temp = gaps[x];
		gaps[x] = gaps[i - x];
		gaps[i - x] = temp;
	}

	return (gaps);
}
