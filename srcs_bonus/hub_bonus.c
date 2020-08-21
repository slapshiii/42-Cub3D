/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hub_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 04:35:33 by phnguyen          #+#    #+#             */
/*   Updated: 2020/08/21 07:32:47 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/cub3d_bonus.h"
#include "../include_bonus/hub_bonus.h"

void	draw_hp(t_game *g, t_coord coord, int size)
{
	int		y;
	int		x;
	int		color;
	t_coord tex_hp;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			tex_hp = (t_coord){x * g->bonus->hp.width / (size),
				y * g->bonus->hp.height / (size)};
			color = (int)g->bonus->hp.data[(int)(g->bonus->hp.width
				* tex_hp.y + tex_hp.x)];
			if (color >= 0)
				g->win_img.data[(int)((g->p->res_w)
					* (y + coord.y) + (x + coord.x))] = color;
			x++;
		}
		y++;
	}
}

void	update_hp(t_game *g)
{
	int		i;
	t_coord	coord;
	int		size;

	i = 0;
	size = (g->bonus->hp.width > g->p->res_w / 100) ? g->bonus->hp.width
		: g->p->res_w / 100;
	while (i < g->hp)
	{
		coord = (t_coord){(int)(g->p->res_w / 2)
			+ (g->bonus->hp.width + size / 2)
			* (i - (int)((HP_MAX + 1) / 2)), (int)(g->p->res_h * 9 / 10)};
		draw_hp(g, coord, size);
		i++;
	}
	draw_map(g);
}

void	draw_map(t_game *g)
{
	t_coord to_win;
	char	c;

	to_win = (t_coord){g->p->res_w / 6, g->p->res_h / 6};
	g->x = -1;
	while (++g->x < g->p->res_w / 6)
	{
		g->y = -1;
		while (++g->y < g->p->res_h / 6)
		{
			if (g->x * g->p->max_x / to_win.x <= ft_strlen(g->p->map[
(int)(g->y * g->p->max_y / to_win.y)]) && (c = g->p->map[(int)(g->y
	* g->p->max_y / to_win.y)][(int)(g->x * g->p->max_x / to_win.x)]))
			{
				if (c == '1')
					g->bonus->map.data[(int)(to_win.x * g->y + g->x)] = BLK;
				else if (c == '0')
					g->bonus->map.data[(int)(to_win.x * g->y + g->x)] = WHT;
				else if (c == '2')
					g->bonus->map.data[(int)(to_win.x * g->y + g->x)] = RED;
				else
					g->bonus->map.data[(int)(to_win.x * g->y + g->x)] = BLU;
			}
		}
	}
}

void	update_map(t_game *g)
{
	mlx_put_image_to_window(g->mlx_ptr, g->win_temp, g->bonus->map.img, 0, 0);
	mlx_pixel_put(g->mlx_ptr, g->win_temp,
		g->player.x * (g->p->res_w / 6) / g->p->max_x,
		g->player.y * (g->p->res_h / 6) / g->p->max_y, 0xFF0000);
}
