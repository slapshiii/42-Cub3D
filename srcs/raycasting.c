/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 03:05:16 by phnguyen          #+#    #+#             */
/*   Updated: 2020/07/08 03:10:26 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "struct.h"
#include <math.h>

void	init_raycast(game_t *g)
{
	coord_t	rays[g->p->res_w];
	double	camerax;

	g->x = 0;
	if (!(g->zbuffer = (double*)malloc(sizeof(double) * g->p->res_w)))
		error_exit("pas de malloc\n", g);
	g->win_img.img = mlx_new_image(g->mlx_ptr, g->p->res_w, g->p->res_h);
	g->win_img.data = (int*)mlx_get_data_addr(g->win_img.img,
		&g->win_img.bpp, &g->win_img.sizeline, &g->win_img.endian);
	while (g->x < g->p->res_w)
	{
		camerax = 2 * g->x / (double)g->p->res_w - 1;
		g->ray_dir = (vect_t){g->player_dir.x + g->plane.x * camerax,
			g->player_dir.y + g->plane.y * camerax};
		g->map_x = (int)g->player.x;
		g->map_y = (int)g->player.y;
		g->hit = 0;
		rays[g->x] = init_castwall(g);
		g->zbuffer[g->x] = g->perpwalldist;
		g->x++;
	}
	init_castsprite(g);
	mlx_put_image_to_window(g->mlx_ptr, g->win_temp, g->win_img.img, 0, 0);
	free(g->zbuffer);
}

coord_t	init_castwall(game_t *g)
{
	if (g->ray_dir.y == 0)
		g->deltadist.x = 0;
	else if (g->ray_dir.x == 0)
		g->deltadist.x = 1;
	else
		g->deltadist.x = fabs(1 / g->ray_dir.x);
	if (g->ray_dir.x == 0)
		g->deltadist.y = 0;
	else if (g->ray_dir.y == 0)
		g->deltadist.y = 1;
	else
		g->deltadist.y = fabs(1 / g->ray_dir.y);
	init_castwall_bis(g);
	return (calc_dda(g));
}

void	init_castwall_bis(game_t *g)
{
	if (g->ray_dir.x < 0)
	{
		g->step_x = -1;
		g->sidedist.x = (g->player.x - g->map_x) * g->deltadist.x;
	}
	else
	{
		g->step_x = 1;
		g->sidedist.x = (g->map_x + 1.0 - g->player.x) * g->deltadist.x;
	}
	if (g->ray_dir.y < 0)
	{
		g->step_y = -1;
		g->sidedist.y = (g->player.y - g->map_y) * g->deltadist.y;
	}
	else
	{
		g->step_y = 1;
		g->sidedist.y = (g->map_y + 1.0 - g->player.y) * g->deltadist.y;
	}
}

coord_t	calc_dda(game_t *g)
{
	coord_t res;

	while (g->hit == 0)
	{
		if (g->sidedist.x < g->sidedist.y)
		{
			g->sidedist.x += g->deltadist.x;
			g->map_x += g->step_x;
			g->side = 0;
		}
		else
		{
			g->sidedist.y += g->deltadist.y;
			g->map_y += g->step_y;
			g->side = 1;
		}
		if (g->p->map[g->map_y][g->map_x] == '1')
			g->hit = 1;
	}
	res = hit_texture(g);
	return (calc_texture(g, res));
}
