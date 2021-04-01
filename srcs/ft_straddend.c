/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_straddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:15:18 by jalves-d          #+#    #+#             */
/*   Updated: 2021/04/01 13:24:15 by jalves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_straddend(char *str)
{
	int		i;
	int		j;
	char	*nstr;

	i = ft_strlen(str);
	j = 0;
	nstr = (char *)malloc(sizeof(char) * (i + 1));
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
