/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_attack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 04:04:55 by phnguyen          #+#    #+#             */
/*   Updated: 2020/08/04 06:58:06 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/cub3d.h"
#include "../include_bonus/hub.h"

void	get_data_image(void *mlx_ptr, image_t *image, char *path)
{
	image->img = mlx_xpm_file_to_image(mlx_ptr, path,
		&image->width, &image->height);
	image->data = (int*)mlx_get_data_addr(image->img,
		&image->bpp, &image->sizeline, &image->endian);
}

void	load_images(game_t *g)
{
	get_data_image(g->mlx_ptr,
		&g->bonus->attack[0], "texture/attack/frame1.xpm");
	get_data_image(g->mlx_ptr,
		&g->bonus->attack[1], "texture/attack/frame2.xpm");
	get_data_image(g->mlx_ptr,
		&g->bonus->attack[2], "texture/attack/frame3.xpm");
	get_data_image(g->mlx_ptr,
		&g->bonus->attack[3], "texture/attack/frame4.xpm");
	get_data_image(g->mlx_ptr,
		&g->bonus->attack[4], "texture/attack/frame5.xpm");
}

void	draw_attack(game_t *g, image_t image)
{
	int		y;
	int		x;
	int		color;
	coord_t tex_hp;

	y = 0;
	while (y < g->p->res_h / 2)
	{
		x = 0;
		while (x < g->p->res_w / 2)
		{
			tex_hp = (coord_t){x * image.width / (g->p->res_w / 2),
				y * image.height / (g->p->res_h / 2)};
			color = (int)image.data[(int)(image.width * tex_hp.y + tex_hp.x)];
			if (color >= 0)
				g->win_img.data[(int)((g->p->res_w) * (y + g->p->res_h / 2)
					+ (x + g->p->res_w / 2))] = color;
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
	else if (g->frame < 3)
		draw_attack(g, g->bonus->attack[2]);
	else if (g->frame < 4)
		draw_attack(g, g->bonus->attack[3]);
	else
		draw_attack(g, g->bonus->attack[4]);
	if (g->frame > 0)
		g->frame--;
}
