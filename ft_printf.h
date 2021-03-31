/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 15:55:49 by jalves-d          #+#    #+#             */
/*   Updated: 2021/03/31 13:20:23 by jalves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

char			*ft_puthex(unsigned long nb, char c);
char			*ft_itoa_base(unsigned int n, char *base);
char			*checkpr(char *str, int *istr);
int				ft_putstr(char *str);
unsigned int	ft_uns(int i);
void			strapplyflags(char *flags, int *apply);
int				*ft_intzero(int *str, int i);
char			*ft_itoa(long long nbr);
char			*widht(int size, char *str, int left);
char			*precisionapply(int size, char *str);
char			*prapplyig(int size, char *str);
void			executionflags(int **isstr, char *str, char s, int *j);
void			convertfunc(va_list list, char s, char *flags, int *j);
char			*ft_straddend(char *str);
char			*ft_strdup(char *src);
char			*ft_strev(char *str);
char			*ft_strjoin(char *s1, char *s2);
int				ft_strlen(const char *str);
int				ft_printf(const char *s, ...);
int				ft_isdigit(int c);
int				ft_atoi(const char *str);
int				ft_checkflag(char c, char *cmp);
void			ft_bzero(void *ptr, size_t num);
char			*ft_charset(char *str, char s);
char			*swidht(int size, char *str, int left);
int				swidhtt(int size, int left);
char			*ft_prapply(int size, char *str);
int				*ft_na(int *nflags, char *flags, va_list list);

#endif
