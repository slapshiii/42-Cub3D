/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 02:25:05 by phnguyen          #+#    #+#             */
/*   Updated: 2020/07/30 06:38:36 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/cub3d.h"
#include "../include_bonus/hook.h"
#include <math.h>

void	dash(game_t *g)
{
	int	i;

	i = 0;
	while (i < 20)
	{
		move_up(g);
		i++;
	}
}

void	move_up(game_t *g)
{
	if (g->p->map[(int)(g->player.y)]
		[(int)(g->player.x + (g->player_dir.x * g->speed))] != '1'
		&& g->p->map[(int)(g->player.y)]
		[(int)(g->player.x + (g->player_dir.x * g->speed))] != '2')
		g->player = (coord_t){g->player.x
			+ (g->player_dir.x * g->speed), g->player.y};
	if (g->p->map[(int)(g->player.y + (g->player_dir.y * g->speed))]
		[(int)(g->player.x)] != '1'
		&& g->p->map[(int)(g->player.y + (g->player_dir.y * g->speed))]
		[(int)(g->player.x)] != '2')
		g->player = (coord_t){g->player.x, g->player.y
			+ (g->player_dir.y * g->speed)};
}

void	move_down(game_t *g)
{
	if (g->p->map[(int)(g->player.y)]
		[(int)(g->player.x - (g->player_dir.x * g->speed))] != '1'
		&& g->p->map[(int)(g->player.y)]
		[(int)(g->player.x - (g->player_dir.x * g->speed))] != '2')
		g->player = (coord_t){g->player.x
			- (g->player_dir.x * g->speed), g->player.y};
	if (g->p->map[(int)(g->player.y - (g->player_dir.y * g->speed))]
		[(int)(g->player.x)] != '1'
		&& g->p->map[(int)(g->player.y - (g->player_dir.y * g->speed))]
		[(int)(g->player.x)] != '2')
		g->player = (coord_t){g->player.x, g->player.y
			- (g->player_dir.y * g->speed)};
}

void	move_left(game_t *g)
{
	if (g->p->map[(int)(g->player.y)]
		[(int)(g->player.x + (g->player_dir.y * g->speed))] != '1'
		&& g->p->map[(int)(g->player.y)]
		[(int)(g->player.x + (g->player_dir.y * g->speed))] != '2')
		g->player = (coord_t){g->player.x
			+ (g->player_dir.y * g->speed), g->player.y};
	if (g->p->map[(int)(g->player.y - (g->player_dir.x * g->speed))]
		[(int)(g->player.x)] != '1'
		&& g->p->map[(int)(g->player.y - (g->player_dir.x * g->speed))]
		[(int)(g->player.x)] != '2')
		g->player = (coord_t){g->player.x, g->player.y
			- (g->player_dir.x * g->speed)};
}

void	move_right(game_t *g)
{
	if (g->p->map[(int)(g->player.y)]
		[(int)(g->player.x - (g->player_dir.y * g->speed))] != '1'
		&& g->p->map[(int)(g->player.y)]
		[(int)(g->player.x - (g->player_dir.y * g->speed))] != '2')
		g->player = (coord_t){g->player.x
			- (g->player_dir.y * g->speed), g->player.y};
	if (g->p->map[(int)(g->player.y + (g->player_dir.x * g->speed))]
		[(int)(g->player.x)] != '1'
		&& g->p->map[(int)(g->player.y + (g->player_dir.x * g->speed))]
		[(int)(g->player.x)] != '2')
		g->player = (coord_t){g->player.x, g->player.y
			+ (g->player_dir.x * g->speed)};
}
