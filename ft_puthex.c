
#include "printf.h"

char	*ft_puthex(u_int64_t nb, char c)
{
	char	*hex;
	int		tmp;
	int		i;

	hex = (char*)malloc(sizeof(char) * 17);
	i = 0;
	if (nb == 0)
	{
		hex[i] = '0';
		i++;
	}
	while (nb)
	{
		tmp = nb % 16;
		hex[i] = (tmp + (tmp >= 10 ? (c - 10) : '0'));
		nb /= 16;
		i++;
	}
	hex[i] = 0;
	hex = ft_strev(hex);
	return (hex);
}
