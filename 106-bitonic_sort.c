#include "sort.h"

/**
 * bitonic_sort - sorts an array of integers in ascending
 * order using the Bitonic sort.
 * @array: array to be sorted.
 * @size: size of array
 */

void bitonic_sort(int *array, size_t size)
{
	int asc = 1;

	if (size < 2 || !array)
		return;

	bitonic_sequence(array, 0, size, asc, size);
}

/**
 * bitonic_sequence - creates a bit9nic sequence
 * @arr: array to be sorted
 * @start: beginn8g of section
 * @no_elem: number of items in the array
 * @order: 1 = acsending 0 = desending
 * @size: size of the array
 */

void bitonic_sequence(int *arr, int start, int no_elem, int order, int size)
{
	int mid;
	int asc = 1, des = 0;

	if (no_elem > 1)
	{
		if (order)
		{
			printf("Merging [%i/%i] (UP):\n", no_elem, size);
			print_array(&arr[start], no_elem);
		}
		else
		{
			printf("Merging [%i/%i] (DOWN):\n", no_elem, size);
			print_array(&arr[start], no_elem);
		}
		mid = no_elem / 2;
		bitonic_sequence(arr, start, mid, asc, size);
		bitonic_sequence(arr, start + mid, mid, des, size);
		bitonic_merge(arr, start, no_elem, order);
		if (!order)
		{
			printf("Result [%i/%i] (DOWN):\n", no_elem, size);
			print_array(&arr[start], no_elem);
		}
		if (order)
		{
			printf("Result [%i/%i] (UP):\n", no_elem, size);
			print_array(&arr[start], no_elem);
		}
	}
}

/**
 * bitonic_merge - merge two bitonic array
 * @arr: array
 * @start: first item in the array
 * @no_elem: number of elements in the array
 * @order: 1 = ascending 0 = desending
 */

void bitonic_merge(int *arr, int start, int no_elem, int order)
{
	int mid, i;

	if (no_elem > 1)
	{
		mid = no_elem / 2;

		for (i = start; i < start + mid; i++)
			bitonic_swap(arr, i, i + mid, order);
		bitonic_merge(arr, start, mid, order);
		bitonic_merge(arr, start + mid, mid, order);
	}
}

/**
 * bitonic_swap - swaps elements
 * @arr: array
 * @i: index of first item
 * @j: index of second item
 * @order: swaping order
 */

void bitonic_swap(int *arr, int i, int j, int order)
{
	int temp;

	if (order == (arr[i] > arr[j]))
	{
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
}
