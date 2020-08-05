/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 03:21:46 by phnguyen          #+#    #+#             */
/*   Updated: 2020/08/05 08:27:01 by phnguyen         ###   ########.fr       */
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

t_coord	update_pos(t_game *g, t_vect dir, t_sprite *sprite)
{
	t_coord	res;
	int		x;
	int		y;

	x = (int)(dir.x * SPEED_SPRITE + sprite->pos.x);
	y = (int)(dir.y * SPEED_SPRITE + sprite->pos.y);
	res = (t_coord){sprite->pos.x, sprite->pos.y};
	if (x != (int)g->player.x && g->p->map[y][x] != '1')
		sprite->pos.x = dir.x * SPEED_SPRITE + sprite->pos.x;
	if (y != (int)g->player.y && g->p->map[y][x] != '1')
		sprite->pos.y = dir.y * SPEED_SPRITE + sprite->pos.y;
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
	t_coord	old_pos;

	i = -1;
	g->bonus->hit = 0;
	while (++i < g->p->num_sprite)
	{
		dir = pos_to_dir(g, i);
		old_pos = update_pos(g, dir, &g->p->sprite[i]);
		g->bonus->hit = (fabs(g->player.x - g->p->sprite[i].pos.x) < 0.7
			&& fabs(g->player.y - g->p->sprite[i].pos.y) < 0.7);
	}
	if (g->bonus->hit && g->bonus->invincible == 0)
	{
		g->bonus->invincible = 10;
		if (--g->hp == 0)
			g->bonus->status = 2;
	}
}
