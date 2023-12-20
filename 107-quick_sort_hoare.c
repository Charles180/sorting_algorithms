#include "sort.h"
void swap_ints(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

/**
  *swap_ints - Fuctions that swaps 2 ints
  *
  *@a: The first integer to swap.
  *
  *@b: The second integer to swap.
  */
void swap_ints(int *a, int *b)
{
	int temporary;

	temporary = *a;
	*a = *b;
	*b = temporary;
}

/**
  *hoare_partition - Order a subset of an array
  *
  *@array: The array of integers.
  *
  *@size: array size.
  *
  *@left: The starting index of the subset to order.
  *
  *@right: The ending index of the subset to order.
  *
  *Return: The final partition index.
  *
  */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int pvt, up, down;

	pvt = array[right];
	for (up = left - 1, down = right + 1; up < down;)
	{
		do {
			up++;
		} while (array[up] < pvt);
		do {
			down--;
		} while (array[down] > pvt);

		if (up < down)
		{
			swap_ints(array + up, array + down);
			print_array(array, size);
		}
	}

	return (up);
}

/**
  *hoare_sort - Implement the quicksort algorithm through recursion.
  *
  *@array: An array of integers to sort.
  *
  *@size: The size of the array.
  *
  *@left: The starting index of the array partition to order.
  *
  *@right: The ending index of the array partition to order
  *
  */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, part - 1);
		hoare_sort(array, size, part, right);
	}
}

/**
 * quick_sort_hoare - Sort an array of integers in ascending
 *                    order using the quicksort algorithm.
 *
 *@array: An array of integers.
 *
 *@size: The size of the array.
 *
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	hoare_sort(array, size, 0, size - 1);
}
