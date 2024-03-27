#include "main.h"

char *_memcpy(char *dest, char *src, unsigned int n)
{
	char *ptr_dest = dest;
	char *ptr_src = src;
	while (n > 0)
	{
		*ptr_dest = *ptr_src;
		ptr_dest++;
		ptr_src++;
		n--;
	}
	return dest;
}
