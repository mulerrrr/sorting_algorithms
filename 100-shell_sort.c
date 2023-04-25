#include "sort.h"
/**
 * shell_sort - perform shell sort algorithm
 * @array: array of integers
 * @size: size of the array
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	unsigned int gap = 1, outer, rigth_val;
	int value_insert;

	if (array == NULL || size < 2)
		return;

	while (gap < (size / 3))
		gap = (gap * 3) + 1;

	while (gap > 0)
	{
		for (outer = gap; outer < size; outer++)
		{
			/*Entering first interval or gap*/
			value_insert = array[outer];
			rigth_val = outer;

/*Make insertion sort between values in gap and changing the original array*/
			while (rigth_val > gap - 1 && array[rigth_val - gap] >= value_insert)
			{
				array[rigth_val] = array[rigth_val - gap];
				rigth_val = rigth_val - gap;
			}
			array[rigth_val] = value_insert;
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}

