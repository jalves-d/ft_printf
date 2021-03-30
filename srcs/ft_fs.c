/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:14:21 by jalves-d          #+#    #+#             */
/*   Updated: 2021/03/30 16:14:31 by jalves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_charset(char *str, char s)
{
	int		i;
	char	*p;

	i = 0;
	if (str != NULL)
	{
		p = (char*)malloc(sizeof(char) * (ft_strlen(str) + 2));
		while (str[i])
		{
			p[i] = str[i];
			i++;
		}
	}
	else
		p = (char*)malloc(sizeof(char) * 2);
	p[i] = s;
	i++;
	p[i] = 0;
	free(str);
	return (p);
}

char	*swidht(int size, char *str, int left)
{
	char	*p;
	int		i;

	i = 0;
	if (size <= ft_strlen(str))
		return (str);
	p = (char*)malloc(sizeof(char) * (size + 1 - ft_strlen(str)));
	while (i < (size - ft_strlen(str)))
	{
		p[i] = ' ';
		i++;
	}
	p[i] = '\0';
	if (left)
		str = ft_strjoin(str, p);
	else
		str = ft_strjoin(p, str);
	return (str);
}

int		swidhtt(int size, int left)
{
	int i;

	i = 0;
	if (left)
		write(1, "\0", 1);
	while (i < (size - 1))
	{
		write(1, " ", 1);
		i++;
	}
	if (!left)
		write(1, "\0", 1);
	if (size == 0)
		return (1);
	return (size);
}

char	*prapply(int size, char *str)
{
	char	*p;
	int		i;

	if (size >= ft_strlen(str))
		return (str);
	i = 0;
	p = (char*)malloc(sizeof(char) * (size + 1));
	while (i < size)
	{
		p[i] = str[i];
		i++;
	}
	p[i] = 0;
	free(str);
	return (p);
}
