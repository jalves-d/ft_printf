# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jalves-d <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/30 16:02:45 by jalves-d          #+#    #+#              #
#    Updated: 2021/03/30 16:02:55 by jalves-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	srcs/ft_atoi.c srcs/ft_bzero.c srcs/ft_checkflag.c  srcs/ft_flags.c srcs/ft_fs.c \
			srcs/ft_isdigit.c srcs/ft_itoa.c ft_printf.c srcs/ft_put.c srcs/ft_itoa_base.c \
			srcs/ft_straddend.c srcs/ft_strdup.c srcs/ft_strev.c srcs/ft_strjoin.c \
			srcs/ft_strlen.c srcs/ft_puthex.c

OBJS	= $(SRCS:.c=.o)

CC	= gcc
RM	= rm -f
CFLAGS	= -Wall -Wextra -Werror -I includes

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
