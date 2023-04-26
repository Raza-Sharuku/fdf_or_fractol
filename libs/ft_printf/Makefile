# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 16:42:18 by sraza             #+#    #+#              #
#    Updated: 2023/03/19 12:35:25 by razasharuku      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRCS = ft_strlen_printf.c \
		ft_putchar_printf.c \
		ft_putstr_printf.c \
		ft_putunbr_printf.c \
		ft_putnbr_printf.c \
		ft_printf.c \
		ft_hexa.c \
		ft_pointer.c \
		ft_strptr_printf.c \
		ft_strchr_printf.c 

OBJS = ${SRCS:.c=.o}

all:	$(NAME)

$(NAME):	${OBJS}
		ar -r ${NAME} ${OBJS}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
	rm -f ${OBJS}
fclean: clean
	rm -f ${NAME}

re: fclean all
