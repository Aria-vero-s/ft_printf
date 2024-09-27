# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asaulnie <asaulnie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/13 15:56:53 by asaulnie          #+#    #+#              #
#    Updated: 2024/06/17 15:48:21 by asaulnie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c ft_itoa.c ft_itoa_base.c ft_strlen.c ft_printc.c ft_prints.c ft_printp.c ft_printd.c ft_printi.c ft_printu.c ft_printx.c ft_print88.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -ggdb3

CC = cc

AR = ar rcs

#regles
all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
