/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 02:25:05 by phnguyen          #+#    #+#             */
/*   Updated: 2020/07/28 04:45:06 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/cub3d.h"
#include "../include_bonus/hook.h"
#include <math.h>

void	move_up(game_t *g)
{
	if (g->p->map[(int)(g->player.y)]
		[(int)(g->player.x + (g->player_dir.x * SPEED_WALK))] != '1')
		g->player = (coord_t){g->player.x
			+ (g->player_dir.x * SPEED_WALK), g->player.y};
	if (g->p->map[(int)(g->player.y + (g->player_dir.y * SPEED_WALK))]
		[(int)(g->player.x)] != '1')
		g->player = (coord_t){g->player.x, g->player.y
			+ (g->player_dir.y * SPEED_WALK)};
}

void	move_down(game_t *g)
{
	if (g->p->map[(int)(g->player.y)]
		[(int)(g->player.x - (g->player_dir.x * SPEED_WALK))] != '1')
		g->player = (coord_t){g->player.x
			- (g->player_dir.x * SPEED_WALK), g->player.y};
	if (g->p->map[(int)(g->player.y - (g->player_dir.y * SPEED_WALK))]
		[(int)(g->player.x)] != '1')
		g->player = (coord_t){g->player.x, g->player.y
			- (g->player_dir.y * SPEED_WALK)};
}

void	move_left(game_t *g)
{
	if (g->p->map[(int)(g->player.y)]
		[(int)(g->player.x + (g->player_dir.y * SPEED_WALK))] != '1')
		g->player = (coord_t){g->player.x
			+ (g->player_dir.y * SPEED_WALK), g->player.y};
	if (g->p->map[(int)(g->player.y - (g->player_dir.x * SPEED_WALK))]
		[(int)(g->player.x)] != '1')
		g->player = (coord_t){g->player.x, g->player.y
			- (g->player_dir.x * SPEED_WALK)};
}

void	move_right(game_t *g)
{
	if (g->p->map[(int)(g->player.y)]
		[(int)(g->player.x - (g->player_dir.y * SPEED_WALK))] != '1')
		g->player = (coord_t){g->player.x
			- (g->player_dir.y * SPEED_WALK), g->player.y};
	if (g->p->map[(int)(g->player.y + (g->player_dir.x * SPEED_WALK))]
		[(int)(g->player.x)] != '1')
		g->player = (coord_t){g->player.x, g->player.y
			+ (g->player_dir.x * SPEED_WALK)};
}
