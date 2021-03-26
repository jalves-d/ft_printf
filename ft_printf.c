
#include "printf.h"

void ft_putstr(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if (str[i] == 127)
			write(1, "\0", 1);
		else
			write(1, &str[i], 1);
		i++;
	}
}

void ft_init(char *str)
{
	str[0] = 0;
}
int ft_printreturn(char *str)
{
	int i;

	i = ft_strlen(str);
	ft_putstr(str);
	str = 0;
	free(str);
	return (i);
}

int		checkpercent(char **str, const char *s, va_list list, int i)
{
	char *flasmem;
	char *p;
	int	j;

	p = *str;
	flasmem = (char*)malloc(sizeof(char) * 1);
	ft_init(flasmem);
	while(ft_checkflag(s[i], "-.*") || ft_isdigit(s[i]))
	{
		flasmem = ft_charset(flasmem, s[i]);
		i++;
	}
	if (ft_checkflag(s[i], "n"))
		j = ft_strlen(*str);
	if (ft_checkflag(s[i], "n"))
		*va_arg(list, int*) = j;
	else if (ft_checkflag(s[i], "cspdiuxX%"))
		*str = ft_strjoin(p, convertfunc(list, s[i], flasmem));	
	if (flasmem[0] != 0)
		free(flasmem);
	return (i);
}

int		ft_printf(const char *s, ...)
{
	va_list list;
	int i;
	char *str;

	i = 0;
	str = (char*)malloc(sizeof(char) * 1);
	ft_init(str);
	va_start(list, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			i = checkpercent(&str, s, list, i);
		}
		else
			str = ft_charset(str, s[i]);
		i++;
	}
	va_end(list);
	return (ft_printreturn(str));
}
