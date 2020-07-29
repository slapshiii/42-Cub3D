/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 02:25:05 by phnguyen          #+#    #+#             */
/*   Updated: 2020/07/30 00:24:48 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/cub3d.h"
#include "../include_bonus/hook.h"
#include <math.h>

void	set_speed(game_t *g)
{
	if (g->key_shift && !g->key_x)
		g->speed = SPEED_RUN;
	else if (g->key_x)
	{
		g->speed = SPEED_CROUCH;
		g->posz = -(g->p->res_h / 5);
	}
	else
		g->speed = SPEED_WALK;
}

void	move_up(game_t *g)
{	
	if (g->p->map[(int)(g->player.y)]
		[(int)(g->player.x + (g->player_dir.x * g->speed))] != '1')
		g->player = (coord_t){g->player.x
			+ (g->player_dir.x * g->speed), g->player.y};
	if (g->p->map[(int)(g->player.y + (g->player_dir.y * g->speed))]
		[(int)(g->player.x)] != '1')
		g->player = (coord_t){g->player.x, g->player.y
			+ (g->player_dir.y * g->speed)};
}

void	move_down(game_t *g)
{
	if (g->p->map[(int)(g->player.y)]
		[(int)(g->player.x - (g->player_dir.x * g->speed))] != '1')
		g->player = (coord_t){g->player.x
			- (g->player_dir.x * g->speed), g->player.y};
	if (g->p->map[(int)(g->player.y - (g->player_dir.y * g->speed))]
		[(int)(g->player.x)] != '1')
		g->player = (coord_t){g->player.x, g->player.y
			- (g->player_dir.y * g->speed)};
}

void	move_left(game_t *g)
{
	if (g->p->map[(int)(g->player.y)]
		[(int)(g->player.x + (g->player_dir.y * g->speed))] != '1')
		g->player = (coord_t){g->player.x
			+ (g->player_dir.y * g->speed), g->player.y};
	if (g->p->map[(int)(g->player.y - (g->player_dir.x * g->speed))]
		[(int)(g->player.x)] != '1')
		g->player = (coord_t){g->player.x, g->player.y
			- (g->player_dir.x * g->speed)};
}

void	move_right(game_t *g)
{
	if (g->p->map[(int)(g->player.y)]
		[(int)(g->player.x - (g->player_dir.y * g->speed))] != '1')
		g->player = (coord_t){g->player.x
			- (g->player_dir.y * g->speed), g->player.y};
	if (g->p->map[(int)(g->player.y + (g->player_dir.x * g->speed))]
		[(int)(g->player.x)] != '1')
		g->player = (coord_t){g->player.x, g->player.y
			+ (g->player_dir.x * g->speed)};
}
