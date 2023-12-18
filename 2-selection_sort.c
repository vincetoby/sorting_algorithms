#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending
 * order using the Selection sort algorithm
 * @array: Array to sort
 * @size: Size of array
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	size_t j, i = 0;
	int tmp, fg, min_indx, comp;

	if (array == NULL)
		return;
	while (i < size)
	{
		j = i;
		comp = array[i];
		fg = 0;
		while (j < size)
		{
			if (comp > array[j])
			{
				comp = array[j];
				min_indx = j;
				fg = 1;
			}
			j++;
		}
		if (fg == 1)
		{
			tmp = array[i];
			array[i] = comp;
			array[min_index] = temp;
			print_array(array, size);
		}
		i++;
	}
}
