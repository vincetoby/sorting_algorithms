#include "sort.h"

/**
 * max_of - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of array.
 * Return: The maximum int in the array.
 */

int max_of(int *array, int size)
{
	int maxi, i;

	for (maxi = array[0], i = 1; i < size; i++)
	{
		if (array[i] > maxi)
			maxi = array[i];
	}
	return (maxi);
}

/**
 * counting_sort - Sort an array of integers in ascending order
 * using the counting sort algorithm
 * @array: An array of integers.
 * @size: The size of array.
 * Return: void
 */

void counting_sort(int *array, size_t size)
{
	int *counter, *sd, maxi, i;

	if (array == NULL || size < 2)
		return;

	sd = malloc(sizeof(int) * size);
	if (sd == NULL)
		return;
	maxi = max_of(array, size);
	counter = malloc(sizeof(int) * (maxi + 1));
	if (counter == NULL)
	{
		free(sd);
		return;
	}

	for (i = 0; i < (maxi + 1); i++)
		counter[i] = 0;
	for (i = 0; i < (int)size; i++)
		counter[array[i]] += 1;
	for (i = 0; i < (maxi + 1); i++)
		counter[i] += counter[i - 1];
	print_array(counter, maxi + 1);

	for (i = 0; i < (int)size; i++)
	{
		sd[count[array[i]] - 1] = array[i];
		counter[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sd[i];

	free(sd);
	free(counter);
}
