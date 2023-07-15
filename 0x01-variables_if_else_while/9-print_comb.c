#include <stdio.h>
/**
 * main - entry point of every code in c
 * Return:0 (Success)
 *
 */
int main(void)
{
	int n;

	n = '0';
	while (n <= '9')
	{
		putchar(n);
		n++;
		if (n <= '9')
		{
			putchar(',');
			putchar(' ');
		}
	}
	putchar('\n');
	return (0);
}
