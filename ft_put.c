
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
	p[i] = '\0';
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
	while(i < size && *str)
	{
		p[i] = str[i];
		i++;
	}
	while(i < size)
	{
		p[i] = '0';
		i++;
	}	
	p[i] = 0;
	free(str);
	return (p);
}

char *executionflags(int *istr, char *str, char s)
{
	if (s == 's')
	{
		if(istr[3] == 1 && istr[4] > 0)
			str = prapply(istr[4], str);
		if(istr[2] > 0)
			str = swidht(istr[2], str, istr[0]);
	}
	else if(s == 'c')
		if(istr[2] > 0)
			str = swidht(istr[2], str, istr[0]);
	return (str);
}

char *convertfunc(va_list list, char s, char *flags)
{
	char 	*str;
	int		*nflags;

	str = 0;
	nflags = (int*)malloc(sizeof(int) * 5);	
	nflags = ft_na(nflags, flags, list);
	if (s == 'c')
		str = ft_charset(str, va_arg(list, int));
	else if(s == 's')
		str = ft_strjoin(str, va_arg(list, char*));
	else if(s == 'p')
		str = ft_strjoin("0x", ft_puthex((unsigned int)va_arg(list, void*), 'a'));
	else if(s == 'd' || s == 'i')
		str = ft_itoa(va_arg(list, int));
	else if(s == 'u')
		str = ft_itoa(4294967295 + va_arg(list, int) + 1);
	else if(s == 'x')
		str = ft_puthex(va_arg(list, unsigned int), 'a');
	else if(s == 'X')
		str = ft_puthex(va_arg(list, unsigned int), 'A');
	return (executionflags(nflags, str, s));
}
