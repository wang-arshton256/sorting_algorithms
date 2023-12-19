#include "sort.h"

/**
 * radix_sort - aunction that sorts an array of integers
 * in ascending order using the Radix sort
 * @array: array to be sorted
 * @size: size of the array
 */

void radix_sort(int *array, size_t size)
{
	int max, exp;
	int *output;

	if (!array || size < 2)
		return;

	output = malloc(size * sizeof(int));
	max = findMax(array, size);

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		countingSort(array, size, exp, output);
		print_array(array, size);
	}
	free(output);
}


/**
 * countingSort - counting sort
 * @arr: the array to be sorted
 * @size: size of the array
 * @exp: the current base
 * @output: auxiliary array for sorting
 */

void countingSort(int *arr, size_t size, int exp, int *output)
{
	int i;
	int count[10] = {0};

	for (i = 0; i < (int)size; i++)
		count[(arr[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i >= 0; i--)
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}
	for (i = 0; i < (int)size; i++)
		arr[i] = output[i];


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
