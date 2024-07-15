#include "search_algos.h"

/**
 * binary_search - a function that searches for a value
 * in a sorted array of integers using binary search.
 *
 * @array: the pointer to the first element of the array.
 * @size: the number of elements in the array.
 * @value: the number to search for.
 *
 * Return: the index where the value is located or -1 if not present.
 */
int binary_search(int *array, size_t size, int value)
{
	size_t min_index, max_index, mid;
	size_t i;

	if (!array)
		return (-1);

	min_index = 0;
	max_index = size - 1;

	while (min_index <= max_index)
	{
	/* Print the array being searched*/
	printf("Searching in array: ");
	for (i = min_index; i <= max_index; i++)
	{
		printf("%d", array[i]);
		if (i < max_index)
		printf(", ");
	}
	printf("\n");

	mid = min_index + (max_index - min_index) / 2;

	if (array[mid] == value)
		return (mid);
	else if (array[mid] < value)
		min_index = mid + 1;
	else
		max_index = mid - 1;
	}

	return (-1);
}
