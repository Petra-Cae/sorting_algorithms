#include "sort.h"

/**
* quick_sort - Sorts an array of integers in ascending
*		order using the Quick sort algorithm
* @array: The array to be sorted
* @size: The size of the array
*
* Return: void
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sport(array, 0, size - 1, size);
}

/**
* lomuto_pt - The partition scheme
* @array: The array to be sorted
* @lo: lower integer
* @hi: higher integer
* @size: The size of the array
*
* Return: a, the sorted integer
*/
int lomuto_pt(int *array, int lo, int hi, size_t size)
{
	int a = lo - 1, b = lo;
	int pivot = array[hi], tmp = 0;

	for (; b < hi; b++)
	{
		if (array[b] < pivot)
		{
			a++;
			if (array[a] != array[b])
			{
				tmp = array[a];
				array[a] = array[b];
				array[b] = tmp;
				print_array(array, size);
			}
		}
	}
	if (array[a + 1] != array[hi])
	{
		tmp = array[a + 1];
		array[a + 1] = array[hi];
		array[hi] = tmp;
		print_array(array, size);
	}
	return (a + 1);
}

/**
* quick_sport - quick sort algorithm
* @array: The array to be sorted
* @lo: The lower integer
* @hi: The higher integer
* @size: The size of the array
*
* Return: void
*/
void quick_sport(int *array, int lo, int hi, size_t size)
{
	int pivot;

	if (lo < hi)
	{
		pivot = lomuto_pt(array, lo, hi, size);
		quick_sport(array, lo, pivot - 1, size);
		quick_sport(array, pivot + 1, hi, size);
	}
}
