
#include "printf.h"

char *ft_charset(char *str, char s)
{
	int i;
	char *p;

	i = 0;
	p = (char*)malloc(sizeof(char) * (ft_strlen(str) + 2));
	while(str[i])
	{
		p[i] = str[i];
		i++;
	}
	p[i] = s;
	i++;
	p[i] = 0;
	free(str);
	return (p);
}

char *swidht(int size, char *str, int left)
{
	char *p;
	int i;

	i = 0;
	p = (char*)malloc(sizeof(char) * (size  + 1 -  ft_strlen(str)));
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
	return (str);
}

char *prapply(int size, char *str)
{
	char *p;
	int i;

	if (size >= ft_strlen(str))
		return (str);
	i = 0;
	p = (char*)malloc(sizeof(char) * (size + 1));
	while (i < size)
	{
		p[i] = str[i];
		i++;
	}
	p[i] = 0;
	free(str);
	return (p);
}
