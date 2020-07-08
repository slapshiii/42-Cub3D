/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 02:33:07 by phnguyen          #+#    #+#             */
/*   Updated: 2020/07/08 03:10:02 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "struct.h"
#include <math.h>

coord_t	hit_texture(game_t *g)
{
	coord_t res;

	get_side(g);
	g->texture_side = get_texture(g);
	g->wallx -= floor(g->wallx);
	g->tex_x = (int)(g->wallx * (g->texture_side.width));
	if (g->side == 0 && g->ray_dir.x > 0)
		g->tex_x = (g->texture_side.width - g->tex_x - 1);
	if (g->side == 1 && g->ray_dir.y < 0)
		g->tex_x = (g->texture_side.width - g->tex_x - 1);
	g->col = (int)(g->p->res_h / (g->perpwalldist));
	res.x = (-g->col) / 2 + g->p->res_h / 2;
	if (res.x < 0)
		res.x = 0;
	res.y = g->col / 2 + g->p->res_h / 2;
	if (res.y >= g->p->res_h)
		res.y = g->p->res_h - 1;
	return (res);
}

coord_t	calc_texture(game_t *g, coord_t res)
{
	int	color;

	g->y = -1;
	while (++g->y < (int)res.x)
		g->win_img.data[(g->p->res_w + 1) * g->y + g->x] = g->p->color_ceiling;
	g->step = 1.0 * g->texture_side.height / g->col;
	g->tex_pos = (res.x - g->p->res_h / 2 + g->col / 2) * g->step;
	while (g->y < res.y)
	{
		g->tex_y = (int)g->tex_pos & (g->texture_side.height - 1);
		g->tex_pos += g->step;
		color = (int)g->texture_side.data
			[g->texture_side.width * g->tex_y + g->tex_x];
		color = (g->side == 0) ? (color >> 1) & 0x7F7F7F : color;
		g->win_img.data[(g->p->res_w + 1) * g->y + g->x] = color;
		g->y++;
	}
	while (g->y < g->p->res_h)
	{
		g->win_img.data[(g->p->res_w + 1) * g->y + g->x] = g->p->color_floor;
		g->y++;
	}
	return (res);
}

image_t	get_texture(game_t *g)
{
	if (g->side == 1 && g->ray_dir.y < 0)
		return (g->texture[1]);
	else if (g->side == 1)
		return (g->texture[2]);
	else if (g->side == 0 && g->ray_dir.x > 0)
		return (g->texture[3]);
	else
		return (g->texture[4]);
}

void	get_side(game_t *g)
{
	if (g->side == 0)
	{
		g->perpwalldist = (g->map_x - g->player.x
			+ (1 - g->step_x) / 2) / g->ray_dir.x;
		g->wallx = g->player.y + g->perpwalldist * g->ray_dir.y;
	}
	else
	{
		g->perpwalldist = (g->map_y - g->player.y
			+ (1 - g->step_y) / 2) / g->ray_dir.y;
		g->wallx = g->player.x + g->perpwalldist * g->ray_dir.x;
	}
}
