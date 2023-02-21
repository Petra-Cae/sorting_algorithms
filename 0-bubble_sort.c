#include "sort.h"

/**
* bubble_sort - bubble sorts an array in ascending order
* @array: The array to be sorted
* @size: The length of the array
*
* Return: void
*/
void bubble_sort(int *array, size_t size)
{
	size_t a, b = 0;
	int new_arr = 0;

	if (array == NULL || size == 0)
		return;

	for (a = 0; a < size - 1; a++)
	{
		for (b = 0; b < size - a - 1; b++)
		{
			if (array[b] > array[b + 1])
			{
				new_arr = array[b + 1];
				array[b + 1] = array[b];
				array[b] = new_arr;
				print_array(array, size);
			}
		}
	}
}
