/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_alt_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 05:18:27 by phnguyen          #+#    #+#             */
/*   Updated: 2020/08/20 07:26:16 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/cub3d_bonus.h"
#include "../include_bonus/hook_bonus.h"
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

	i = -1;
	g->frame = 5;
	if (g->bonus->status == 0)
		g->bonus->status = 1;
	if (g->p->num_sprite)
		while (++i < g->p->num_sprite)
		{
			if ((fabs(g->player.x + g->player_dir.x - g->p->sprite[i].pos.x) < 0.4
			&& fabs(g->player.y + g->player_dir.y - g->p->sprite[i].pos.y) < 0.4))
				if (--g->p->sprite[i].hp == 0)
				{
					g->p->map[(int)g->p->sprite[i].pos.y]
						[(int)g->p->sprite[i].pos.x] = '0';
					swap_sprite(&g->p->sprite[i],
						&g->p->sprite[--g->p->num_sprite]);
					if (++g->hp > HP_MAX)
						g->hp = HP_MAX;
					draw_map(g);
				}
		}
}
