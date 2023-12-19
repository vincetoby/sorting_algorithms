#include "sort.h"

/**
 * swapper - swaps two values
 * @one: Fisrt value
 * @two: Second value
 * Return: void
 */

void swapper(int *one, int *two)
{
	int tmp;

	tmp = *two;
	*two = *one;
	*one = tmp;
}

/**
 * gap_sorter - sort array with gaps
 * @array: array to sort
 * @size: size of array
 * @gap: size of gap
 * Return: void
 */

void gap_sorter(int *array, size_t size, unsigned int gap)
{
	size_t j, k;

	for (j = gap; j < size; j++)
	{
		k = j;
		while (k >= gap && array[k] < array[k - gap])
		{
			swapper(array + k, array + k - gap);
			k -= gap;
		}
	}
}

/**
 * shell_sort - sorts an array of integers in ascending
 * order using the Shell sort algorithm
 * @array: array to be sorted
 * @size: size of array
 * Return: void
 */

void shell_sort(int *array, size_t size)
{
	unsigned int gap = 1;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap >= 1)
	{
		gap_sorter(array, size, gap);
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
