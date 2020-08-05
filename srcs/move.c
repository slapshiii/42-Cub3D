/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 02:25:05 by phnguyen          #+#    #+#             */
/*   Updated: 2020/08/05 02:34:43 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../include/hook.h"
#include <math.h>

void	move_up(t_game *g)
{
	if (g->p->map[(int)(g->player.y)]
		[(int)(g->player.x + (g->player_dir.x * SPEED_WALK))] != '1')
		g->player = (t_coord){g->player.x
			+ (g->player_dir.x * SPEED_WALK), g->player.y};
	if (g->p->map[(int)(g->player.y + (g->player_dir.y * SPEED_WALK))]
		[(int)(g->player.x)] != '1')
		g->player = (t_coord){g->player.x, g->player.y
			+ (g->player_dir.y * SPEED_WALK)};
}

void	move_down(t_game *g)
{
	if (g->p->map[(int)(g->player.y)]
		[(int)(g->player.x - (g->player_dir.x * SPEED_WALK))] != '1')
		g->player = (t_coord){g->player.x
			- (g->player_dir.x * SPEED_WALK), g->player.y};
	if (g->p->map[(int)(g->player.y - (g->player_dir.y * SPEED_WALK))]
		[(int)(g->player.x)] != '1')
		g->player = (t_coord){g->player.x, g->player.y
			- (g->player_dir.y * SPEED_WALK)};
}

void	move_left(t_game *g)
{
	if (g->p->map[(int)(g->player.y)]
		[(int)(g->player.x + (g->player_dir.y * SPEED_WALK))] != '1')
		g->player = (t_coord){g->player.x
			+ (g->player_dir.y * SPEED_WALK), g->player.y};
	if (g->p->map[(int)(g->player.y - (g->player_dir.x * SPEED_WALK))]
		[(int)(g->player.x)] != '1')
		g->player = (t_coord){g->player.x, g->player.y
			- (g->player_dir.x * SPEED_WALK)};
}

void	move_right(t_game *g)
{
	if (g->p->map[(int)(g->player.y)]
		[(int)(g->player.x - (g->player_dir.y * SPEED_WALK))] != '1')
		g->player = (t_coord){g->player.x
			- (g->player_dir.y * SPEED_WALK), g->player.y};
	if (g->p->map[(int)(g->player.y + (g->player_dir.x * SPEED_WALK))]
		[(int)(g->player.x)] != '1')
		g->player = (t_coord){g->player.x, g->player.y
			+ (g->player_dir.x * SPEED_WALK)};
}
