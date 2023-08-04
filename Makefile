# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchoy-me <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/04 12:24:47 by jchoy-me          #+#    #+#              #
#    Updated: 2023/08/04 13:03:35 by jchoy-me         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c \
		ft_putchar_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_strlen.c

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJS)

clean:
		rm -f $(OBJS)

fclean:	clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re