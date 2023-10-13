#include "variadic_functions.h"
#include <stdarg.h>
/**
 * sum_them_all - function that returns the sum 
 * @n: number of arguments
 * Return: 0
 */
int sum_them_all(const unsigned int n,...)
{
	/* creating va_list to store the variable argument list */
	va_list my_num;
	unsigned int i;
	int sum;

	if (n == 0)
		return (0);
	sum =0;

	/* init valist for the number of arguments */
	va_start(my_num, n);

	/* loop through/access all arguments stored in the valist */
	for (count = 0; count < n; count++)
		sum += va_arg(my_num, int);

	va_end(my_num);
	return (sum);
}
