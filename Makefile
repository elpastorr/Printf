# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elpastor <elpastor@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 14:52:12 by elpastor          #+#    #+#              #
#    Updated: 2022/01/05 14:28:31 by elpastor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c \
put_nbrs.c \
put_strs.c

OBJS = ${SRCS:.c=.o}

FLAGS = -Wall -Wextra -Werror

all:	${NAME}

${NAME}: ${OBJS}
		ar rc ${NAME} ${OBJS}
		ranlib ${NAME}
clean:
		rm -f ${OBJS} ${BONUS_OBJS}

fclean:	clean
		rm -f ${NAME}

re:		fclean all

.PHONY: all clean fclean re
