#include <stdio.h>
/**
 * main - entry point of every c code
 * Return: 0. (Success)
 *
 */
int main(void)
{
	int n;

	int l;

	n = '0';
	l = 'a';

	while (n <= '9')
	{
		putchar(n);
		n++;
	}
	while (l <= 'f')
	{
		putchar(l);
		l++;
	}
	putchar('\n');
	return (0);
}
