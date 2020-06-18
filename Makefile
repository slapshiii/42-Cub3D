# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/08 13:50:03 by phnguyen          #+#    #+#              #
#    Updated: 2020/06/18 14:34:37 by phnguyen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3D

LIBFTDIR = libft/

GNLDIR = get_next_line/

MLXDIR = minilibx/

HEADER = include/

SRCS = 	srcs/main.c\
		srcs/game.c\
		srcs/error_handler.c\
		srcs/parser_param.c\
		srcs/parser_file.c\
		srcs/checker_param.c\
		srcs/window.c\

OBJS = $(SRC:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror

#MLXFLAG = -lmlx -lXext -lX11
MLXFLAG = -lmlx -framework OpenGL -framework AppKit

MINILIBX = -L minilibx $(MLXFLAG)

HEADER = include/

LIBS = 	$(LIBFTDIR)libft.a\
		$(GNLDIR)get_next_line.a\
		$(MLXDIR)libmlx.dylib


all: $(NAME)

$(NAME): $(SRCS) $(LIBS) $(HEADER)
	$(CC) $(FLAGS) -I$(HEADER) $(SRCS) $(LIBS) -o $(NAME)

$(LIBS):
	make -C $(LIBFTDIR)
	make -C $(GNLDIR)
	make -C $(MLXDIR)
	cp $(MLXDIR)libmlx.dylib .

clean:
	rm -rf $(OBJS)
	make clean -C $(LIBFTDIR)
	make clean -C $(GNLDIR)
	make clean -C $(MLXDIR)
	rm -rf libmlx.dylib

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFTDIR)
	make fclean -C $(GNLDIR)

re: fclean all
	make re -C $(LIBFTDIR)
	make re -C $(GNLDIR)

.PHONY : all clean fclean re