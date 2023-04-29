#include "sort.h"

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void mx_heapify(int *array, size_t size, size_t i)
{
	size_t largest = i;
	size_t l = 2 * i;
	size_t r = (2 * i) + 1;

	while(l <= size && array[l] > array[largest])
	{
		largest = l;
	}
	while(r <= size && array[r] > array[largest])
	{
		largest = r;
	}
	if(largest != i)
	{
		swap(&array[largest], &array[i]);
		print_array(array, size);
		mx_heapify(array, size, largest);
	}
}

void heap_sort(int *array, size_t size)
{
	size_t i;
	for(i = size / 2; i >= 1; i--)
	{
		mx_heapify(array, size, i);
	}
	for(i = size; i >= 1; i--)
	{
		swap(&array[1], &array[i]);
		print_array(array, size);
		mx_heapify(array, size, 1);
	}
}
