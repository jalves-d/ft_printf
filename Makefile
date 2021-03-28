SRCS	=	ft_atoi.c ft_bzero.c ft_checkflag.c  ft_flags.c ft_fs.c \
			ft_isdigit.c ft_itoa.c ft_printf.c ft_put.c ft_puthex.c \
			ft_straddend.c ft_strdup.c ft_strev.c ft_strjoin.c \
			ft_strlen.c

OBJS	= $(SRCS:.c=.o)

CC	= gcc
RM	= rm -f
CFLAGS	= -Wall -Wextra -Werror -I.

NAME = libftprintf.a

all:	$(NAME)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re:	fclean $(NAME)

.PHONY:			all clean fclean re
