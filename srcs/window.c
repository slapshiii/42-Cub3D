/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 14:37:55 by phnguyen          #+#    #+#             */
/*   Updated: 2020/07/10 03:33:48 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>
#include "hook.h"
#include <math.h>

int	testest(game_t *g);

void	init_data(game_t *g)
{
	g->player.x = g->p->spawn_x + 0.5;
	g->player.y = g->p->spawn_y + 0.5;
	if (g->p->spawn_dir == 'N')
	{
		g->plane = (vect_t){0.66, 0.00};
		g->player_dir = (vect_t){0, -1};
	}
	if (g->p->spawn_dir == 'S')
	{
		g->plane = (vect_t){-0.66, 0.00};
		g->player_dir = (vect_t){0, 1};
	}
	if (g->p->spawn_dir == 'E')
	{
		g->plane = (vect_t){0.00, 0.66};
		g->player_dir = (vect_t){1, 0};
	}
	if (g->p->spawn_dir == 'W')
	{
		g->plane = (vect_t){0.00, -0.66};
		g->player_dir = (vect_t){-1, 0};
	}
}

int		make_window(game_t *g)
{
	init_data(g);
	if (!(g->win_temp =
		mlx_new_window(g->mlx_ptr, g->p->res_w, g->p->res_h, "Cub3D")))
		return (1);
	mlx_do_key_autorepeatoff(g->mlx_ptr);
	init_raycast(g);
	if (g->save)
		save_bitmap(g);
	mlx_hook(g->win_temp, 2, 0, key_press_hook, g);
	mlx_hook(g->win_temp, 3, 0, key_release_hook, g);
	mlx_hook(g->win_temp, 17, 0, exit_hook, g);
	mlx_loop_hook(g->mlx_ptr, testest, g);
	mlx_loop(g->mlx_ptr);
	return (0);
}

int	testest(game_t *g)
{
	init_raycast(g);
	return (0);
}