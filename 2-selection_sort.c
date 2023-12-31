#include "sort.h"

/**
 * swaps_integers - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swaps_integers(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - Sort an array of integers in ascending order
 *                  use the selection_sort_algorithm.
 * @array: An array of ints.
 * @size: The size of the array.
 *
 * Description: Prints the array after each and every swap.
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array + i;
		for (j = i + 1; j < size; j++)
			min = (array[j] < *min) ? (array + j) : min;

		if ((array + i) != min)
		{
			swaps_integers(array + i, min);
			print_array(array, size);
		}
	}
}
