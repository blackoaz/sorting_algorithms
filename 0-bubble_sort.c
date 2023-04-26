#include "sort.h"
/**
 * bubble_sort - function for operating a bubble sort
 * @array: the array to be sorted through bubble sort
 * @size: the size of the array
 * Return: the function returns a void
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp, val;
	for (i = 0; i < size - 1; i++)
	{
		val = 0;
		if (array == NULL || size < 2)
			return;

		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j + 1];
				array[ j + 1] = array[j];
				array[j] = temp;
				print_array(array, size);
				val = 1;

			}
		}
		if (val == 0)
			break;
	}
}
