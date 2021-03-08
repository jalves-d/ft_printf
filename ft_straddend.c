
#include "printf.h"

char	*ft_straddend(char *str, char c)
{
	int i;
	int j;
	char *nstr;

	i = ft_strlen(str);
	nstr = (char*)malloc(sizeof(char) * (i + 2));
	if (!nstr)
		return (0);
	while (str[j])
	{
		nstr[j] = str[j];
		j++;
	}
	nstr[j++] = c;
	nstr[j] = 0;
	free (str);
	return (nstr);
}
