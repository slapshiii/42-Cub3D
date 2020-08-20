/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_sprite_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 02:02:48 by phnguyen          #+#    #+#             */
/*   Updated: 2020/08/20 03:29:42 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/cub3d_bonus.h"
#include "../include_bonus/struct_bonus.h"
#include <math.h>

void	cast_sprite(t_game *g)
{
	int		x;
	double	inv_det;

	x = 0;
	while (x < g->p->num_sprite)
	{
		g->s = (t_coord){g->p->sprite[x].pos.x - g->player.x,
			g->p->sprite[x].pos.y - g->player.y};
		inv_det = 1.0 / (g->plane.x * g->player_dir.y
			- g->player_dir.x * g->plane.y);
		g->trans = (t_coord){inv_det * (g->player_dir.y * g->s.x -
			g->player_dir.x * g->s.y),
			inv_det * (-(g->plane.y) * g->s.x + g->plane.x * g->s.y)};
		g->sprite_screen = (int)((g->p->res_w / 2)
			* (1 + g->trans.x / g->trans.y));
		calc_hw_sprite(g, x);
		x++;
	}
}

void	calc_hw_sprite(t_game *g, int x)
{
	t_coord	draw_y;
	t_coord	draw_x;

	g->movscreen = g->pitch + (g->posz / g->trans.y);
	g->sprite_h = abs((int)(g->p->res_h / g->trans.y));
	draw_y.x = -(g->sprite_h) / 2 + g->p->res_h / 2 + g->movscreen;
	draw_y.x = (draw_y.x < 0) ? 0 : draw_y.x;
	draw_y.y = g->sprite_h / 2 + g->p->res_h / 2 + g->movscreen;
	if (draw_y.y >= g->p->res_h)
		draw_y.y = g->p->res_h - 1;
	g->sprite_w = abs((int)(g->p->res_h / g->trans.y));
	draw_x.x = -(g->sprite_h) / 2 + g->sprite_screen;
	draw_x.x = (draw_x.x < 0) ? 0 : draw_x.x;
	draw_x.y = g->sprite_w / 2 + g->sprite_screen;
	if (draw_x.y >= g->p->res_w)
		draw_x.y = g->p->res_w - 1;
	draw_sprite(g, draw_y, draw_x, x);
}

void	check_hp(t_game *g, int color, int x)
{
	color = (g->p->sprite[x].hp == 2) ? (color >> 1) & 0x7F7F7F : color;
	color = (g->p->sprite[x].hp == 1) ? (color >> 1) & 0x272727 : color;
	g->win_img.data[(g->p->res_w) * g->y + g->x] = color;
}

void	draw_sprite(t_game *g, t_coord draw_y, t_coord draw_x, int x)
{
	int color;
	int d;

	g->x = (int)draw_x.x;
	g->y = draw_y.x;
	while (g->x < (int)draw_x.y)
	{
		g->y = draw_y.x;
		g->tex_x = (int)(256 * (g->x - (-(g->sprite_w) / 2 + g->sprite_screen))
			* g->texture[4].width / g->sprite_w) / 256;
		if (g->trans.y > 0 && g->x > 0
			&& g->x < g->p->res_w && g->trans.y < g->zbuffer[g->x])
			while (g->y < draw_y.y)
			{
				d = (g->y - g->movscreen) * 256
					- g->p->res_h * 128 + g->sprite_h * 128;
				g->tex_y = ((d * g->texture[4].height) / g->sprite_h) / 256;
				color = (int)g->texture[4].data[(g->texture[4].width)
					* g->tex_y + g->tex_x];
				if ((color & 0x00FFFFFF) != 0)
					check_hp(g, color, x);
				g->y++;
			}
		g->x++;
	}
}