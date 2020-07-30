/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 04:35:33 by phnguyen          #+#    #+#             */
/*   Updated: 2020/07/30 06:52:32 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/cub3d.h"
#include "../include_bonus/hub.h"

void	init_hud(game_t *g)
{
	if (!(g->bonus = (bonus_t*)malloc(sizeof(bonus_t))))
		error_exit("malloc HUD\n", g);
	g->bonus->hud.img = mlx_xpm_file_to_image(g->mlx_ptr,
		"texture/crosshair.xpm", &g->bonus->hud.width, &g->bonus->hud.height);
	g->bonus->hud.data = (int*)mlx_get_data_addr(g->bonus->hud.img,
		&g->bonus->hud.bpp, &g->bonus->hud.sizeline, &g->bonus->hud.endian);
	g->bonus->map.img = mlx_new_image(g->mlx_ptr,
			g->p->res_w / 6, g->p->res_h / 6);
	g->bonus->map.data = (int*)mlx_get_data_addr(g->bonus->map.img,
		&g->bonus->map.bpp, &g->bonus->map.sizeline, &g->bonus->map.endian);
	system("afplay music/cat.mp3 &");
}

void	draw_hud(game_t *g)
{
	int x;
	int y;

	x = 0;
	if (!g->save)
		while (x < g->p->res_w)
		{
			y = 0;
			while (y < g->p->res_h)
			{
				if (g->bonus->hud.data[
					(y * g->bonus->hud.height / g->p->res_h)
					* g->bonus->hud.width
					+ (x * g->bonus->hud.width / g->p->res_w)] != 0x0)
					g->win_img.data[g->p->res_w * y + x] = 0xFFFFFF;
				y++;
			}
			x++;
		}
}

void	draw_map(game_t *g)
{
	coord_t	to_map;
	coord_t to_win;

	to_win = (coord_t){g->p->res_w / 6, g->p->res_h / 6};
	to_map = (coord_t){g->p->max_x / to_win.x, g->p->max_y / to_win.y};
	g->x = -1;
	while (++g->x < g->p->res_w / 6)
	{
		g->y = -1;
		while (++g->y < g->p->res_h / 6)
		{
			if (g->x * to_map.x <= ft_strlen(g->p->map[(int)(g->y * to_map.y)])
			&& g->p->map[(int)(g->y * to_map.y)][(int)(g->x * to_map.x)] == '1')
				g->bonus->map.data[(int)(to_win.x * g->y + g->x)] = 0xFFFFFF;
			else if (g->x * to_map.x <= ft_strlen(g->p->map[(int)(g->y * to_map.y)])
			&& g->p->map[(int)(g->y * to_map.y)][(int)(g->x * to_map.x)] == '0')
				g->bonus->map.data[(int)(to_win.x * g->y + g->x)] = 0x0;
			else if (g->x * to_map.x <= ft_strlen(g->p->map[(int)(g->y * to_map.y)])
			&& g->p->map[(int)(g->y * to_map.y)][(int)(g->x * to_map.x)] == '2')
				g->bonus->map.data[(int)(to_win.x * g->y + g->x)] = 0xBA202F;
			else
				g->bonus->map.data[(int)(to_win.x * g->y + g->x)] = 0x263D63;
		}
	}
}

void	update_map(game_t *g)
{
	mlx_put_image_to_window(g->mlx_ptr, g->win_temp, g->bonus->map.img, 0, 0);
	mlx_pixel_put(g->mlx_ptr, g->win_temp,
		g->player.x * (g->p->res_w / 6) / g->p->max_x,
		g->player.y * (g->p->res_h / 6) / g->p->max_y, 0xFF0000);
}
