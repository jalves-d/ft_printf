/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-d <jalves-d@42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 11:09:45 by jalves-d          #+#    #+#             */
/*   Updated: 2021/03/22 13:34:42 by jalves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char			*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*p;
	unsigned int	i;
	char			*init;

	p = (char*)malloc(sizeof(const char) * (len + 1));
	if (!p || !s)
		return (0);
	i = start + len;
	if (start >= ft_strlen(s))
		return (p);
	init = p;
	while (start < i)
		*(p++) = *(s + start++);
	*(p++) = '\0';
	return (init);
}
