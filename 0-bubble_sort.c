#include "sort.h"

/**
 * bubble_sort - sort an array of integers in ascending order using the
 * bubble-sort algorithm
 * @array: array of integers
 * @size: number of elements in `array`
 *
 * Return: void.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp, swap = 0;

	if (size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 1; j < size - i; j++)
		{
			if (array[j] < array[j - 1])
			{
				temp = array[j - 1];
				array[j - 1] = array[j];
				array[j] = temp;
				print_array(array, size);
				swap = 1;
			}
		}
		if (swap == 0)
			break;
	}
}
