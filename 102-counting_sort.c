#include "sort.h"

/**
 * counting_sort - Sort an array of integers using counting sort
 * @array: An array of integers to be sorted.
 * @size: The size of the array of integer.
 */
void counting_sort(int *array, size_t size)
{
	int *count = NULL, *sorted = NULL;
	unsigned int i, max;

	if (array == NULL || size < 2)
		return;
	max = findMax(array, size);
	count = malloc(sizeof(int) * (max + 1));
	sorted = malloc(sizeof(int) * size);

	if (count == NULL || sorted == NULL)
	{
		free(count);
		free(sorted);
		return;
	}
	for (i = 0; i <= max; i++)
		count[i] = 0;
	for (i = 0; i < size; i++)
		count[array[i]]++;
	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];

	print_array(count, max + 1);

	for (i = 0; i < size; i++)
	{
		sorted[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = sorted[i];

	free(count);
	free(sorted);
}


/**
 * findMax - find the maximum nuber in the array
 * @arr: array to be checked
 * @size: size of the array
 * Return: mwximum value
 */

int findMax(int *arr, size_t size)
{
	int i, max = arr[0];

	for (i = 0; i < (int)size; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return (max);
}
