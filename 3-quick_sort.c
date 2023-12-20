#include "sort.h"

void swaps_integers(int *a, int *b);
int lomuto_partitions(int *array, size_t size, int left, int right);
void lomuto_sorting(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swaps_integers - Swaps two integers in an array
 * @a: The first int to swap.
 * @b: The second int to swap.
 */
void swaps_integers(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partitions - Order an array of ints according to
 *                    the lomuto_partitions scheme
 * @array: The array of ints
 * @size: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int lomuto_partitions(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swaps_integers(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swaps_integers(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sorting - quicksort algorithm implementor through recursion.
 * @array: An array of ints to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition
 * @right: The ending index of the array partition
 * Description: Uses the Lomuto_partition scheme.
 */
void lomuto_sorting(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partitions(array, size, left, right);
		lomuto_sorting(array, size, left, part - 1);
		lomuto_sorting(array, size, part + 1, right);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort_algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints
 *              the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sorting(array, size, 0, size - 1);
}
