
#include "ft_printf.h"

int	*ft_intzero(int *str, int i)
{
	while (i >= 0)
	{
		str[i] = 0;
		i--;
	}
	return (str);
}

void	applyprec(char *flags, int i, int *apply)
{
	char	*numt;

	numt = (char*)malloc(sizeof(char) * 1);
	numt[0] = 0;
	if (flags[i] == '.')
	{
		apply[3] = 1;
		i++;
		if (flags[i] == '*')
			apply[4] = -1;
		if (flags[i] == '*')
			i++;
		else
		{
			while (ft_isdigit(flags[i]))
			{
				numt = ft_charset(numt, flags[i]);
				i++;
			}
			if (numt[0] != 0)
				apply[4] = ft_atoi(numt);
		}
	}
	free(numt);
}

void	strapplynums(char *flags, int i, int *apply)
{
	char	*num;

	num = (char*)malloc(sizeof(char) * 1);
	num[0] = 0;
	if (flags[i] == '*')
	{
		apply[2] = -1;
		i++;
	}
	else
	{
		while (ft_isdigit(flags[i]))
		{
			num = ft_charset(num, flags[i]);
			i++;
		}
		if (num[0] != 0)
			apply[2] = ft_atoi(num);
	}
	applyprec(flags, i, apply);
	free(num);
}

void	strapplyflags(char *flags, int *apply)
{
	int	i;

	i = 0;
	if (flags[i] == '0' && flags[i + 1] == '-')
		i++;
	while (flags[i] == '-')
	{
		apply[0] = 1;
		i++;
	}
	if (flags[i] == '0')
	{
		apply[1] = 1;
		i++;
	}
	strapplynums(flags, i, apply);
}

int	*ft_na(int *nflags, char *flags, va_list list)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		nflags[i] = 0;
		i++;
	}
	strapplyflags(flags, nflags);
	if (nflags[2] == -1)
	{
		nflags[2] = va_arg(list, int);
		if (nflags[2] < 0)
			nflags[0] = 1;
		if (nflags[2] < 0)
			nflags[2] *= -1;
	}
	if (nflags[4] == -1)
		nflags[4] = va_arg(list, int);
	return (nflags);
}
