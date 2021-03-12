#ifndef PRINTF_H
#define PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct	s_flags
{
	int			minus;
	int			zero;
	int			star;
	int			min_width;
	int			point;
	int			precision;
	char		type;
}				t_flags;

void	strapplyflags(char *flags, int *apply);
int		*ft_intzero(int *str, int i);
char	*ft_itoa(long long nbr);
char 	*widht(int size, char *str, int left);
char 	*precisionapply(int size, char *str);
char 	*executionflags(int *istr, char *str, char s);
char 	*convertfunc(va_list list, char s, char *flags);
char	*ft_puthex(u_int64_t nb, char c);
char	*ft_straddend(char *str, char c);
char	*ft_strdup(char *src);
char 	*ft_strev(char *str);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(const char *str);
int		ft_printf(const char *s, ...);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
int 	ft_checkflag(char c, char *cmp);
void	ft_bzero(void *ptr, size_t num);
char 	*ft_charset(char *str, char s);
char 	*swidht(int size, char *str, int left);
char 	*prapply(int size, char *str);
int		*ft_na(int *nflags, char *flags, va_list list);

#endif
