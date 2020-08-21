/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 14:39:15 by phnguyen          #+#    #+#             */
/*   Updated: 2020/08/22 01:00:57 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "parser_param_bonus.h"
# include "libft_bonus.h"
# include "struct_bonus.h"
# include "hub_bonus.h"
# ifdef __APPLE__
#  include "../minilibx_a/mlx.h"
# else
#  include "../minilibx_b/mlx.h"
# endif
# include <stdio.h>

# define MASK_KPRESSED 1
# define MASK_KRELEASE 2
# define MASK_MSMOTION 64

# define SPEED_WALK 0.063
# define SPEED_TURN 0.063
# define SPEED_RUN 0.091
# define SPEED_CROUCH 0.031
# define SPEED_SPRITE 0.063

# define HP_MAX 10

# define MIN_SIZE_W 200
# define MIN_SIZE_H 200

void	clear_path(t_param *p);
void	clear_game(t_game *g);
void	clear_tab(char **tab, int max);
void	error_exit(char *msg, t_game *g);
void	ft_game(t_game *g, int screen, char *path);

int		make_window(t_game *g);
int		check_status_game(t_game *g);
void	player_set_dir(t_game *g);

void	draw_floorcast(t_game *g, t_image tex);
void	init_floorcast(t_game *g);
void	data_floorcast(t_game *g);
void	loop_floorcast(t_game *g);

int		init_raycast(t_game *g);
void	init_raycasting(t_game *g);
void	init_sidedist(t_game *g);
void	calc_dda(t_game *g);
void	calc_startend(t_game *g);

void	calc_texture(t_game *g, int start, int end);
void	get_texture(t_game *g);
void	get_wallx(t_game *g);

void	init_castsprite(t_game *g);
void	sort_sprites(t_game *g);
int		sprite_cmp(t_coord pos1, t_coord pos2, t_game *g);
void	swap_sprite(t_sprite *s1, t_sprite *s2);

void	cast_sprite(t_game *g);
void	calc_hw_sprite(t_game *g, int x);
void	check_hp(t_game *g, int color, int x);
void	draw_sprite(t_game *g, t_coord draw_y, t_coord draw_x, int x);

void	save_bitmap(t_game *g);
int		exists(const char *fname);
int		screenshot(t_game *g, int fd);
void	write_texture_bmp_file(t_game *g, int fd);

#endif
