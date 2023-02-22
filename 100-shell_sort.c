#include "sort.h"

/**
* shell_sort - Sorts an array of integers in ascending order
*	using the Shell sort algorithm, using the Knuth sequence
* @array: The array to be sorted
* @size: The size of the array
*
* Return: void
*/
void shell_sort(int *array, size_t size)
{
	unsigned int a = 0, b = 0, gap = 0;
	int knst = 0;

	if (array == NULL || size < 2)
		return;

	while (gap < size / 3)
		gap = (gap * 3) + 1;

	for (; gap > 0; gap = (gap - 1) / 3)
	{
		for (a = gap; a < size; a++)
		{
			knst = array[a];
			for (b = a; b >= gap && array[b - gap] > knst;
					b -= gap)
			{
				if (array[b] != array[b - gap])
					array[b] = array[b - gap];
			}
			if (array[b] != knst)
				array[b] = knst;

		}
		print_array(array, size);
	}
}
