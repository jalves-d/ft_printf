/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:22:06 by jalves-d          #+#    #+#             */
/*   Updated: 2021/03/31 15:29:33 by jalves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

void	ft_init(char *str)
{
	str[0] = 0;
}

int		checkpercent(const char *s, va_list list, int i, int *h)
{
	char *flasmem;

	flasmem = (char*)malloc(sizeof(char) * 1);
	ft_init(flasmem);
	while (ft_checkflag(s[i], "-.*") || ft_isdigit(s[i]))
	{
		flasmem = ft_charset(flasmem, s[i]);
		i++;
	}
	if (ft_checkflag(s[i], "n"))
		*va_arg(list, int*) = *h;
	else if (ft_checkflag(s[i], "cspdiuxX%"))
		convertfunc(list, s[i], flasmem, &(*h));
	free(flasmem);
	return (i);
}

int		ft_printf(const char *s, ...)
{
	va_list list;
	int		i;
	int		j;

	i = 0;
	j = 0;
	va_start(list, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			i = checkpercent(s, list, i, &j);
		}
		else
			j += write(1, &s[i], 1);
		i++;
	}
	va_end(list);
	return (j);
}
