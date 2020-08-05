/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 02:29:57 by phnguyen          #+#    #+#             */
/*   Updated: 2020/08/05 04:58:47 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/cub3d.h"
#include "../include_bonus/hook.h"
#include <math.h>

void	set_speed(t_game *g)
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
	if (g->posz > 0)
		g->posz -= 10;
	else if (g->posz < 0 && !g->key_x)
		g->posz = 0;
	if (g->bonus->invincible > 0)
		g->bonus->invincible--;
}

void	turn_left(t_game *g)
{
	t_vect	olddir;
	t_vect	oldplane;

	olddir = g->player_dir;
	oldplane = g->plane;
	g->player_dir.x = g->player_dir.x * cos(-SPEED_TURN)
		- g->player_dir.y * sin(-SPEED_TURN);
	g->player_dir.y = olddir.x * sin(-SPEED_TURN)
		+ g->player_dir.y * cos(-SPEED_TURN);
	g->plane.x = g->plane.x * cos(-SPEED_TURN) - g->plane.y * sin(-SPEED_TURN);
	g->plane.y = oldplane.x * sin(-SPEED_TURN) + g->plane.y * cos(-SPEED_TURN);
}

void	turn_right(t_game *g)
{
	t_vect	olddir;
	t_vect	oldplane;

	olddir = g->player_dir;
	oldplane = g->plane;
	g->player_dir.x = g->player_dir.x * cos(SPEED_TURN)
		- g->player_dir.y * sin(SPEED_TURN);
	g->player_dir.y = olddir.x * sin(SPEED_TURN)
		+ g->player_dir.y * cos(SPEED_TURN);
	g->plane.x = g->plane.x * cos(SPEED_TURN) - g->plane.y * sin(SPEED_TURN);
	g->plane.y = oldplane.x * sin(SPEED_TURN) + g->plane.y * cos(SPEED_TURN);
}

void	turn_down(t_game *g)
{
	g->pitch -= 150 * SPEED_TURN;
	if (g->pitch < -200)
		g->pitch = -200;
}

void	turn_up(t_game *g)
{
	g->pitch += 150 * SPEED_TURN;
	if (g->pitch > 200)
		g->pitch = 200;
}
