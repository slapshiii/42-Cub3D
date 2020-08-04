/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 02:33:07 by phnguyen          #+#    #+#             */
/*   Updated: 2020/08/04 04:09:10 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../include/struct.h"
#include <math.h>

void	draw_ceiling_floor(game_t *g, int start, int end)
{
	while (g->y < start)
	{
		g->win_img.data[((g->p->res_w) * g->y) + g->x] = g->p->color_ceiling;
		g->y++;
	}
	g->y = end;
	while (g->y < g->p->res_h)
	{
		g->win_img.data[((g->p->res_w) * g->y) + g->x] = g->p->color_floor;
		g->y++;
	}
}

void	calc_texture(game_t *g, int start, int end)
{
	int		color;
	double	step;

	g->y = 0;
	get_texture(g);
	get_wallx(g);
	step = 1.0 * g->texture_side.height / g->lineheight;
	g->tex_pos = (start - g->p->res_h / 2 + g->lineheight / 2) * step;
	draw_ceiling_floor(g, start, end);
	g->y = start;
	while (g->y < end)
	{
		g->tex_y = (int)g->tex_pos & (g->texture_side.height - 1);
		g->tex_pos += step;
		color = (int)g->texture_side.data
			[g->texture_side.height * g->tex_y + g->tex_x];
		color = (g->side == 0) ? (color >> 1) & 0x7F7F7F : color;
		g->win_img.data[((g->p->res_w) * g->y) + g->x] = color;
		g->y++;
	}
}

void	get_texture(game_t *g)
{
	if (g->side == 1 && g->ray_dir.y < 0)
		g->texture_side = g->texture[1];
	else if (g->side == 1)
		g->texture_side = g->texture[2];
	else if (g->side == 0 && g->ray_dir.x > 0)
		g->texture_side = g->texture[3];
	else
		g->texture_side = g->texture[4];
}

void	get_wallx(game_t *g)
{
	if (g->side == 0)
		g->wallx = g->player.y + g->perp * g->ray_dir.y;
	else
		g->wallx = g->player.x + g->perp * g->ray_dir.x;
	g->wallx -= floor((g->wallx));
	g->tex_x = (int)(g->wallx * (double)(g->texture_side.width));
	if (g->side == 0 && g->ray_dir.x > 0)
		g->tex_x = g->texture_side.width - g->tex_x - 1;
	if (g->side == 1 && g->ray_dir.y < 0)
		g->tex_x = g->texture_side.width - g->tex_x - 1;
}
