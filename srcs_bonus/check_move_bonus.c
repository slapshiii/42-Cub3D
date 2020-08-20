/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_move_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 04:26:38 by phnguyen          #+#    #+#             */
/*   Updated: 2020/08/20 03:29:48 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/cub3d_bonus.h"
#include "../include_bonus/hook_bonus.h"
#include <math.h>

int	check_distx_sprite(t_game *g, double vect)
{
	int	i;

	i = -1;
	while (++i < g->p->num_sprite)
	{
		if (fabs(vect - g->p->sprite[i].pos.x) <= 0.5
			&& fabs(g->player.y - g->p->sprite[i].pos.y) < 0.5)
			return (0);
	}
	return (1);
}

int	check_disty_sprite(t_game *g, double vect)
{
	int	i;

	i = -1;
	while (++i < g->p->num_sprite)
	{
		if (fabs(vect - g->p->sprite[i].pos.y) <= 0.5
			&& fabs(g->player.x - g->p->sprite[i].pos.x) < 0.5)
			return (0);
	}
	return (1);
}
