/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:08:19 by jalves-d          #+#    #+#             */
/*   Updated: 2021/03/31 14:48:49 by jalves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_puthex(unsigned long nb, char c)
{
	char	*hex;
	int		tmp;
	int		i;

	hex = (char*)malloc(sizeof(char) * 17);
	i = 0;
	if (nb == 0)
		hex[i++] = '0';
	while (nb)
	{
		tmp = nb % 16;
		if (tmp >= 10)
			hex[i] = tmp + (c - 10);
		else
			hex[i] = tmp + '0';
		nb /= 16;
		i++;
	}
	hex[i] = 0;
	hex = ft_strev(hex);
	return (hex);
}
