/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_attack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 04:04:55 by phnguyen          #+#    #+#             */
/*   Updated: 2020/08/05 02:34:43 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/cub3d.h"
#include "../include_bonus/hub.h"

void	get_data_image(void *mlx_ptr, t_image *image, char *path)
{
	image->img = mlx_xpm_file_to_image(mlx_ptr, path,
		&image->width, &image->height);
	image->data = (int*)mlx_get_data_addr(image->img,
		&image->bpp, &image->sizeline, &image->endian);
}

void	load_images(t_game *g)
{
	get_data_image(g->mlx_ptr, &g->bonus->attack[0], ATTACK_F1_PATH);
	get_data_image(g->mlx_ptr, &g->bonus->attack[1], ATTACK_F2_PATH);
	get_data_image(g->mlx_ptr, &g->bonus->attack[2], ATTACK_F3_PATH);
	get_data_image(g->mlx_ptr, &g->bonus->attack[3], ATTACK_F4_PATH);
	get_data_image(g->mlx_ptr, &g->bonus->attack[4], ATTACK_F5_PATH);
	get_data_image(g->mlx_ptr, &g->bonus->end_game, ENDSCREEN_PATH);
	get_data_image(g->mlx_ptr, &g->bonus->start_game, STARTSCREEN_PATH);
}

void	draw_attack(t_game *g, t_image image)
{
	int		y;
	int		x;
	int		color;
	t_coord tex_hp;

	y = 0;
	while (y < g->p->res_h / 2)
	{
		x = 0;
		while (x < g->p->res_w / 2)
		{
			tex_hp = (t_coord){x * image.width / (g->p->res_w / 2),
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

void	animate_attack(t_game *g)
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
