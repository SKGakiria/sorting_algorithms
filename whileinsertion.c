#include <stdio.h>

void for_sort(int *arr, int size)
{
	int i, j, k, temp;

	for (j = 1; j < size; j++)
	{
		for (i = 0; i < j; i++)
		{
			if (arr[j] < arr[i])
			{
				temp = arr[j];
				for (k = j; k > i; k--)
					arr[k] = arr[k - 1];
				arr[i] = temp;
			}
		}
	}
}

void while_sort(int *arr, size_t size)
{
	size_t i, j = 1, k;
	int temp;

	while (j < size)
	{
		i = 0;
		while (i < j)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[j];
				k = j;
				while (k > i)
				{
					arr[k] = arr[k - 1];
					k--;
				}
				arr[i] = temp;
			}
			i++;
		}
		j++;
	}
}

void print(int *arr, int size)
{
	int i;

	printf("[");
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\b]\n");
}

int main(void)
{
	int arr[] = {2, 3, 5, 1, 0};

	printf("Before sort:\n");
	print(arr, 5);
	while_sort(arr, 5);
	printf("After sort:\n");
	print(arr, 5);

	return 0;
}