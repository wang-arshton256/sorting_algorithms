#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending using quick sort
 * order using the Quick sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (array && size > 1)
		sort(array, 0, size - 1, size);
}

/**
 * sort - a revursive sort
 * @arr: array to be sorted
 * @low: the beginig of the array
 * @high: the end of the array
 * @size: size of the array
 */

void sort(int *arr, int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = partition(arr, low, high, size);
		sort(arr, low, pivot_index - 1, size);
		sort(arr, pivot_index + 1, high, size);
	}
}

/**
 * partition - partitions the array
 * @arr: the array to be partition
 * @low: the begining of the array
 * @high: end of list
 * @size: size of the array
 * Return: the current index
 */

int partition(int *arr, size_t low, size_t high, size_t size)
{
	size_t j, i;
	int temp, pivot = arr[high];

	i = low;

	for (j = low; j < high; j++)
	{
		if (arr[j] < pivot)
		{
			if (arr[i] != arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
				print_array(arr, size);
			}
			i++;
		}
	}
	if (arr[i] != arr[high])
	{
		temp = arr[i];
		arr[i] = arr[high];
		arr[high] = temp;
		print_array(arr, size);
	}

	return (i);
}
