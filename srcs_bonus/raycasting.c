/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 03:05:16 by phnguyen          #+#    #+#             */
/*   Updated: 2020/07/29 05:48:49 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/cub3d.h"
#include "../include_bonus/struct.h"
#include <math.h>
#include "../include_bonus/hook.h"

int	init_raycast(game_t *g)
{
	g->x = 0;
	if (!(g->zbuffer = (double*)malloc(sizeof(double) * g->p->res_w)))
		error_exit("pas de malloc\n", g);
	g->win_img.img = mlx_new_image(g->mlx_ptr, g->p->res_w, g->p->res_h);
	g->win_img.data = (int*)mlx_get_data_addr(g->win_img.img,
		&g->win_img.bpp, &g->win_img.sizeline, &g->win_img.endian);
	init_floorcast(g);
	while (g->x < (g->p->res_w))
	{
		init_raycasting(g);
		g->zbuffer[g->x] = g->perp;
		g->x++;
	}
	init_castsprite(g);
	draw_hud(g);
	mlx_put_image_to_window(g->mlx_ptr, g->win_temp, g->win_img.img, 0, 0);
	mlx_put_image_to_window(g->mlx_ptr, g->win_temp, g->bonus->map.img, 0, 0);
	update_map(g);
	free(g->zbuffer);
	mlx_destroy_image(g->mlx_ptr, g->win_img.img);
	loop(g);
	return (0);
}
