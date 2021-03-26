/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-d <jalves-d@42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 11:06:56 by jalves-d          #+#    #+#             */
/*   Updated: 2021/03/25 13:24:41 by jalves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

int	ft_atoi(const char *str)
{
	long int	i;
	int	negative;
	long int	num;

	num = 0;
	i = 0;
	negative = 1;
	while (str[i] == ' ' || str[i] == '\f'
		|| str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		negative *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i] - '0';
		i++;
	}
	return (num * negative);
}
