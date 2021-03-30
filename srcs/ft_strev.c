/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strev.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:05:13 by jalves-d          #+#    #+#             */
/*   Updated: 2021/03/30 16:06:10 by jalves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strev(char *str)
{
	char	*rev;
	int		i;
	int		j;

	i = ft_strlen(str);
	rev = (char*)malloc(sizeof(char) * (i + 1));
	j = 0;
	i--;
	while (i >= 0)
	{
		rev[j] = str[i];
		j++;
		i--;
	}
	rev[j] = '\0';
	free(str);
	return (rev);
}
