/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-d <jalves-d@42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 11:07:33 by jalves-d          #+#    #+#             */
/*   Updated: 2021/03/21 15:49:20 by jalves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

//this function need convert values long long to string to print
int	cont(long long nb)
{
	int		i;

	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		i++;
		nb = nb * -1;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(long long nbr)
{
	char	*p;
	int		nb;

	nb = cont(nbr);
	p = (char*)malloc(sizeof(char) * (nb + 1));
	if (!p)
		return (0);
	p[nb] = '\0';
	nb--;
	if (nbr == 0)
		p[0] = '0';
	if (nbr < 0)
		p[0] = '-';
	if (nbr < 0)
		nbr = nbr * -1;
	while (nbr > 0)
	{
		p[nb] = (nbr % 10) + '0';
		nbr = nbr / 10;
		nb--;
	}
	return (p);
}
