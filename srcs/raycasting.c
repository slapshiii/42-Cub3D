/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 03:05:16 by phnguyen          #+#    #+#             */
/*   Updated: 2020/08/21 07:06:47 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../include/struct.h"
#include <math.h>
#include "../include/hook.h"

int	init_raycast(t_game *g)
{
	g->x = 0;
	if (!(g->zbuffer = (double*)malloc(sizeof(double) * g->p->res_w)))
		error_exit("pas de malloc\n", g);
	while (g->x < (g->p->res_w))
	{
		init_raycasting(g);
		g->zbuffer[g->x] = g->perp;
		g->x++;
	}
	init_castsprite(g);
	mlx_put_image_to_window(g->mlx_ptr, g->win_temp, g->win_img.img, 0, 0);
	free(g->zbuffer);
	loop(g);
	return (0);
}
