
#include "ft_printf.h"

unsigned int	ft_uns(int i)
{
	if (i > 0)
		return (i);
	else
		return (4294967295 + i + 1);
}

int	ft_checkflag(char c, char *cmp)
{
	while (*cmp)
	{
		if (*cmp == c)
			return (1);
		cmp++;
	}
	return (0);
}
