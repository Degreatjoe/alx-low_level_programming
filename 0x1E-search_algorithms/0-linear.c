#include "search_algos.h"
/**
 * linear_search - a function that searches for
 * a value in an array of intergers using
 * linear search.
 *
 * @array: the pointer to the first element in
 *  the array.
 * @size: the number of values in the array
 * @value: the value to search for
 *
 * Return: the index of the array where the value was found.
 */
int linear_search(int *array, size_t size, int value)
{
	size_t index;

	if (array == NULL)
	{
		return (-1);
	}

	for (index == 0; index < size; index++)
	{
		printf("Value checked array[%lu] = [%d]\n", index, array[index]);
		if (array[index] == value)
		{
			return (index);
		}
	}
	return (-1);
}

