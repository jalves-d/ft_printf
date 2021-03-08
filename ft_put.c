
#include "printf.h"

char *widht(int size, char *str, int left)
{
	char *p;
	int i;

	i = 0;
	p = (char*)malloc(sizeof(char) * (size + 1 -  ft_strlen(str)));
	while (i < (size - ft_strlen(str)))
	{
		p[i] = ' ';
		i++;
	}
	p = '\0';
	if(left)
		str = ft_strjoin(str, p);
	else
		str = ft_strjoin(p, str);
	free(p);
	return (str);
}

char *precisionapply(int size, char *str)
{
	char *p;
	int i;

	i = 0;
	p = (char*)malloc(sizeof(char) * (size + 1));
	while(i < size)
	{
		p[i] = str[i];
		i++;
	}
	p[i] = 0;
	free(str);
	return (p);
}

char *executionflags(int *istr, char *str)
{
	if(istr[3] == '.' && istr[4] > 0)
		str = precisionapply(istr[4], str);
	if(istr[2])
		str = widht(istr[2], str, istr[0]);
	return (str);
}

char *convertfunc(va_list list, char s, char *flags)
{
	char 	*str;
	int		*nflags;

		nflags = strapplyflags(flags);
		if (nflags[2] == -1)
			nflags[2] = va_arg(list, int);
		if (nflags[4] == -1)
			nflags[4] = va_arg(list, int);
		if(s == 'c')
			str = ft_straddend(va_arg(list, char));
		else if(s == 's')
			str = ft_strjoin(str, va_arg(list, char*));
		else if(s == 'p')
			str = ft_convertpointer(va_arg(list, void*), flags);
		else if(s == 'd')
			str = ft_itoa(va_arg(list, int));
		else if(s == 'i')
			str = ft_itoa(va_arg(list, int));
		else if(s == 'u')
			str = ft_itoa(4294967295 + va_arg(list, int) + 1);
		else if(s == 'x')
			str = ft_puthex(va_arg(list, unsigned int), 'a');
		else if(s == 'X')
			str = ft_puthex(va_arg(list, unsigned int), 'A');
	return (executionflags(nflags, str));
}
