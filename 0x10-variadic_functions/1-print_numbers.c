#include <stdio.h>
#include "variadic_functions.h"
#include <stdarg.h>

/**
 * print_numbers - function that prints numbers.
 * @n: resepresents the number of arguments
 * @separator: resepresents the seperator b/w the numbers
 * Return: Always 0.
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	/* creating va_list to store the variable argument list */
	va_list my_num;
	unsigned int i;
	/* init valist for the number of arguments */

	va_start(my_num, n);

	/* loop through/access all arguments stored in the valist */
	for (i =0; i < n; i++)
	{
		printf("%d", va_args(my_num, unsigned int));

		if (i < (n - 1) && separator != NULL)
		{
			printf("%s", separator);
		}
	}
	va_end(my_nums);
	printf("\n");
}
