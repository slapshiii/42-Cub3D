/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 03:05:16 by phnguyen          #+#    #+#             */
/*   Updated: 2020/07/10 05:06:43 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "struct.h"
#include <math.h>
#include "hook.h"

void	init_raycast(game_t *g)
{
	g->x = 0;
	if (!(g->zbuffer = (double*)malloc(sizeof(double) * g->p->res_w)))
		error_exit("pas de malloc\n", g);
	g->win_img.img = mlx_new_image(g->mlx_ptr, g->p->res_w, g->p->res_h);
	g->win_img.data = (int*)mlx_get_data_addr(g->win_img.img,
		&g->win_img.bpp, &g->win_img.sizeline, &g->win_img.endian);
	while (g->x < g->p->res_w)
	{
		init_raycasting(g);
		g->zbuffer[g->x] = g->perp;
		g->x++;
	}
	init_castsprite(g);
	mlx_put_image_to_window(g->mlx_ptr, g->win_temp, g->win_img.img, 0, 0);
	free(g->zbuffer);
	loop(g);
}