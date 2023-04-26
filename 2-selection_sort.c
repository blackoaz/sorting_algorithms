#include "sort.h"
/**
 * selection_sort - function for sorting an array through selection sort
 * @array: array to be sorted
 * @size: the size of the array
 * Return: resturns a void
 */

void selection_sort(int *array, size_t size)
{
	int temp;
	size_t i, j, min;

	for (i = 0; i < size - 1; i++)
	{
		min = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
		}
		if (min != i)
		{
			temp = array[min];
			array[min] = array[i];
			array[i] = temp;
			print_array(array, size);
		}
	}
}
