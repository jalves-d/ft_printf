
#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

void	ft_init(char *str)
{
	str[0] = 0;
}

int	ft_printreturn(char *str, int i)
{

	i += ft_strlen(str);
	ft_putstr(str);
	str = 0;
	free(str);
	return (i);
}

<<<<<<< HEAD
int	checkpercent(const char *s, va_list list, int i, int *h)
=======
int	checkpercent(char **str, const char *s, va_list list, int i, int *h)
>>>>>>> 540e083ded7f601b37d5b5c45c58dcf88a747e83
{
	char *flasmem;

	flasmem = (char*)malloc(sizeof(char) * 1);
	ft_init(flasmem);
	while (ft_checkflag(s[i], "-.*") || ft_isdigit(s[i]))
	{
		flasmem = ft_charset(flasmem, s[i]);
		i++;
	}
	if (ft_checkflag(s[i], "n"))
		*va_arg(list, int*) = *h;
	else if (ft_checkflag(s[i], "cspdiuxX%"))
<<<<<<< HEAD
		ft_putstr(convertfunc(list, s[i], flasmem, &(*h)));
=======
		*str = ft_strjoin(p, convertfunc(list, s[i], flasmem, &(*h)));
>>>>>>> 540e083ded7f601b37d5b5c45c58dcf88a747e83
	if (flasmem[0] != 0)
		free(flasmem);
	return (i);
}

int	ft_printf(const char *s, ...)
{
	va_list list;
	int i;
<<<<<<< HEAD
=======
	char *str;
>>>>>>> 540e083ded7f601b37d5b5c45c58dcf88a747e83
	int j;

	i = 0;
	j = 0;
<<<<<<< HEAD
=======
	str = (char*)malloc(sizeof(char) * 1);
	ft_init(str);
>>>>>>> 540e083ded7f601b37d5b5c45c58dcf88a747e83
	va_start(list, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
<<<<<<< HEAD
			i = checkpercent(s, list, i, &j);
=======
			i = checkpercent(&str, s, list, i, &j);
>>>>>>> 540e083ded7f601b37d5b5c45c58dcf88a747e83
		}
		else
			j += write(1, &s[i], 1);
		i++;
	}
	va_end(list);
<<<<<<< HEAD
	return (j);
=======
	return (ft_printreturn(str, j));
>>>>>>> 540e083ded7f601b37d5b5c45c58dcf88a747e83
}
