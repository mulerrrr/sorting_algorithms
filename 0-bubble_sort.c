#include "sort.h"
/**
 * bubble_sort - bubble sort algorithm
 * @array: array as input
 * @size: size of the array
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int j;
	int swapped = 1;

	if ((array == NULL) || size < 2)
		return;

	while (swapped != 0)
	{
		swapped = 0;
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				swapped = 1;
				print_array(array, size);
			}
		}
	}
}
/**
 * swap - swap between two values
 * @actual: actual value
 * @next: next value
 * Return: void
 */
void swap(int *actual, int *next)
{
	int temp = *actual;
	*actual = *next;
	*next = temp;
}

