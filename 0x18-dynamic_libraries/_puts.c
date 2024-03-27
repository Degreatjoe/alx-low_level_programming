#include "main.h"

void _puts(char *s)
{
	while (*s)
	{
		write(1, s, 1);
		s++;
	}
	write(1, "\n", 1);
}
