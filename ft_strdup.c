
#include "ft_printf.h"

char	*ft_strdup(char *src)
{
	char	*p;
	int		i;

	p = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	i = 0;
	if (p == NULL)
	{
		return (NULL);
	}
	while (src[i])
	{
		p[i] = src[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
