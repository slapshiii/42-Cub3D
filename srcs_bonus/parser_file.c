/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 14:34:56 by phnguyen          #+#    #+#             */
/*   Updated: 2020/07/28 04:45:12 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/parser_param.h"
#include "../get_next_line/get_next_line.h"
#include "../include_bonus/cub3d.h"

void	init_data(game_t *g)
{
	g->player.x = g->p->spawn_x + 0.5;
	g->player.y = g->p->spawn_y + 0.5;
	if (g->p->spawn_dir == 'N')
	{
		g->plane = (vect_t){0.66, 0.00};
		g->player_dir = (vect_t){0, -1};
	}
	if (g->p->spawn_dir == 'S')
	{
		g->plane = (vect_t){-0.66, 0.00};
		g->player_dir = (vect_t){0, 1};
	}
	if (g->p->spawn_dir == 'E')
	{
		g->plane = (vect_t){0.00, 0.66};
		g->player_dir = (vect_t){1, 0};
	}
	if (g->p->spawn_dir == 'W')
	{
		g->plane = (vect_t){0.00, -0.66};
		g->player_dir = (vect_t){-1, 0};
	}
}

int	parser_file(game_t *g)
{
	if (!(g->texture[0].img = mlx_xpm_file_to_image(g->mlx_ptr,
					g->p->path_sprite, &(g->texture[0].width),
					&(g->texture[0].height)))
			|| !(g->texture[1].img = mlx_xpm_file_to_image(g->mlx_ptr,
					g->p->path_no, &(g->texture[1].width),
					&(g->texture[1].height)))
			|| !(g->texture[2].img = mlx_xpm_file_to_image(g->mlx_ptr,
					g->p->path_so, &(g->texture[2].width),
					&(g->texture[2].height)))
			|| !(g->texture[3].img = mlx_xpm_file_to_image(g->mlx_ptr,
					g->p->path_ea, &(g->texture[3].width),
					&(g->texture[3].height)))
			|| !(g->texture[4].img = mlx_xpm_file_to_image(g->mlx_ptr,
					g->p->path_we, &(g->texture[4].width),
					&(g->texture[4].height))))
		return (-1);
	init_data(g);
	return (get_data_file(g));
}

int	get_data_file(game_t *g)
{
	if (!(g->texture[0].data = (int*)mlx_get_data_addr(g->texture[0].img,
					&g->texture[0].bpp, &g->texture[0].sizeline,
					&g->texture[0].endian))
			|| !(g->texture[1].data = (int*)mlx_get_data_addr(g->texture[1].img,
					&g->texture[1].bpp, &g->texture[1].sizeline,
					&g->texture[1].endian))
			|| !(g->texture[2].data = (int*)mlx_get_data_addr(g->texture[2].img,
					&g->texture[2].bpp, &g->texture[2].sizeline,
					&g->texture[2].endian))
			|| !(g->texture[3].data = (int*)mlx_get_data_addr(g->texture[3].img,
					&g->texture[3].bpp, &g->texture[3].sizeline,
					&g->texture[3].endian))
			|| !(g->texture[4].data = (int*)mlx_get_data_addr(g->texture[4].img,
					&g->texture[4].bpp, &g->texture[4].sizeline,
					&g->texture[4].endian)))
		return (-1);
	return (0);
}

