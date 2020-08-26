/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 14:34:56 by phnguyen          #+#    #+#             */
/*   Updated: 2020/08/26 22:39:32 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser_param.h"
#include "../get_next_line/get_next_line.h"
#include "../include/cub3d.h"

void	init_data(t_game *g)
{
	g->player.x = g->p->spawn_x + 0.5;
	g->player.y = g->p->spawn_y + 0.5;
	if (g->p->spawn_dir == 'N')
	{
		g->plane = (t_vect){0.66, 0.00};
		g->player_dir = (t_vect){0, -1};
	}
	if (g->p->spawn_dir == 'S')
	{
		g->plane = (t_vect){-0.66, 0.00};
		g->player_dir = (t_vect){0, 1};
	}
	if (g->p->spawn_dir == 'E')
	{
		g->plane = (t_vect){0.00, 0.66};
		g->player_dir = (t_vect){1, 0};
	}
	if (g->p->spawn_dir == 'W')
	{
		g->plane = (t_vect){0.00, -0.66};
		g->player_dir = (t_vect){-1, 0};
	}
}

int		load_image(t_game *g, t_image *image, char *path)
{
	if (!(image->img = mlx_xpm_file_to_image(g->mlx_ptr, path, &(image->width),
					&(image->height)))
	|| (!(image->data = (int*)mlx_get_data_addr(image->img,
					&image->bpp, &image->sizeline,
					&image->endian))))
		return (-1);
	return (0);
}

int		parser_file(t_game *g)
{
	if (load_image(g, &g->texture[0], g->p->path_sprite) == -1)
		error_exit("Couldn load sprite\n", g);
	if (load_image(g, &g->texture[1], g->p->path_no) == -1)
		error_exit("Couldn load sprite\n", g);
	if (load_image(g, &g->texture[2], g->p->path_so) == -1)
		error_exit("Couldn load sprite\n", g);
	if (load_image(g, &g->texture[3], g->p->path_ea) == -1)
		error_exit("Couldn load sprite\n", g);
	if (load_image(g, &g->texture[4], g->p->path_we) == -1)
		error_exit("Couldn load sprite\n", g);
	init_data(g);
	return (0);
}
