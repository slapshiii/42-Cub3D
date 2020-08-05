/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 03:21:46 by phnguyen          #+#    #+#             */
/*   Updated: 2020/08/05 04:55:14 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/cub3d.h"
#include "../include_bonus/hub.h"
#include <math.h>

t_vect	pos_to_dir(t_game *g, int i)
{
	t_vect	res;
	double	norm;
	t_coord	vect;

	vect = (t_coord){g->player.x - g->p->sprite[i].pos.x,
		g->player.y - g->p->sprite[i].pos.y};
	norm = sqrt((vect.x * vect.x) + (vect.y * vect.y));
	res = (t_vect){vect.x / norm, vect.y / norm};
	return (res);
}

void	edit_map(t_game *g, t_coord pos, t_sprite sprite)
{
	int	x;
	int	y;
	int	sx;
	int	sy;

	x = (int)pos.x;
	y = (int)pos.y;
	sx = (int)sprite.pos.x;
	sy = (int)sprite.pos.y;
	if (sx != x || sy != y)
	{
		g->p->map[y][x] = '0';
		g->p->map[sy][sx] = '2';
		draw_map(g);
	}
}

void	move_sprite(t_game *g)
{
	int		i;
	t_vect	dir;
	t_coord	old_pos;

	i = -1;
	g->bonus->hit = 0;
	while (++i < g->p->num_sprite)
	{
		dir = pos_to_dir(g, i);
		old_pos = (t_coord){g->p->sprite[i].pos.x, g->p->sprite[i].pos.y};
		g->p->sprite[i].pos.x = dir.x * SPEED_SPRITE + g->p->sprite[i].pos.x;
		g->p->sprite[i].pos.y = dir.y * SPEED_SPRITE + g->p->sprite[i].pos.y;
		g->bonus->hit = (fabs(g->player.x - g->p->sprite[i].pos.x) < 0.5
			&& fabs(g->player.y - g->p->sprite[i].pos.y) < 0.5);
		edit_map(g, old_pos, g->p->sprite[i]);
	}
	if (g->bonus->hit && g->bonus->invincible == 0)
	{
		g->bonus->invincible = 10;
		if(--g->hp == 0)
			g->bonus->status = 2;
	}
}