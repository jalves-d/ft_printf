
#include "ft_printf.h"

char	*ft_strev(char *str)
{
	char	*rev;
	int	i;
	int	j;

	i = ft_strlen(str);
	rev = (char*)malloc(sizeof(char) * (i + 1));
	j = 0;
	i--;
	while (i >= 0)
	{
		rev[j] = str[i];
		j++;
		i--;
	}
	rev[j] = '\0';
	free (str);
	return (rev);
}
