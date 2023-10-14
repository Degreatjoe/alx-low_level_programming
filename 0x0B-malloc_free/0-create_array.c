#include <stdio.h>
#include "main.h"
#include <stdlib.h>
/*
 * main -  a function that creates an array of chars,
 * and initializes it with a specific char.
 *
 * @creat_array - to creat an array of characters
 *
 * Return ; 0
 */
char *create_array(unsigned int size, char c)
{
	char *add_mal;
	unsigned int count;

	add_mal = malloc(size * sizeof(char));

	if (size == NULL )
	{
		return (NULL);
	}

	for (count = 0; count < size; count++)
	{
		/*if (size == NULL)
		{
			return (NULL);
		}*/
		add_mal[count] = c;
	}
	return (add_mal);
}

