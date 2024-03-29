/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_param.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 14:50:41 by phnguyen          #+#    #+#             */
/*   Updated: 2020/08/26 22:37:22 by phnguyen         ###   ########.fr       */
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

int		check_file(char **tab, int index, t_game *g);
int		parser_param(t_game *g, char *path);
int		check_close_map(char **map, int x, int y);
int		check_spawn(char **map, int x, int y, t_param *p);

int		handle_color(char *rgb);
int		check_map_valid(t_param *p);
int		check_param(char **split, t_param *p);
int		check_map(char **tab, t_param *p, int offset, int max);
int		check_config(t_param *p);

int		init_mlx(t_game *g);
int		parser_file(t_game *g);
void	init_data(t_game *g);
int		load_image(t_game *g, t_image *image, char *path);
int		parser_file(t_game *g);
void	destroy_image(t_game *g, t_image *image);
void	clear_image(t_game *g);
#endif
