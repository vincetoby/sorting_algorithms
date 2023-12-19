#include "sort.h"

void submerge(int *arr, int *buffer, size_t fwd, size_t mid,
		size_t bwd);
void recursive_merge_sort(int *arr, int *buffer, size_t fwd, size_t bwd);
void merge_sort(int *array, size_t size);

/**
 * submerge - Sort a subarray of integers.
 * @arr: subarray to sort.
 * @buffer: buffer for storing the sorted subarray.
 * @fwd: The first index of the array.
 * @mid: The middle index of the array.
 * @bwd: The last index of the array.
 */

void submerge(int *arr, int *buffer, size_t fwd, size_t mid,
		size_t bwd)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(arr + fwd, mid - fwd);

	printf("[right]: ");
	print_array(arr + mid, bwd - mid);

	for (i = fwd, j = mid; i < mid && j < bwd; k++)
		buffer[k] = (arr[i] < arr[j]) ? arr[i++] : arr[j++];
	for (; i < mid; i++)
		buffer[k++] = arr[i];
	for (; j < bwd; j++)
		buffer[k++] = arr[j];
	for (i = fwd, k = 0; i < bwd; i++)
		arr[i] = buffer[k++];

	printf("[Done]: ");
	print_array(arr + fwd, bwd - fwd);
}

/**
 * recursive_merge_sort - Implement the merge sort algorithm through recursion.
 * @subarr: A subarray of an array of integers to sort.
 * @buff: A buffer to store the sorted result.
 * @front: The front index of the subarray.
 * @back: The back index of the subarray.
 */

void recursive_merge_sort(int *arr, int *buffer, size_t fwd, size_t bwd)
{
	size_t midx;

	if (bwd - fwd > 1)
	{
		midx = fwd + (bwd - fwd) / 2;
		recursive_merge_sort(arr, buffer, fwd, midx);
		recursive_merge_sort(arr, buffer, midx, bwd);
		submerge(arr, buffer, fwd, midx, bwd);
	}
}

/**
 * merge_sort - Sort an array in ascending
 * order using the merge sort algorithm.
 * @array: array of integers.
 * @size: size of array.
 * Return: void
 */

void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	recursive_merge_sort(array, buffer, 0, size);

	free(buffer);
}
