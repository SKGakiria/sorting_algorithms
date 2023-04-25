#include <stdio.h>
#define MAX 100000

/**
 * sort - implement the insertion sort algorithm
 * @arr: pointer to beginning of integer array
 * @size: size of integer array
 *
 * Return: void.
 */
void sort(int *arr, int size)
{
	int i, j, k, temp;

	for (j = 1; j < size; j++)
		for (i = 0; i < j; i++)
			if (arr[j] < arr[i])
			{
				temp = arr[j];
				for (k = j; k > i; k--)
					arr[k] = arr[k - 1];
				arr[i] = temp;
			}
}

/**
 * print - print an array of integers
 * @arr: pointer to first element in the array
 * @size: size of the array
 *
 * Return: void.
 */
void print(int *arr, int size)
{
	int i;

	printf("[");
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	if (size)
		printf("\b");
	printf("]\n");
}

/**
 * main - entry point
 *
 * Return: 0.
 */
int main(void)
{
	int arr[MAX], i;

	for (i = 0; i < MAX; i++)
		arr[i] = MAX - i;
	printf("Before sort:\n");
	print(arr, 10);
	sort(arr, MAX);
	printf("After sort:\n");
	print(arr, 10);

	return (0);
}
