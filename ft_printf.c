
#include "printf.h"

// first the program need receive the string for print, and after receive the variables, we need the check the chars '%'.
//if have other '%' print % and cant have special character,
void	ft_printf(char *s, ...)
{
	va_list list;
	va_start (list, s);
	unsigned int i;
	unsigned int j;
	char *flasmem;
	char *str;

	i = 0;
	while (s[i])
	{
		if(s[i] == '%')
		{
			i++;
			if(s[i] == '%' || (s[i] == ' ' && s[i + 1] == '%'))
			{
				ft_straddend(str, '%');
				i = i + 2;
			}
			else
				j = 0;
				while(ft_checkflag(s[i], "-.*") || isdigit(s[i]))
					flasmem[j++] = s[i++];
				if(ft_checkflag(s[i], "cspdiuxX"))
					str = ft_strjoin(str, convertfunc(list, s, flasmem));
				else
					break;
		}
		i++;
	}
	printf("%s", str);
}
