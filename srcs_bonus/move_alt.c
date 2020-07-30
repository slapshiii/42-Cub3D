/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_alt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 05:18:27 by phnguyen          #+#    #+#             */
/*   Updated: 2020/07/30 05:50:46 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/cub3d.h"
#include "../include_bonus/hook.h"
#include <math.h>

void	attack(game_t *g)
{
	if ((int)(g->player.x + g->player_dir.x / 4) == (int)(g->p->sprite[g->p->num_sprite - 1].pos.x)
		&& (int)(g->player.y + g->player_dir.y / 4) == (int)(g->p->sprite[g->p->num_sprite - 1].pos.y))
		g->p->sprite[g->p->num_sprite - 1].hp--;
	if (g->p->sprite[g->p->num_sprite - 1].hp == 0)
	{
		g->p->map[(int)(g->p->sprite[g->p->num_sprite - 1].pos.y)][(int)(g->p->sprite[g->p->num_sprite - 1].pos.x)] = '0';
		g->p->num_sprite--;
	}
}
