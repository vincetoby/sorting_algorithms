#include "sort.h"

/**
 * bubble_sort - Sorts by swapping largest items to the end of array 
 * @array: Array to sort
 * @size: Size of array
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	size_t indx;
	int fg;
	size_t tmp;
	size_t tmpsize;

	if (array == NULL)
		return;
	tmpsize = size;
	fg = 1;
	while (fg)
	{
		fg = 0;
		indx = 0;
		while (indx < tmpsize - 1)
		{
			if (array[indx] > array[indx + 1])
			{
				/*Swap elements if they are in the wrong order*/
				tmp = array[indx + 1];
				array[indx + 1] = array[indx];
				array[j] = tmp;

				/*Print the array after each swap (for visualization)*/
				print_array(array, size);
				fg = 1; /*Set the flag to indicate a swap occurred*/
			}
			indx++;
		}
		tmpsize = indx;
	}
}
