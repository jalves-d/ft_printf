
#include "printf.h"

char *precisionapply(int size, char *str)
{
	char *p;
	int i;
	int check;

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
	while(i++ < (size - ft_strlen(str)) - 1)
		p[i] = '0';
	p[i] = 0;
	p = ft_strjoin(p, str);
	if (check == 1)
		p[0] = '-';
	free(str);
	return (p);
}

char *executionflags(int **isstr, char *str, char s)
{
	int *istr;

	istr = *isstr;
	if (s == 's')
		if(istr[3] == 1 && istr[4] > 0)
			str = prapply(istr[4], str);
	if (s == 'd')
	{
		if (istr[3] == 1 && istr[4] > 0)
			str = precisionapply(istr[4], str);
		if (istr[1] == 1 && istr[3] == 0 && istr[0] == 0)
		   str = precisionapply(istr[2], str);
	}
	if (istr[2] > 0 && istr[1] == 0)
		str = swidht(istr[2], str, istr[0]);
	return (str);
}

char *convertfunc(va_list list, char s, char *flags)
{
	char 	*str;
	int		*nflags;
	char 	*ns;

	str = 0;
	ns = ft_straddend("0x");
	nflags = (int*)malloc(sizeof(int) * 5);
	nflags = ft_na(nflags, flags, list);
	if (s == 'c')
		str = ft_charset(str, va_arg(list, int));
	else if (s == 's')
		str = ft_strjoin(str, va_arg(list, char*));
	else if (s == 'p')
		str = ft_strjoin(ns, ft_puthex(((unsigned long)va_arg(list, void*)), 'a'));
	else if (s == 'd' || s == 'i')
		str = ft_itoa(va_arg(list, int));
	else if (s == 'u')
		str = ft_itoa(4294967295 + va_arg(list, int) + 1);
	else if (s == 'x')
		str = ft_puthex(va_arg(list, unsigned long), 'a');
	else if (s == 'X')
		str = ft_puthex(va_arg(list, unsigned long), 'A');
	return (executionflags(&nflags, str, s));
}
