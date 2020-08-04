/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_alt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 05:18:27 by phnguyen          #+#    #+#             */
/*   Updated: 2020/08/04 23:31:54 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/cub3d.h"
#include "../include_bonus/hook.h"
#include <math.h>

void	attack(game_t *g)
{
	int i;
	int x;
	int y;

	i = -1;
	x = (int)(g->player.x + g->player_dir.x / 4);
	y = (int)(g->player.y + g->player_dir.y / 4);
	g->frame = 5;
	if (g->p->num_sprite)
		while (++i < g->p->num_sprite)
		{
			if (g->p->sprite[i].pos.x == x && g->p->sprite[i].pos.y == y)
				if (--g->p->sprite[i].hp == 0)
				{
					swap_sprite(&g->p->sprite[i],
						&g->p->sprite[g->p->num_sprite - 1]);
					g->p->map[y][x] = '0';
					g->p->num_sprite--;
					if (--g->hp == 0)
						error_exit("No Health Point left\n", g);
					draw_map(g);
				}
		}
}
