#include "sort.h"

/**
 * merge_sort - sorts an array of integers in ascending order
 * order using the Merge sort algorithm
 * @array: array to be sorted
 * @size: of array
 */

void merge_sort(int *array, size_t size)
{
	int *ptr;

	if (!array || size < 2)
		return;

	ptr = malloc(size * sizeof(int));
	sort_list(array, 0, size - 1, ptr);
	free(ptr);
}
/**
 * sort_list - divides the list to smaller units
 * @arr: array to be sorted
 * @left: the begining of the sub array
 * @right: end of the sub-array
 * @ptr: pointer to the memory use for mergeing
 */

void sort_list(int *arr, int left, int right, int *ptr)
{
	int mid;

	mid = (left + right) / 2;
	if ((left + right) % 2 == 0)
		mid--;
	if (mid >= left)
	{
		sort_list(arr, left, mid, ptr);
		sort_list(arr, mid + 1, right, ptr);
		merge(arr, left, mid, right, ptr);
	}
}

/**
 * merge - merge two parts of the array;
 * @arr: the arr to be sorted
 * @left: begining of the first array (left-side)
 * @right: end if the second array (right-side)
 * @mid: end of the first array (left-side)
 * @ptr: pointer to the auxiliary array
 */

void merge(int *arr, int left, int mid, int right, int *ptr)
{
	int l, r, nlen;

	l = left, r = mid + 1, nlen = left;

	while (l <= mid && r <= right)
	{
		if (arr[l] <= arr[r])
		{
			ptr[nlen] = arr[l];
			l++;
		}
		else
		{
			ptr[nlen] = arr[r];
			r++;
		}
		nlen++;
	}

	for (; l <= mid; l++, nlen++)
		ptr[nlen] = arr[l];

	for (; r <= right; r++, nlen++)
		ptr[nlen] = arr[r];

	for (nlen = left; nlen <= right; nlen++)
		arr[nlen] = ptr[nlen];

	printf("Merging...\n");
	printf("[left]: ");
	print_array(ptr + left, mid - left + 1);
	printf("[right]: ");
	print_array(ptr + mid + 1, right - mid);
	printf("[Done]: ");
	print_array(ptr + left, right - left + 1);
}
