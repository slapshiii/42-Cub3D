/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycasting_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 04:29:38 by phnguyen          #+#    #+#             */
/*   Updated: 2020/08/20 03:30:41 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/cub3d_bonus.h"
#include "../include_bonus/struct_bonus.h"
#include <math.h>
#include "../include_bonus/hook_bonus.h"

void	init_raycasting(t_game *g)
{
	double camera;

	camera = (2 * g->x / (double)(g->p->res_w)) - 1;
	g->ray_dir.x = g->player_dir.x + g->plane.x * camera;
	g->ray_dir.y = g->player_dir.y + g->plane.y * camera;
	g->mapx = (int)(g->player.x);
	g->mapy = (int)(g->player.y);
	if (g->ray_dir.y == 0)
		g->deltdist.x = 0;
	else if (g->ray_dir.x == 0)
		g->deltdist.x = 1;
	else
		g->deltdist.x = fabs(1 / g->ray_dir.x);
	if (g->ray_dir.x == 0)
		g->deltdist.y = 0;
	else if (g->ray_dir.y == 0)
		g->deltdist.y = 1;
	else
		g->deltdist.y = fabs(1 / g->ray_dir.y);
	init_sidedist(g);
}

void	init_sidedist(t_game *g)
{
	if (g->ray_dir.x < 0)
	{
		g->step.x = -1;
		g->sidedist.x = (g->player.x - g->mapx) * g->deltdist.x;
	}
	else
	{
		g->step.x = 1;
		g->sidedist.x = (g->mapx + 1.0 - g->player.x) * g->deltdist.x;
	}
	if (g->ray_dir.y < 0)
	{
		g->step.y = -1;
		g->sidedist.y = (g->player.y - g->mapy) * g->deltdist.y;
	}
	else
	{
		g->step.y = 1;
		g->sidedist.y = (g->mapy + 1.0 - g->player.y) * g->deltdist.y;
	}
	calc_dda(g);
}

void	calc_dda(t_game *g)
{
	int hit;

	hit = 0;
	while (hit == 0)
	{
		if (g->sidedist.x < g->sidedist.y)
		{
			g->sidedist.x += g->deltdist.x;
			g->mapx += g->step.x;
			g->side = 0;
		}
		else
		{
			g->sidedist.y += g->deltdist.y;
			g->mapy += g->step.y;
			g->side = 1;
		}
		hit = (g->p->map[g->mapy][g->mapx] == '1') ? 1 : 0;
	}
	calc_startend(g);
}

void	calc_startend(t_game *g)
{
	if (g->side == 0)
		g->perp = (g->mapx - g->player.x + (1 - g->step.x) / 2) / g->ray_dir.x;
	else
		g->perp = (g->mapy - g->player.y + (1 - g->step.y) / 2) / g->ray_dir.y;
	g->lineheight = (int)(g->p->res_h / g->perp);
	g->dstart = -g->lineheight / 2 + g->p->res_h / 2
		+ g->pitch + (g->posz / g->perp);
	g->dstart = (g->dstart < 0) ? 0 : g->dstart;
	g->dend = g->lineheight / 2 + g->p->res_h / 2
		+ g->pitch + (g->posz / g->perp);
	g->dend = (g->dend >= g->p->res_h) ? g->p->res_h - 1 : g->dend;
	calc_texture(g, g->dstart, g->dend);
}