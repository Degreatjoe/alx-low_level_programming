#include "variadic_functions.h"
#include <stdarg.h>
/**
 * sum_them_all - function that returns the sum 
 * @n: number of arguments
 * Return: 0
 */
int sum_them_all(const unsigned int n, ...)
{
	/** creating va_list to store the variable argument list */
	va_list my_nums;
	unsigned int i;
	int sum;

	if (n == 0)
		return (0);
	sum = 0;

	/** init valist for the number of arguments */
	va_start(my_nums, n);

	/** loop through/access all arguments stored in the valist */
	for (i = 0; i < n; i++)
		sum += va_arg(my_nums, int);

	va_end(my_nums);
	return (sum);
}
