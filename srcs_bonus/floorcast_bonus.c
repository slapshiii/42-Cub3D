/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floorcast_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 22:29:16 by phnguyen          #+#    #+#             */
/*   Updated: 2020/08/21 07:52:46 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/cub3d_bonus.h"
#include "../include_bonus/struct_bonus.h"
#include <math.h>
#include "../include_bonus/hook_bonus.h"

void	draw_floorcast(t_game *g, t_image tex)
{
	int tx;
	int	ty;
	int color;

	tx = (int)(tex.width * (g->floor.x - (int)(g->floor.x)))
		& (tex.width - 1);
	ty = (int)(tex.height * (g->floor.y - (int)(g->floor.y)))
		& (tex.height - 1);
	color = (int)tex.data[(tex.width * ty) + tx];
	g->win_img.data[g->p->res_w * g->y + g->x] = (color >> 1 & 8355711);
}

void	data_floorcast(t_game *g)
{
	g->is_floor = g->y > g->p->res_h / 2 + g->pitch;
	g->raydirz = (t_vect){g->player_dir.x - g->plane.x,
						g->player_dir.y - g->plane.y};
	g->raydiro = (t_vect){g->player_dir.x + g->plane.x,
						g->player_dir.y + g->plane.y};
	g->rowdist = ((g->is_floor) ?
		(0.5 * g->p->res_h + g->posz) : (0.5 * g->p->res_h - g->posz))
		/ ((g->is_floor) ? (g->y - g->p->res_h / 2 - g->pitch)
		: (g->p->res_h / 2 - g->y + g->pitch));
	g->floorstep.x = g->rowdist * (g->raydiro.x - g->raydirz.x) / g->p->res_w;
	g->floorstep.y = g->rowdist * (g->raydiro.y - g->raydirz.y) / g->p->res_w;
	g->floor.x = g->player.x + g->rowdist * g->raydirz.x;
	g->floor.y = g->player.y + g->rowdist * g->raydirz.y;
}

void	loop_floorcast(t_game *g)
{
	g->x = 0;
	while (g->x < g->p->res_w)
	{
		if (g->is_floor)
			draw_floorcast(g, g->texture_floor);
		else
			draw_floorcast(g, g->texture_ceil);
		g->floor.x += g->floorstep.x;
		g->floor.y += g->floorstep.y;
		g->x++;
	}
}

void	init_floorcast(t_game *g)
{
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
