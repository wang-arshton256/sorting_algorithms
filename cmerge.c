#include <stdlib.h>

/**
 * merge_sort - sorts an array of integers in ascending
 * order using the Merge sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void sort_list(int *arr, size_t left, size_t right, int *ptr);
void merge(int *arr, size_t left, size_t mid, size_t right, int *ptr);

void merge_sort(int *array, size_t size)
{
	size_t i;
	int *ptr = malloc(size * sizeof(int));
	if (!ptr)
		return;

	sort_list(array, 0, size - 1, ptr);

	for (i = 0; i < size; i++)
		array[i] = ptr[i];

	free(ptr);
}

void merge(int *arr, size_t left, size_t mid, size_t right, int *ptr)
{
	size_t i = left, j = mid + 1, k = left;

	while (i <= mid && j <= right)
	{
		if (arr[i] <= arr[j])
		{
			ptr[k] = arr[i];
			i++;
		}
		else
		{
			ptr[k] = arr[j];
			j++;
		}
		k++;
	}

	while (i <= mid)
	{
		ptr[k] = arr[i];
		i++;
		k++;
	}

	while (j <= right)
	{
		ptr[k] = arr[j];
		j++;
		k++;
	}

	for (k = left; k <= right; k++)
		arr[k] = ptr[k];
}

void sort_list(int *arr, size_t left, size_t right, int *ptr)
{
	if (left < right)
	{
		size_t mid = left + (right - left) / 2;
		sort_list(arr, left, mid, ptr);
		sort_list(arr, mid + 1, right, ptr);
		merge(arr, left, mid, right, ptr);
	}
}
