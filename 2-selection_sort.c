#include "sort.h"
/**
 * selection_sort - perform selection sort algorithm
 * @array: array of integers
 * @size: size of the array
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	int min, prev;
	unsigned int begin, selection_indx, iterator = 0;

	if (array == NULL || size < 2)
		return;
	while (iterator < size)
	{
		selection_indx += 0;
		min = array[iterator];
		for (begin = iterator; begin < size; begin++)
		{
			if (array[begin] <= min)
			{
				min = array[begin];
				selection_indx = begin;
			}
		}
		prev = array[iterator];
		array[iterator] = min;
		array[selection_indx] = prev;
		if (prev != min)
			print_array(array, size);
		iterator++;
	}
}

