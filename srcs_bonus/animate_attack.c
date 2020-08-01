/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_attack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 04:04:55 by phnguyen          #+#    #+#             */
/*   Updated: 2020/08/01 05:53:35 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/cub3d.h"
#include "../include_bonus/hub.h"

void	load_images(game_t *g)
{
	g->bonus->attack[0].img = mlx_xpm_file_to_image(g->mlx_ptr,
		"texture/attack/frame1.xpm", &g->bonus->attack[0].width, &g->bonus->attack[0].height);
	g->bonus->attack[0].data = (int*)mlx_get_data_addr(g->bonus->attack[0].img,
		&g->bonus->attack[0].bpp, &g->bonus->attack[0].sizeline, &g->bonus->attack[0].endian);
	g->bonus->attack[1].img = mlx_xpm_file_to_image(g->mlx_ptr,
		"texture/attack/frame2.xpm", &g->bonus->attack[1].width, &g->bonus->attack[1].height);
	g->bonus->attack[1].data = (int*)mlx_get_data_addr(g->bonus->attack[1].img,
		&g->bonus->attack[1].bpp, &g->bonus->attack[1].sizeline, &g->bonus->attack[1].endian);
	g->bonus->attack[2].img = mlx_xpm_file_to_image(g->mlx_ptr,
		"texture/attack/frame3.xpm", &g->bonus->attack[2].width, &g->bonus->attack[2].height);
	g->bonus->attack[2].data = (int*)mlx_get_data_addr(g->bonus->attack[2].img,
		&g->bonus->attack[2].bpp, &g->bonus->attack[2].sizeline, &g->bonus->attack[2].endian);
	g->bonus->attack[3].img = mlx_xpm_file_to_image(g->mlx_ptr,
		"texture/attack/frame4.xpm", &g->bonus->attack[3].width, &g->bonus->attack[3].height);
	g->bonus->attack[3].data = (int*)mlx_get_data_addr(g->bonus->attack[3].img,
		&g->bonus->attack[3].bpp, &g->bonus->attack[3].sizeline, &g->bonus->attack[3].endian);
	g->bonus->attack[4].img = mlx_xpm_file_to_image(g->mlx_ptr,
		"texture/attack/frame5.xpm", &g->bonus->attack[4].width, &g->bonus->attack[4].height);
	g->bonus->attack[4].data = (int*)mlx_get_data_addr(g->bonus->attack[4].img,
		&g->bonus->attack[4].bpp, &g->bonus->attack[4].sizeline, &g->bonus->attack[4].endian);
}

void	draw_attack(game_t *g, image_t image)
{
	int y;
	int	x;
	int	color;
	coord_t tex_hp;

	y = 0;
	while (y < g->p->res_h / 2)
	{
		x = 0;
		while (x < g->p->res_w / 2)
		{
			tex_hp = (coord_t){x * image.width / (g->p->res_w / 2), y * image.height / (g->p->res_w / 2)};
			color = (int)image.data[(int)(image.width * tex_hp.y + tex_hp.x)];
			if (color >= 0)
				g->win_img.data[(int)((g->p->res_w) * (y + g->p->res_h / 2) + (x + g->p->res_w / 2))] = color;
			x++;
		}
		y++;
	}
}

void	animate_attack(game_t *g)
{
	if (g->frame == 0)
		draw_attack(g, g->bonus->attack[0]);
	else if (g->frame < 2)
		draw_attack(g, g->bonus->attack[1]);
	else if (g->frame < 4)
		draw_attack(g, g->bonus->attack[2]);
	else if (g->frame < 6)
		draw_attack(g, g->bonus->attack[3]);
	else
		draw_attack(g, g->bonus->attack[4]);
}
