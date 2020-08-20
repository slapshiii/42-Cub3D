/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 02:22:28 by phnguyen          #+#    #+#             */
/*   Updated: 2020/08/20 03:30:46 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/cub3d_bonus.h"
#include "../include_bonus/struct_bonus.h"
#include <math.h>

void	init_castsprite(t_game *g)
{
	sort_sprites(g);
	cast_sprite(g);
}

void	sort_sprites(t_game *g)
{
	int swap;
	int i;

	swap = 1;
	while (swap)
	{
		i = 0;
		swap = 0;
		while (i < g->p->num_sprite - 1)
		{
			if (sprite_cmp(g->p->sprite[i].pos,
				g->p->sprite[i + 1].pos, g) == -1)
			{
				swap_sprite(&g->p->sprite[i], &g->p->sprite[i + 1]);
				swap = 1;
			}
			i++;
		}
	}
}

int		sprite_cmp(t_coord pos1, t_coord pos2, t_game *g)
{
	if (((g->player.x - pos1.x) * (g->player.x - pos1.x)
		+ (g->player.y - pos1.y) * (g->player.y - pos1.y))
			< ((g->player.x - pos2.x) * (g->player.x - pos2.x)
				+ (g->player.y - pos2.y) * (g->player.y - pos2.y)))
		return (-1);
	else if (((g->player.x - pos1.x) * (g->player.x - pos1.x)
		+ (g->player.y - pos1.y) * (g->player.y - pos1.y))
			> ((g->player.x - pos2.x) * (g->player.x - pos2.x)
				+ (g->player.y - pos2.y) * (g->player.y - pos2.y)))
		return (1);
	else
		return (0);
}

void	swap_sprite(t_sprite *s1, t_sprite *s2)
{
	t_sprite	temp;

	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}
