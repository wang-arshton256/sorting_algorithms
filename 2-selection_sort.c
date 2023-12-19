#include "sort.h"

/**
 * selection_sort - sorts an array of integers
 * in ascending order using the Selection sort algorithm
 * @array: The array to be sorted
 * @size: the size of the array
 * Return: no return
 */

void selection_sort(int *array, size_t size)
{
	size_t i, min, j;
	int temp, issorted;

	if (!array || size <= 1)
		return;

	for (i = 0; i < size; i++)
	{
		min = i;
		issorted = 0;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
				issorted = 1;
			}
		}
		temp = array[i];
		array[i] = array[min];
		array[min] = temp;
		if (issorted)
			print_array(array, size);

	}
}

/**
 * swap_selection - swaps items in selection sort
 * @arr: array to be swaped
 * @min: first index
 * @i: second index
 */

void swap_selection(int *arr, size_t min, size_t i)
{
	int n;

	n = arr[i];
	arr[i] = arr[min];
	arr[min] = n;
}
