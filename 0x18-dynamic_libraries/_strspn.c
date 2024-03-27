#include "main.h"

unsigned int _strspn(char *s, char *accept)
{
	unsigned int count = 0;
	while (*s != '\0' && *accept != '\0' && *s == *accept)
	{
		count++;
		s++;
		accept++;
	}
	return count;
}
