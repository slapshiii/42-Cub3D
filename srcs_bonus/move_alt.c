/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_alt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 05:18:27 by phnguyen          #+#    #+#             */
/*   Updated: 2020/08/05 04:49:45 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/cub3d.h"
#include "../include_bonus/hook.h"
#include <math.h>

void	end_game(t_game *g)
{
	int	x;
	int	y;
	int	ty;
	int	tx;
	int	color;

	y = -1;
	while (++y < g->p->res_h)
	{
		x = -1;
		while (++x < g->p->res_w)
		{
			tx = (int)(g->bonus->end_game.width * x / g->p->res_w);
			ty = (int)(g->bonus->end_game.height * y / g->p->res_h);
			color = (int)g->bonus->end_game.data[
				(g->bonus->end_game.width * ty) + tx];
			g->win_img.data[g->p->res_w * y + x] = color;
		}
	}
	mlx_put_image_to_window(g->mlx_ptr, g->win_temp, g->win_img.img, 0, 0);
}

void	start_game(t_game *g)
{
	int	x;
	int	y;
	int	ty;
	int	tx;
	int	color;

	y = -1;
	while (++y < g->p->res_h)
	{
		x = -1;
		while (++x < g->p->res_w)
		{
			tx = (int)(g->bonus->start_game.width * x / g->p->res_w);
			ty = (int)(g->bonus->start_game.height * y / g->p->res_h);
			color = (int)g->bonus->start_game.data[
				(g->bonus->start_game.width * ty) + tx];
			g->win_img.data[g->p->res_w * y + x] = color;
		}
	}
	mlx_put_image_to_window(g->mlx_ptr, g->win_temp, g->win_img.img, 0, 0);
}

void	attack(t_game *g)
{
	int i;
	int x;
	int y;

	i = -1;
	x = (int)(g->player.x + g->player_dir.x / 2);
	y = (int)(g->player.y + g->player_dir.y / 2);
	g->frame = 5;
	if (g->bonus->status == 0)
		g->bonus->status = 1;
	if (g->p->num_sprite)
		while (++i < g->p->num_sprite)
		{
			if ((int)g->p->sprite[i].pos.x == x && (int)g->p->sprite[i].pos.y == y)
				if (--g->p->sprite[i].hp == 0)
				{
					swap_sprite(&g->p->sprite[i],
						&g->p->sprite[g->p->num_sprite - 1]);
					g->p->map[y][x] = '0';
					g->p->num_sprite--;
					g->hp++;
					draw_map(g);
				}
		}
}
