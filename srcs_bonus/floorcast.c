/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floorcast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 22:29:16 by phnguyen          #+#    #+#             */
/*   Updated: 2020/07/29 00:09:19 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/cub3d.h"
#include "../include_bonus/struct.h"
#include <math.h>
#include "../include_bonus/hook.h"

void	data_floorcast(game_t *g)
{
	g->raydirz = (vect_t){g->player_dir.x - g->plane.x,
						g->player_dir.y - g->plane.y};
	g->raydiro = (vect_t){g->player_dir.x + g->plane.x,
						g->player_dir.y + g->plane.y};
	g->rowdist = (0.5 * g->p->res_h) / (g->y - g->p->res_h / 2);
	g->floorstep.x = g->rowdist * (g->raydiro.x - g->raydirz.x) / g->p->res_w;
	g->floorstep.y = g->rowdist * (g->raydiro.y - g->raydirz.y) / g->p->res_w;
	g->floor.x = g->player.x + g->rowdist * g->raydirz.x;
	g->floor.y = g->player.y + g->rowdist * g->raydirz.y;
}

void	loop_floorcast(game_t *g)
{
	int tx;
	int	ty;
	int color;

	g->x = 0;
	while (g->x < g->p->res_w)
	{
		tx = (int)(g->texture_floor.width * (g->floor.x - (int)(g->floor.x)))
			& (g->texture_floor.width - 1);
		ty = (int)(g->texture_floor.height * (g->floor.y - (int)(g->floor.y)))
			& (g->texture_floor.height - 1);
		g->floor.x += g->floorstep.x;
		g->floor.y += g->floorstep.y;
		color = (int)g->texture_floor.data[g->texture_floor.width * ty + tx];
		color = (color >> 1) & 8355711;
		g->win_img.data[((g->p->res_w) * g->y) + g->x] = color;
		color = (int)g->texture_ceil.data[g->texture_ceil.width * ty + tx];
		color = (color >> 1) & 8355711;
		g->win_img.data[
			((g->p->res_w) * (g->p->res_h - g->y - 1)) + g->x] = color;
		g->x++;
	}
}

void	init_floorcast(game_t *g)
{
	g->texture_floor.img = mlx_xpm_file_to_image(g->mlx_ptr,
		"texture/floor.xpm", &g->texture_floor.width,
		&g->texture_floor.height);
	g->texture_floor.data = (int*)mlx_get_data_addr(g->texture_floor.img,
		&g->texture_floor.bpp, &g->texture_floor.sizeline,
		&g->texture_floor.endian);
	g->texture_ceil.img = mlx_xpm_file_to_image(g->mlx_ptr, "texture/west.xpm",
		&g->texture_ceil.width, &g->texture_ceil.height);
	g->texture_ceil.data = (int*)mlx_get_data_addr(g->texture_ceil.img,
		&g->texture_ceil.bpp, &g->texture_ceil.sizeline,
		&g->texture_ceil.endian);
	g->y = 0;
	while (g->y < g->p->res_h)
	{
		data_floorcast(g);
		loop_floorcast(g);
		g->y++;
	}
	g->y = 0;
	g->x = 0;
}
