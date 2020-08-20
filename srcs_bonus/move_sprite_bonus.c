/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_sprite_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 03:21:46 by phnguyen          #+#    #+#             */
/*   Updated: 2020/08/20 03:31:10 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/cub3d_bonus.h"
#include "../include_bonus/hub_bonus.h"
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

t_coord	update_pos(t_game *g, t_vect dir, t_sprite *sprite)
{
	t_coord	res;
	t_coord	pos;
	int		x;
	int		y;

	pos = (t_coord){dir.x * SPEED_SPRITE + sprite->pos.x,
		dir.y * SPEED_SPRITE + sprite->pos.y};
	x = (int)(pos.x);
	y = (int)(pos.y);
	res = (t_coord){sprite->pos.x, sprite->pos.y};
	if (fabs(g->player.x - pos.x) > 0.5 && g->p->map[y][x] != '1')
		sprite->pos.x += dir.x * SPEED_SPRITE;
	if (fabs(g->player.y - pos.y) > 0.5 && g->p->map[y][x] != '1')
		sprite->pos.y += dir.y * SPEED_SPRITE;
	edit_map(g, res, *sprite);
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
	g->p->map[sy][sx] = '2';
	if (sx != x || sy != y)
		g->p->map[y][x] = '0';
}

void	move_sprite(t_game *g)
{
	int		i;
	t_vect	dir;

	i = -1;
	g->bonus->hit = 0;
	while (++i < g->p->num_sprite)
	{
		dir = pos_to_dir(g, i);
		update_pos(g, dir, &g->p->sprite[i]);
		g->bonus->hit = (fabs(g->player.x - g->p->sprite[i].pos.x) < 0.6
			&& fabs(g->player.y - g->p->sprite[i].pos.y) < 0.6);
	}
	if (g->bonus->hit && g->bonus->invincible == 0)
	{
		g->bonus->invincible = 10;
		if (--g->hp == 0)
			g->bonus->status = 2;
	}
}
