#include "sort.h"

/**
* selection_sort - sorts an array of integers in ascending order
*		using the Selection sort algorithm
* @array: The array to be sorted
* @size: The size of the array to be sorted
*
* Return: void
*/
void selection_sort(int *array, size_t size)
{
	int nwarr = 0;
	size_t a, b = 0, f = 0;

	if (array == NULL || size == 0)
		return;

	for (a = 0; a < size - 1; a++)
	{
		f = a;
		for (b = a + 1; b < size; b++)
		{
			if (array[b] < array[f])
				f = b;
		}
		if (f != a)
		{
			nwarr = array[a];
			array[a] = array[f];
			array[f] = nwarr;
			print_array(array, size);
		}
	}
}
