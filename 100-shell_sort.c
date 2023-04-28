#include "sort.h"
/**
 * swap - function for swapping two integers
 * @m: the first value
 * @n: the second value
 * Return: returns nothing
 */
void swap(int *m, int *n)
{
	int temp = *m;
	*m = *n;
	*n = temp;
}
/**
 * shell_sort - function that sorts array of interger using shell sort
 * @array: the array to be sorted
 * @size: size of the array
 * Return: returns a void
 */
void shell_sort(int *array, size_t size)
{
	int temp;
	size_t i, j, diff = 0;

	while (diff < size / 3)
		diff = diff * 3 + 1;
	while (diff > 0)
	{
		for (i = diff; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= diff && array[j - diff] > temp; j -= diff)
			{
				if (array[j - diff] > temp)
					swap(&array[j], &array[j - diff]);
			}
			array[j] = temp;
		}
		print_array(array, size);
		diff = (diff - 1) / 3;
	}

}
