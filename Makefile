# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/08 13:50:03 by phnguyen          #+#    #+#              #
#    Updated: 2020/04/08 14:20:06 by phnguyen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3D

LIBS = libft/libft.a

LIBFTDIR = libft/

HEADER = include/

SRCS = srcs/main.c srcs/parser_param.c srcs/window.c

OBJS = $(SRC:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror

MINILIBX = -L minilibx -lmlx -framework OpenGL -framework AppKit

HEADER = srcs/cub3d.h

all: $(NAME)

$(LIBS):
	make -C $(LIBFTDIR)

$(NAME): $(SRC)
	$(CC) $(FLAGS) $(MINILIBX) -L. -lft $(SRCS) -o $(NAME)

clean:
	rm -rf $(OBJS)
	make clean -C $(LIBFTDIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFTDIR)

re: fclean all
	make re -C $(LIBFTDIR)

.PHONY : all clean fclean re