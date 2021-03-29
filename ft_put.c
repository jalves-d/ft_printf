
#include "ft_printf.h"

char	*precisionapply(int size, char *str)
{
	char	*p;
	int	i;
	int	check;

	i = -1;
	check = 0;
	p = (char*)malloc(sizeof(char) * ((size - ft_strlen(str)) + 1));
	if (size > ft_strlen(str))
	{
		if (str[0] == '-')
			check = 1;
		if (str[0] == '-')
			str[0] = '0';
	}
	while (i++ < (size - ft_strlen(str)) - 1)
		p[i] = '0';
	p[i] = 0;
	p = ft_strjoin(p, str);
	if (check == 1)
		p[0] = '-';
	free(str);
	return (p);
}

char	*prapplyig(int size, char *str)
{
	char	*p;
	int	i;
	int	check;

	i = -1;
	check = 0;
	p = (char*)malloc(sizeof(char) * ((size - ft_strlen(str)) + 1));
	if (size >= ft_strlen(str))
	{
		if (str[0] == '-')
			check = 1;
		if (str[0] == '-')
			str[0] = '0';
	}
	while (i++ < (size - ft_strlen(str)) + check - 1)
		p[i] = '0';
	p[i] = 0;
	p = ft_strjoin(p, str);
	if (check == 1)
		p[0] = '-';
	free(str);
	return (p);
}

void	executionflags(int **isstr, char *str, char s, int *j)
{
	int *istr;

	istr = *isstr;
	if (s == '%')
		str = ft_charset(str, 37);
	if (s == 's' && istr[3] == 1 && istr[4] >= 0)
		str = prapply(istr[4], str);
	if (ft_checkflag(s, "diuxX%"))
		str = checkpr(str, istr);
	if (istr[2] >= 0 && s == 'c' && ft_strlen(str) == 0)
		*j += swidhtt(istr[2], istr[0]);
	else if (istr[2] > 0)
	{
		str = swidht(istr[2], str, istr[0]);
		*j += ft_strlen(str);
	}
	else 
		*j += ft_strlen(str);
	ft_putstr(str);
	free(str);
}

char	*prtopointer(char *str, int *istr)
{
	char	*ns;

	ns = ft_straddend("0x");
	if (istr[3] == 1 && istr[4] > 0)
		if (istr[4] >= ft_strlen(str))
			str = prapplyig(istr[4], str);
	if (istr[1] == 1 && istr[3] == 0 && istr[0] == 0)
		if (istr[2] > 0 && istr[2] > ft_strlen(str))
	   		str = precisionapply(istr[2], str);
	if (istr[3] == 1 && istr[4] == 0)
		str = prapplyig(istr[4], str);
	str = ft_strjoin(ns, str);
	return (str);
}

void	convertfunc(va_list list, char s, char *flags, int *j)
{
	char	*str;
	int	*nflags;

	str = 0;
	nflags = (int*)malloc(sizeof(int) * 5);
	nflags = ft_na(nflags, flags, list);
	if (s == 'c')
		str = ft_charset(str, va_arg(list, int));
	else if (s == 's')
		str = ft_strjoin(str, va_arg(list, char*));
	else if (s == 'p')
		str = prtopointer(ft_puthex(((unsigned long)va_arg(list, void*)), 'a'), nflags);
	else if (s == 'd' || s == 'i')
		str = ft_itoa(va_arg(list, int));
	else if (s == 'u')
		str = ft_itoa(ft_uns(va_arg(list, int)));
	else if (s == 'x')
		str = ft_puthex(va_arg(list, unsigned long), 'a');
	else if (s == 'X')
		str = ft_puthex(va_arg(list, unsigned long), 'A');
	executionflags(&nflags, str, s, &(*j));
	free(nflags);
}
