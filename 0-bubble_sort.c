#include "sort.h"

/**
 * bubble_sort - sorts an array of numbers
 * integers in ascending order using the Bubble sort algorithm
 * @array: The array to be sorted
 * @size: size of the array
 * Return: no return
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, flag;

	if (!array || size <= 0)
		return;

	while (1)
	{
		flag = 0;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap(array, i);
				print_array(array, size);
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}

}

/**
 * swap - swaps element in array
 * @idx: index to be swap
 * @array: array to swap
 * Return: no return
 */

void swap(int *array, int idx)
{
	int n;

	n = array[idx];
	array[idx] = array[idx + 1];
	array[idx + 1] = n;
}
