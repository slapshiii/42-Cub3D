/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 14:37:55 by phnguyen          #+#    #+#             */
/*   Updated: 2020/07/30 05:19:09 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/cub3d.h"
#include <stdio.h>
#include "../include_bonus/hook.h"
#include <math.h>

int	make_window(game_t *g)
{
	if (!(g->win_temp = mlx_new_window(g->mlx_ptr,
					g->p->res_w, g->p->res_h, "Cub3D")))
		return (1);
	mlx_do_key_autorepeatoff(g->mlx_ptr);
	init_hud(g);
	init_raycast(g);
	draw_map(g);
	if (g->save)
		save_bitmap(g);
	mlx_hook(g->win_temp, 2, 0, key_press_hook, g);
	mlx_hook(g->win_temp, 3, 0, key_release_hook, g);
	mlx_hook(g->win_temp, 6, 0, mouse_motion_hook, g);
	mlx_hook(g->win_temp, 17, 0, exit_hook, g);
	mlx_loop_hook(g->mlx_ptr, init_raycast, g);
	mlx_loop(g->mlx_ptr);
	return (0);
}
