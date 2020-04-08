# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/08 14:58:58 by phnguyen          #+#    #+#              #
#    Updated: 2020/04/08 15:00:02 by phnguyen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

SRCS = get_next_line.c get_next_line_utils.c

OBJS = ${SRCS:.c=.o}

CFLAGS = -Wall -Werror -Wextra

all: 		${NAME}

${NAME}:	${OBJS}
		ar rc ${NAME} ${OBJS}
		ranlib ${NAME}

%.o:		%.c
		gcc ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
		rm -rf ${OBJS}

fclean:		clean
		rm -rf ${NAME}

re:		fclean all

.PHONY:		all clean fclean re