#include "sort.h"
#include <stdlib.h>

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
	size_t i, j, gap_idx, *gaps;
	int temp;

	if (array == NULL || size < 2)
		return;

	gaps = knuth_seq(size);
	if (gaps == NULL)
		exit(EXIT_FAILURE);

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
	size_t h = 0, i = 0, j = 0, *seq = NULL;

	while (1)
	{
		if ((h * 3 + 1) > (size / 3))
			break;
		h = h * 3 + 1;
		i++;
	}

	seq = calloc(i + 1, sizeof(size_t));
	if (seq == NULL)
		return (NULL);

	while (1)
	{
		seq[j] = h;
		h = (h - 1) / 3;
		i--;
		j++;

		if (i == 0)
			break;
	}

	return (seq);
}
