#include "sort.h"
/**
 * quick_sort - perform quicksort algorithm
 * @array: array of integers
 * @size: size of the array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort_low_high(array, 0, size - 1, size);
}
/**
 * quicksort_low_high - function that includes low_idx and high_idx
 * @array: array of integers
 * @low_idx: low index in the array partitioned
 * @high_idx: high index in the array partitioned
 * @size: size of the original array
 * Return: void
 */
void quicksort_low_high(int *array, int low_idx, int high_idx, size_t size)
{
	int pivot_idx;

	if (low_idx < high_idx)
	{
		pivot_idx = Lotumo_partition(array, low_idx, high_idx, size);
		quicksort_low_high(array, low_idx, pivot_idx - 1, size);
		quicksort_low_high(array, pivot_idx + 1, high_idx, size);
	}
}
/**
 * Lotumo_partition - perform Lotumo partition scheme
 * @array: array of integers
 * @low_idx: low index in the array partitioned
 * @high_idx: high index in the array partitioned
 * @size: size of the original array
 * Return: pivot index
 */
int Lotumo_partition(int *array, int low_idx, int high_idx, size_t size)
{
	int pivot = array[high_idx];
	int i = low_idx, j, temp;

	for (j = i; j < high_idx; j++)
	{
		if (array[j] <= pivot)
		{
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
			i++;
		}
	}
	if (i != j)
	{
		temp = array[i];
		array[i] = array[high_idx];
		array[high_idx] = temp;
		print_array(array, size);
	}
	return (i);
}
