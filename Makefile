# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/08 13:50:03 by phnguyen          #+#    #+#              #
#    Updated: 2020/08/26 23:16:37 by phnguyen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3D

UNAME := $(shell uname -s)

LIBFTDIR = libft/

GNLDIR = get_next_line/

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

SRCS_BONUS =	srcs_bonus/main_bonus.c\
				srcs_bonus/game_bonus.c\
				srcs_bonus/error_handler_bonus.c\
				srcs_bonus/parser_param_bonus.c\
				srcs_bonus/init_mlx_bonus.c\
				srcs_bonus/parser_file_bonus.c\
				srcs_bonus/checker_param_bonus.c\
				srcs_bonus/window_bonus.c\
				srcs_bonus/hook_bonus.c\
				srcs_bonus/move_bonus.c\
				srcs_bonus/check_move_bonus.c\
				srcs_bonus/move_alt_bonus.c\
				srcs_bonus/turn_bonus.c\
				srcs_bonus/raycasting_bonus.c\
				srcs_bonus/init_raycasting_bonus.c\
				srcs_bonus/raycasting_bis_bonus.c\
				srcs_bonus/init_sprite_bonus.c\
				srcs_bonus/cast_sprite_bonus.c\
				srcs_bonus/bitmap_bonus.c\
				srcs_bonus/hub_bonus.c\
				srcs_bonus/init_bonus.c\
				srcs_bonus/floorcast_bonus.c\
				srcs_bonus/animate_attack_bonus.c\
				srcs_bonus/move_sprite_bonus.c\

HEADER =	include/cub3d.h\
			include/hook.h\
			include/struct.h\
			include/parser_param.h\
			minilibx_a/*.h\

HEADER_BONUS =	include_bonus/cub3d_bonus.h\
				include_bonus/hook_bonus.h\
				include_bonus/struct_bonus.h\
				include_bonus/parser_param_bonus.h\
				include_bonus/hub_bonus.h\
				minilibx_a/*.h\

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)



#FLAGS = -Wall -Wextra -Werror -fsanitize=address
FLAGS = -Wall -Wextra -Werror

ifeq ($(UNAME),Darwin)
	MLXFLAG = -framework OpenGL -framework AppKit
	FLAGS += -D __APPLE__
	MLXDIR = minilibx_a/
	CC = gcc
else
	MLXFLAG = -lmlx -lXext -lX11 -lm
	MLXDIR = minilibx_b/
	CC = clang
endif

LIBS = 	$(LIBFTDIR)libft.a\
		$(GNLDIR)get_next_line.a\
		$(MLXDIR)libmlx.a		

all: $(NAME)

$(NAME): clean_bonus $(OBJS) $(LIBS) $(HEADER)
	@$(CC) -O3 $(FLAGS) -L. -o $(NAME) $(OBJS) $(LIBS) $(MLXFLAG)

bonus: clean_mandatory $(OBJS_BONUS) $(LIBS) $(HEADER_BONUS)
	@$(CC) -O3 $(FLAGS) -L. -o $(NAME) $(OBJS_BONUS) $(LIBS) $(MLXFLAG)


$(LIBS):
	@make -C $(LIBFTDIR)
	@make -C $(GNLDIR)
	@make -C $(MLXDIR)
	@cp $(MLXDIR)libmlx.a .

%.o:	%.c
	$(CC) -O3 $(FLAGS) -c $< -o $(<:.c=.o)

clean_bonus:
	@rm -rf $(OBJS_BONUS)
	@rm -f $(NAME)

clean_mandatory:
	@rm -rf $(OBJS)
	@rm -f $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(OBJS_BONUS)
	@make clean -C $(LIBFTDIR)
	@make clean -C $(GNLDIR)
	@make clean -C $(MLXDIR)
	@rm -rf libmlx.a


fclean: clean
	@rm -f $(NAME)

re: fclean all
	@make re -C $(LIBFTDIR)
	@make re -C $(GNLDIR)

norm:
	norminette include*/*.h
	norminette srcs*/*.c

.PHONY : all clean clean_mandatory clean_bonus fclean re bonus norm
