/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 02:29:57 by phnguyen          #+#    #+#             */
/*   Updated: 2020/07/30 06:38:13 by phnguyen         ###   ########.fr       */
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

void	turn_left(game_t *g)
{
	vect_t	olddir;
	vect_t	oldplane;

	olddir = g->player_dir;
	oldplane = g->plane;
	g->player_dir.x = g->player_dir.x * cos(-SPEED_TURN)
		- g->player_dir.y * sin(-SPEED_TURN);
	g->player_dir.y = olddir.x * sin(-SPEED_TURN)
		+ g->player_dir.y * cos(-SPEED_TURN);
	g->plane.x = g->plane.x * cos(-SPEED_TURN) - g->plane.y * sin(-SPEED_TURN);
	g->plane.y = oldplane.x * sin(-SPEED_TURN) + g->plane.y * cos(-SPEED_TURN);
}

void	turn_right(game_t *g)
{
	vect_t	olddir;
	vect_t	oldplane;

	olddir = g->player_dir;
	oldplane = g->plane;
	g->player_dir.x = g->player_dir.x * cos(SPEED_TURN)
		- g->player_dir.y * sin(SPEED_TURN);
	g->player_dir.y = olddir.x * sin(SPEED_TURN)
		+ g->player_dir.y * cos(SPEED_TURN);
	g->plane.x = g->plane.x * cos(SPEED_TURN) - g->plane.y * sin(SPEED_TURN);
	g->plane.y = oldplane.x * sin(SPEED_TURN) + g->plane.y * cos(SPEED_TURN);
}

void	turn_down(game_t *g)
{
	g->pitch -= 150 * SPEED_TURN;
	if (g->pitch < -200)
		g->pitch = -200;
}

void	turn_up(game_t *g)
{
	g->pitch += 150 * SPEED_TURN;
	if (g->pitch > 200)
		g->pitch = 200;
}
