# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/08 13:50:03 by phnguyen          #+#    #+#              #
#    Updated: 2020/07/28 01:51:27 by phnguyen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3D

LIBFTDIR = libft/

GNLDIR = get_next_line/

MLXDIR = minilibx_a/

HEADERDIR = include/

SRCS = 	srcs/main.c\
		srcs/game.c\
		srcs/error_handler.c\
		srcs/parser_param.c\
		srcs/init_mlx.c\
		srcs/parser_file.c\
		srcs/checker_param.c\
		srcs/window.c\
		srcs/hook.c\
		srcs/move.c\
		srcs/turn.c\
		srcs/raycasting.c\
		srcs/init_raycasting.c\
		srcs/raycasting_bis.c\
		srcs/init_sprite.c\
		srcs/cast_sprite.c\
		srcs/bitmap.c\

HEADER =	include/cub3d.h\
			include/hook.h\
			include/struct.h\
			include/parser_param.h\
			minilibx_a/*.h\

OBJS = $(SRCS:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror

#MLXFLAG = -lmlx -lXext -lX11
MLXFLAG = -framework OpenGL -framework AppKit
#MLXFLAG = -I/usr/X11/include -lmlx -framework OpenGL -framework AppKit

#MINILIBX = -L minilibx $(MLXFLAG)

LIBS = 	$(LIBFTDIR)libft.a\
		$(GNLDIR)get_next_line.a\
		$(MLXDIR)libmlx.a
		#$(MLXDIR)libmlx.dylib
		


all: $(NAME)

$(NAME): $(OBJS) $(LIBS) $(HEADER)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBS) $(MLXFLAG)

$(LIBS):
	make -C $(LIBFTDIR)
	make -C $(GNLDIR)
	make -C $(MLXDIR)
	#cp $(MLXDIR)libmlx.dylib .
	cp $(MLXDIR)libmlx.a .

%.o:	%.c
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

clean:
	rm -rf $(OBJS)
	make clean -C $(LIBFTDIR)
	make clean -C $(GNLDIR)
	make clean -C $(MLXDIR)
	#rm -rf libmlx.dylib
	rm -rf libmlx.a


fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFTDIR)
	make fclean -C $(GNLDIR)

re: fclean all
	make re -C $(LIBFTDIR)
	make re -C $(GNLDIR)

.PHONY : all clean fclean re