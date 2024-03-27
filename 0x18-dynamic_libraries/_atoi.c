#include "main.h"

int _atoi(char *s)
{
	int result = 0;
	int sign = 1;
	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	while (*s != '\0')
	{
		result = result * 10 + (*s - '0');
		s++;
	}
	return sign * result;
}
