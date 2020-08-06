# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/08 13:50:03 by phnguyen          #+#    #+#              #
#    Updated: 2020/08/07 01:12:52 by phnguyen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3D

LIBFTDIR = libft/

GNLDIR = get_next_line/

MLXDIR = minilibx_a/

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

SRCS_BONUS =	srcs_bonus/main.c\
				srcs_bonus/game.c\
				srcs_bonus/error_handler.c\
				srcs_bonus/parser_param.c\
				srcs_bonus/init_mlx.c\
				srcs_bonus/parser_file.c\
				srcs_bonus/checker_param.c\
				srcs_bonus/window.c\
				srcs_bonus/hook.c\
				srcs_bonus/move.c\
				srcs_bonus/move_alt.c\
				srcs_bonus/turn.c\
				srcs_bonus/raycasting.c\
				srcs_bonus/init_raycasting.c\
				srcs_bonus/raycasting_bis.c\
				srcs_bonus/init_sprite.c\
				srcs_bonus/cast_sprite.c\
				srcs_bonus/bitmap.c\
				srcs_bonus/hub.c\
				srcs_bonus/floorcast.c\
				srcs_bonus/animate_attack.c\
				srcs_bonus/move_sprite.c\

HEADER =	include/cub3d.h\
			include/hook.h\
			include/struct.h\
			include/parser_param.h\
			minilibx_a/*.h\

HEADER_BONUS =	include_bonus/cub3d.h\
				include_bonus/hook.h\
				include_bonus/struct.h\
				include_bonus/parser_param.h\
				include_bonus/hub.h\
				minilibx_a/*.h\

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

CC = gcc

#FLAGS = -Wall -Wextra -Werror -fsanitize=address
FLAGS = -Wall -Wextra -Werror


#MLXFLAG = -lmlx -lXext -lX11
MLXFLAG = -framework OpenGL -framework AppKit
#MLXFLAG = -I/usr/X11/include -lmlx -framework OpenGL -framework AppKit

#MINILIBX = -L minilibx $(MLXFLAG)

LIBS = 	$(LIBFTDIR)libft.a\
		$(GNLDIR)get_next_line.a\
		$(MLXDIR)libmlx.a		

all: $(NAME)

$(NAME): $(OBJS) $(LIBS) $(HEADER)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBS) $(MLXFLAG)

bonus: $(OBJS_BONUS) $(LIBS) $(HEADER_BONUS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS_BONUS) $(LIBS) $(MLXFLAG)


$(LIBS):
	make -C $(LIBFTDIR)
	make -C $(GNLDIR)
	make -C $(MLXDIR)
	cp $(MLXDIR)libmlx.a .

%.o:	%.c
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

clean:
	rm -rf $(OBJS)
	rm -rf $(OBJS_BONUS)
	make clean -C $(LIBFTDIR)
	make clean -C $(GNLDIR)
	make clean -C $(MLXDIR)
	rm -rf libmlx.a


fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFTDIR)
	make fclean -C $(GNLDIR)

re: fclean all
	make re -C $(LIBFTDIR)
	make re -C $(GNLDIR)

.PHONY : all clean fclean re bonus