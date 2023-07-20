#include "main.h"
/**
 * print_last_digit - to prin out the last digit of a number.
 * @n: the number whose last digit is being printed.
 * Return: the value of the last digit
 *
 */
int print_last_digit(int n)
{
	int i;

	if (n < 0)
		n = -n;

	i = n % 10;

	if (i < 0)
		i = -i;

	_putchar(i + '0');
	return (i);
}
