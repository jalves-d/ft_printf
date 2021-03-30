/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:08:19 by jalves-d          #+#    #+#             */
/*   Updated: 2021/03/30 16:27:52 by jalves-d         ###   ########.fr       */
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
