/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 03:05:16 by phnguyen          #+#    #+#             */
/*   Updated: 2020/08/20 03:32:12 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/cub3d_bonus.h"
#include "../include_bonus/struct_bonus.h"
#include <math.h>
#include "../include_bonus/hook_bonus.h"

int	init_raycast(t_game *g)
{
	g->x = 0;
	if (!(g->zbuffer = (double*)malloc(sizeof(double) * g->p->res_w)))
		error_exit("pas de malloc\n", g);
	if (g->key_w || g->key_s || g->key_a || g->key_d)
		move_sprite(g);
	init_floorcast(g);
	while (g->x < (g->p->res_w))
	{
		init_raycasting(g);
		g->zbuffer[g->x] = g->perp;
		g->x++;
	}
	init_castsprite(g);
	animate_attack(g);
	update_hp(g);
	mlx_put_image_to_window(g->mlx_ptr, g->win_temp, g->win_img.img, 0, 0);
	update_map(g);
	loop(g);
	free(g->zbuffer);
	return (0);
}
