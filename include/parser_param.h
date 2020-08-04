/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_param.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 14:50:41 by phnguyen          #+#    #+#             */
/*   Updated: 2020/08/04 04:29:18 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_PARAM_H
# define PARSER_PARAM_H

# include "libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "cub3d.h"
# include "struct.h"

int check_file(char **tab, int index, game_t *g);
int parser_param(game_t *g, char *path);
int	check_close_map(char **map, int x, int y);
int	check_spawn(char **map, int x, int y, param_t *p);

int handle_color(char *rgb);
int check_map_valid(param_t *p);
int check_param(char **split, param_t *p);
int check_map(char **tab, param_t *p, int offset, int max);
int check_config(param_t *p);

int	mlx_screen_size(void *mlx_ptr, int *width, int *height);
int init_mlx(game_t *g);
int parser_file(game_t *g);
int get_data_file(game_t *g);
#endif
