/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 02:25:05 by phnguyen          #+#    #+#             */
/*   Updated: 2020/08/07 04:37:43 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/cub3d.h"
#include "../include_bonus/hook.h"
#include <math.h>

void	dash(t_game *g)
{
	int	i;

	i = 0;
	while (i < 20)
	{
		move_up(g);
		i++;
	}
}

void	move_up(t_game *g)
{
	if (g->p->map[(int)(g->player.y)]
		[(int)(g->player.x + (g->player_dir.x * g->speed))] != '1'
		&& check_distx_sprite(g, g->player.x + (g->player_dir.x * g->speed)))
		g->player = (t_coord){g->player.x
			+ (g->player_dir.x * g->speed), g->player.y};
	if (g->p->map[(int)(g->player.y + (g->player_dir.y * g->speed))]
		[(int)(g->player.x)] != '1'
		&& check_disty_sprite(g, g->player.y + (g->player_dir.y * g->speed)))
		g->player = (t_coord){g->player.x, g->player.y
			+ (g->player_dir.y * g->speed)};
}

void	move_down(t_game *g)
{
	if (g->p->map[(int)(g->player.y)]
		[(int)(g->player.x - (g->player_dir.x * g->speed))] != '1'
		&& check_distx_sprite(g, g->player.x - (g->player_dir.x * g->speed)))
		g->player = (t_coord){g->player.x
			- (g->player_dir.x * g->speed), g->player.y};
	if (g->p->map[(int)(g->player.y - (g->player_dir.y * g->speed))]
		[(int)(g->player.x)] != '1'
		&& check_disty_sprite(g, g->player.y - (g->player_dir.y * g->speed)))
		g->player = (t_coord){g->player.x, g->player.y
			- (g->player_dir.y * g->speed)};
}

void	move_left(t_game *g)
{
	if (g->p->map[(int)(g->player.y)]
		[(int)(g->player.x + (g->player_dir.y * g->speed))] != '1'
		&& check_distx_sprite(g, g->player.x + (g->player_dir.y * g->speed)))
		g->player = (t_coord){g->player.x
			+ (g->player_dir.y * g->speed), g->player.y};
	if (g->p->map[(int)(g->player.y - (g->player_dir.x * g->speed))]
		[(int)(g->player.x)] != '1'
		&& check_disty_sprite(g, g->player.y - (g->player_dir.x * g->speed)))
		g->player = (t_coord){g->player.x, g->player.y
			- (g->player_dir.x * g->speed)};
}

void	move_right(t_game *g)
{
	if (g->p->map[(int)(g->player.y)]
		[(int)(g->player.x - (g->player_dir.y * g->speed))] != '1'
		&& check_distx_sprite(g, g->player.x - (g->player_dir.y * g->speed)))
		g->player = (t_coord){g->player.x
			- (g->player_dir.y * g->speed), g->player.y};
	if (g->p->map[(int)(g->player.y + (g->player_dir.x * g->speed))]
		[(int)(g->player.x)] != '1'
		&& check_disty_sprite(g, g->player.y + (g->player_dir.x * g->speed)))
		g->player = (t_coord){g->player.x, g->player.y
			+ (g->player_dir.x * g->speed)};
}
