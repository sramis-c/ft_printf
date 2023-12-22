# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sramis-c <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/16 11:09:56 by sramis-c          #+#    #+#              #
#    Updated: 2020/01/25 17:43:13 by sramis-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_printf.c ft_flags.c ft_conversions.c ft_convint.c ft_convuns.c ft_convhex.c ft_convptr.c

UTLS	= libft/ft_calloc.c libft/ft_strdup.c libft/ft_putchar_fd.c libft/ft_strlen.c libft/ft_strjoin.c libft/ft_bzero.c libft/ft_itoa.c libft/ft_litoa.c libft/ft_llitoa.c libft/ft_utoa.c libft/ft_lutoa.c libft/ft_llutoa.c libft/ft_hextoa.c libft/ft_lhextoa.c libft/ft_llhextoa.c

OBJS	= ${SRCS:.c=.o}

OBJ2	= ${UTLS:.c=.o}

CC		= gcc -Wall -Wextra -Werror #-g3 -fsanitize=address

NAME	= libftprintf.a

${NAME}:	${OBJS} ${OBJ2} ft_printf.h
			ar rc ${NAME} ${OBJS} ${OBJ2}

all:		${NAME}

bonus:		${NAME}

clean:
			rm -f ${OBJS} libft/ft_calloc.o libft/ft_strdup.o libft/ft_putchar_fd.o libft/ft_strlen.o libft/ft_strjoin.o libft/ft_bzero.o libft/ft_itoa.o libft/ft_litoa.o libft/ft_llitoa.o libft/ft_utoa.o libft/ft_lutoa.o libft/ft_llutoa.o libft/ft_hextoa.o libft/ft_lhextoa.o libft/ft_llhextoa.o


fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all bonus clean fclean re
