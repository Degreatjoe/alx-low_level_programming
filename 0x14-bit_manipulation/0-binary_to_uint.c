#include "main.h"
/**
 * binary_to_uint - converts a binary number to unsigned int 
 * after reading 
 * @b: it is a string that would contain the binary number
 *
 * Return: the number that has been converted.
 */
unsigned int binary_to_uint(const char *b)
{
	int first;
	unsigned int number;

	number = 0;
	if (!b)
		return (0);
	for (first = 0; b(first) != '\0'; first++)
	{
		if(b[first] != '0' && b[first] != '1')
			return(0);
	}
	for (first = 0; b[first] != '\0'; first++)
	{
		number <<= 1;
		if (b[first] == '1')
			number += 1;
	}
	return(number);
}
