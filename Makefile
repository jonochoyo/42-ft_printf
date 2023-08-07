# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchoy-me <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/04 12:24:47 by jchoy-me          #+#    #+#              #
#    Updated: 2023/08/07 18:17:58 by jchoy-me         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c \
		ft_printchar.c \
		ft_printstr.c \
		ft_printnbr.c \
		ft_printunbr.c \
		ft_printlhex.c \
		ft_strtoupper.c \
		ft_printptr.c \
		ft_printpercent.c \
		ft_strlen.c \
		ft_putstr.c \
		ft_putchar.c

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJS)
			ar -rcs $(NAME) $(OBJS)

clean:
		rm -f $(OBJS)

fclean:	clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re