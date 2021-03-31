/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:08:37 by jalves-d          #+#    #+#             */
/*   Updated: 2021/03/31 14:50:28 by jalves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*tab;

	if (s2 == NULL)
		return (ft_strdup("(null)"));
	if (!s1)
		return (ft_strdup(s2));
	i = ft_strlen(s1) + ft_strlen(s2) + 1;
	tab = (char *)malloc(sizeof(char) * i);
	if (!tab)
		return (NULL);
	i = -1;
	while (s1[++i])
		tab[i] = s1[i];
	j = 0;
	while (s2[j])
		tab[i++] = s2[j++];
	tab[i] = '\0';
	free(s1);
	free(s2);
	return (tab);
}
