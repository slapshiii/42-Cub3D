/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 14:37:55 by phnguyen          #+#    #+#             */
/*   Updated: 2020/08/22 00:53:50 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/cub3d_bonus.h"
#include "../include_bonus/hook_bonus.h"
#include <math.h>

int	check_status_game(t_game *g)
{
	if (g->bonus->status == 2)
		end_game(g);
	else if (g->bonus->status == 0)
		start_game(g);
	else
		init_raycast(g);
	return (0);
}

int	make_window(t_game *g)
{
	if (!(g->win_temp = mlx_new_window(g->mlx_ptr,
					g->p->res_w, g->p->res_h, "Cub3D")))
		return (1);
	g->win_img.img = mlx_new_image(g->mlx_ptr, g->p->res_w, g->p->res_h);
	g->win_img.data = (int*)mlx_get_data_addr(g->win_img.img,
		&g->win_img.bpp, &g->win_img.sizeline, &g->win_img.endian);
	mlx_do_key_autorepeatoff(g->mlx_ptr);
	init_hud(g);
	init_raycast(g);
	draw_map(g);
	if (g->save)
		save_bitmap(g);
	mlx_hook(g->win_temp, 2, MASK_KPRESSED, key_press_hook, g);
	mlx_hook(g->win_temp, 3, MASK_KRELEASE, key_release_hook, g);
	mlx_hook(g->win_temp, 6, MASK_MSMOTION, mouse_motion_hook, g);
	mlx_hook(g->win_temp, 17, 0, exit_hook, g);
	mlx_loop_hook(g->mlx_ptr, check_status_game, g);
	mlx_loop(g->mlx_ptr);
	return (0);
}
