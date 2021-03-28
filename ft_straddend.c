
#include "ft_printf.h"

char	*ft_straddend(char *str)
{
	int	i;
	int	j;
	char	*nstr;

	i = ft_strlen(str);
	j = 0;
	nstr = (char*)malloc(sizeof(char) * (i + 1));
	if (!nstr)
		return (0);
	while (str[j])
	{
		nstr[j] = str[j];
		j++;
	}
	nstr[j] = 0;
	return (nstr);
}
