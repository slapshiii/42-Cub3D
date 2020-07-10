/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 14:39:15 by phnguyen          #+#    #+#             */
/*   Updated: 2020/07/10 05:19:23 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "parser_param.h"
# include "libft.h"
# include "struct.h"
# include <mlx.h>
# include <stdio.h>
//# include <X11/X.h>

# define SPEED_WALK 0.05
# define SPEED_TURN 0.05

# define MIN_SIZE_W 200
# define MIN_SIZE_H 200

void    clear_path(param_t *p);
void    clear_game(game_t *g);
void    clear_tab(char **tab, int max);
void    error_exit(char *msg, game_t *g);
void    ft_game(game_t *g, int screen, char *path);

int     make_window(game_t *g);
void    player_set_dir(game_t *g);

void	init_raycast(game_t *g);
void	init_raycasting(game_t *g);
void	init_sidedist(game_t *g);
void	calc_dda(game_t *g);
void	calc_startend(game_t *g);

void	calc_texture(game_t *g, int start, int end);
void	get_texture(game_t *g);
void	get_wallx(game_t *g);

void    init_castsprite(game_t *g);
void    sort_sprites(game_t *g);
int     sprite_cmp(coord_t pos1, coord_t pos2, game_t *g);
void    swap_sprite(sprite_t *s1, sprite_t *s2);

void    cast_sprite(game_t *g);
void    calc_hw_sprite(game_t *g, coord_t trans);
void    draw_sprite(game_t *g, coord_t draw_y, coord_t draw_x);

void	save_bitmap(game_t *g);
int 	exists(const char *fname);
int		screenshot(game_t *g, int fd);
void	write_texture_bmp_file(game_t *g, int fd);

#endif
