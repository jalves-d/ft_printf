
#include "printf.h"

void ft_putstr(char *str)
{
	int i;
	
	i = 0;
	while(str[i])
	{
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
	ft_putstr(str);
	return (ft_strlen(str));
}

int		checkpercent(char **str, const char *s, va_list list, int i)
{
	char *flasmem;
	char *p;
	
	p = *str;
	flasmem = (char*)malloc(sizeof(char) * 1);
	ft_init(flasmem);
	while(ft_checkflag(s[i], "-.*") || ft_isdigit(s[i]))
	{
		flasmem = ft_charset(flasmem, s[i]);
		i++;
	}
	if(ft_checkflag(s[i], "cspdiuxX%"))
		*str = ft_strjoin(p, convertfunc(list, s[i], flasmem));
	else
		return (-1);
	return (i);
}

int		ft_printf(const char *s, ...)
{
	va_list list;
	int i;
	char *str;

	i = 0;
	str = (char*)malloc(sizeof(char) * 1);
	va_start(list, s);
	while (s[i])
	{
		if(s[i] == '%')
		{
			i++;
			i = checkpercent(&str, s, list, i);
			if (i == -1)
				return (0);			
		}
		else
			str = ft_charset(str, s[i]);
		i++;
	}
	return (ft_printreturn(str));
}
