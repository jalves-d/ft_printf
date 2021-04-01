/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkflag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:06:21 by jalves-d          #+#    #+#             */
/*   Updated: 2021/04/01 13:33:58 by jalves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*checkpr(char *str, int *istr)
{
	if ((istr[4] == 0 && istr[3] == 0) || (istr[3] == 1 && istr[4] < 0))
		if (istr[1] == 1 && istr[0] == 0 && istr[2] > ft_strlen(str))
			str = precisionapply(istr[2], str);
	if (istr[3] == 1 && istr[4] > 0 && istr[4] >= ft_strlen(str))
		str = prapplyig(istr[4], str);
	else if (istr[3] == 1 && istr[4] == 0 && str[0] == '0')
		str = ft_prapply(istr[4], str);
	return (str);
}

unsigned int	ft_uns(int i)
{
	if (i > 0)
		return (i);
	else
		return (4294967295 + i + 1);
}

int	ft_checkflag(char c, char *cmp)
{
	while (*cmp)
	{
		if (*cmp == c)
			return (1);
		cmp++;
	}
	return (0);
}
