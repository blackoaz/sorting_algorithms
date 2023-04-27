#include "sort.h"
/**
 * partition - function for partioning an array
 * @array: array to be partioned
 * @start: start of the array
 * @end: end of the array
 * @size: size of the array to be partioned
 * Return: returns the position of the pivot
 */
int partition(int *array, int start, int end, int size)
{
	int pivot = array[end];
	int i = start, j, temp;

	for (j = start; j < end; j++)
	{
		if (array[j] <= pivot)
		{
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
			i++;
		}
	}
	if (i != end)
	{
		temp = array[i];
		array[i] = array[end];
		array[end] = temp;
		print_array(array, size);
	}
	return (i);
}
/**
 * quickSort - function for sorting array recursively
 * @array: array to be sorted
 * @start: start of partiotned subarray
 * @end: end of partitoned subarray
 * @size: size of the array to be sorted
 */
void quickSort(int *array, int start, int end, int size)
{
	int k;

	if (start < end)
	{
		k = partition(array, start, end, size);
		quickSort(array, start, k - 1, size);
		quickSort(array, k + 1, end, size);
	}
}
/**
 * quick_sort - function for executing quicksort array
 * @array: array to be sorted
 * @size: size of of the array to be sorted
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quickSort(array, 0, size - 1, size);
}
