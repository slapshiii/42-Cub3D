/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 14:39:15 by phnguyen          #+#    #+#             */
/*   Updated: 2020/07/07 05:17:14 by phnguyen         ###   ########.fr       */
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

# define SPEED_WALK 0.1
# define SPEED_TURN 0.1

# define MIN_SIZE_W 200
# define MIN_SIZE_H 200

void    clear_path(param_t *p);
void    clear_game(game_t *g);
void    clear_tab(char **tab, int max);
void    error_exit(char *msg, game_t *g);
void    ft_game(game_t *g, int screen, char *path);

int     make_window(game_t *g);
void    player_set_dir(game_t *g);

void    init_raycast(game_t *g);
coord_t    init_sidedist(game_t *g);
void    init_sidedist_bis(game_t *g);
coord_t hit_texture(game_t *g);

#endif
