#include <stdio.h>
/**
 * main - entry point
 * Return: Always 0.
 *
 */
int main(void)
{
	char g;

	g = 'z';
	while (g >= 'a')
	{
		putchar(g);
		g--;
	}
	putchar('\n');
	return (0);
}
