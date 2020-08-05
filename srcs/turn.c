/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 02:29:57 by phnguyen          #+#    #+#             */
/*   Updated: 2020/08/05 02:34:43 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../include/hook.h"
#include <math.h>

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
