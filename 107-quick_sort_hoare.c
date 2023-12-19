#include "sort.h"

/**
 * quick_sort_hoare - sorts an array of integers in ascending
 * order using the Quick sort.
 * @array: array to be sorted
 * @size: size of the array
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (array && size > 1)
		q_sort(array, 0, size - 1, size);
}

/**
 * q_sort - a recursive sort
 * @arr: array to be sorted
 * @low: the beginig of the array
 * @high: the end of the array
 * @size: size of the array
 */

void q_sort(int *arr, int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = hoare_partition(arr, low, high, size);
		q_sort(arr, low, pivot_index, size);
		q_sort(arr, pivot_index + 1, high, size);
	}
}

/**
 * hoare_partition - partitions the array
 * @arr: the array to be partition
 * @low: the begining of the array
 * @high: end of list
 * @size: size of the array
 * Return: the current index
 */

int hoare_partition(int *arr, int low, int high, size_t size)
{
	int j, i;
	int temp, pivot = arr[low];

	i = low - 1;
	j = high + 1;

	while (1)
	{

		for (i++; arr[i] < pivot; i++)
			;
		for (j--; arr[j] > pivot; j--)
			;
		if (i >= j)
			return (j);

		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
		print_array(arr, size);
	}
	return (j);
}
