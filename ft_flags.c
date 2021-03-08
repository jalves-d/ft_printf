
#include "printf.h"

int		*ft_intzero(int *str, int i)
{
	while(i >= 0)
	{
		str[i] = 0;
		i--;
	}
	return (str);
}

int	*strapplyflags(char *flags)
{
	int apply[5];
	char *num;
	int i;

	i = 0;
	apply = ft_intzero(apply, 3);
	if (flags[i] == '-')
	{
		apply[0] = 1;
		i++;
	}
	if (flags[i] == '0')
	{
		apply[1] = 1;
		i++;
	}
	if (flags[i] == '*')
	{
		apply[2] = -1;
		i++;
	}
	else
		while(isdigit(flags[i]))
		{
			ft_straddend(num, flags[i]);
			i++;
		}
		apply[2] = ft_atoi(num);
		num = ft_intzero(num, ft_strlen(num));
	if(flags[i] == '.')
	{
		apply[3] = 1;
		i++;
		while(isdigit(flags[i]))
		{
			ft_straddend(num, flags[i]);
			i++;
		}
		apply[4] = ft_atoi(num);
	}
	return (apply);
}
