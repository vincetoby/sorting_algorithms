#include "sort.h"

/**
 * quick_sort_quick - calls the split func to get subarrays
 * @array: The array (sub array of last call) to sort
 * @size: Size of array
 * @_array: The whole array to be sorted
 * @_size: The full size of the array being sorted
 **/

void quick_sort_quick(int *array, size_t size, int *_array,
		       size_t _size)
{
	size_t p;

	p = 0;

	if (size > 1)
	{
		p = split(array, size, _array, _size);
		quick_sort_quick(&array[0], p, _array, _size);
		quick_sort_quick(&array[p], size - p, _array, _size);
	}
}

/**
 * split - Finds point to split the array, then swaps larger items
 * to the right and smaller items left
 * @array: Size of array (sub array of last call) being sorted
 * @size: Size of array
 * @_array: The whole array to be sorted
 * @_size: Full size of the original array
 * Return: endin, which is the index where the array
 * should be split into two subarrays
 **/

size_t split(int *array, size_t size, int *_array, size_t _size)
{
	int pi, tmp;
	long begin, endin;

	pi = array[size - 1];
	begin = -1;
	endin = size;


	while (1)
	{
		do {
			begin++;
		} while (array[begin] < pi);
		do {
			endin--;
		} while (array[endin] > pi);

		if (begin >= endin)
		{
			return ((size_t) begin);
		}
		tmp = array[begin];
		array[begin] = array[endin];
		array[endin] = tmp;
		print_array(_array, _size);
	}
	return (endin);
}

/**
 * quick_sort - sorts an array of integers in ascending
 * order using the Quick sort algorithm
 * @array: The array to sort
 * @size: size of array
 */

void quick_sort(int *array, size_t size)
{
	int *_array;
	size_t _size;

	if (array == NULL)
		return;
	_array = &array[0];
	_size = size;
	quick_sort_quick(array, size, _array, _size);
}

