/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 02:02:48 by phnguyen          #+#    #+#             */
/*   Updated: 2020/08/05 02:34:43 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "struct.h"
#include <math.h>

void	cast_sprite(t_game *g)
{
	int		x;
	double	inv_det;

	x = 0;
	while (x < g->p->num_sprite)
	{
		g->s = (t_coord){g->p->sprite[x].pos.x - g->player.x + 0.5,
			g->p->sprite[x].pos.y - g->player.y + 0.5};
		inv_det = 1.0 / (g->plane.x * g->player_dir.y
			- g->player_dir.x * g->plane.y);
		g->trans = (t_coord){inv_det * (g->player_dir.y * g->s.x -
			g->player_dir.x * g->s.y),
			inv_det * (-(g->plane.y) * g->s.x + g->plane.x * g->s.y)};
		g->sprite_screen = (int)((g->p->res_w / 2)
			* (1 + g->trans.x / g->trans.y));
		calc_hw_sprite(g, g->trans);
		x++;
	}
}

void	calc_hw_sprite(t_game *g, t_coord trans)
{
	t_coord	draw_y;
	t_coord	draw_x;

	g->sprite_h = abs((int)(g->p->res_h / trans.y));
	draw_y.x = -(g->sprite_h) / 2 + g->p->res_h / 2;
	draw_y.x = (draw_y.x < 0) ? 0 : draw_y.x;
	draw_y.y = g->sprite_h / 2 + g->p->res_h / 2;
	if (draw_y.y >= g->p->res_h)
		draw_y.y = g->p->res_h - 1;
	g->sprite_w = abs((int)(g->p->res_w / trans.y));
	draw_x.x = -(g->sprite_h) / 2 + g->sprite_screen;
	draw_x.x = (draw_x.x < 0) ? 0 : draw_x.x;
	draw_x.y = g->sprite_w / 2 + g->sprite_screen;
	if (draw_x.y >= g->p->res_w)
		draw_x.y = g->p->res_w - 1;
	draw_sprite(g, draw_y, draw_x);
}

void	draw_sprite(t_game *g, t_coord draw_y, t_coord draw_x)
{
	int color;
	int d;

	g->x = (int)draw_x.x;
	g->y = draw_y.x;
	while (g->x < (int)draw_x.y)
	{
		g->y = draw_y.x;
		g->tex_x = (int)(256 * (g->x - (-(g->sprite_w) / 2 + g->sprite_screen))
			* g->texture[0].width / g->sprite_w) / 256;
		if (g->trans.y > 0 && g->x > 0
			&& g->x < g->p->res_w && g->trans.y < g->zbuffer[g->x])
			while (g->y < draw_y.y)
			{
				d = (g->y) * 256 - g->p->res_h * 128 + g->sprite_h * 128;
				g->tex_y = ((d * g->texture[0].height) / g->sprite_h) / 256;
				color = (int)g->texture[0].data[(g->texture[0].width)
					* g->tex_y + g->tex_x];
				if ((color & 0x00FFFFFF) != 0)
					g->win_img.data[(g->p->res_w) * g->y + g->x] = color;
				g->y++;
			}
		g->x++;
	}
}
