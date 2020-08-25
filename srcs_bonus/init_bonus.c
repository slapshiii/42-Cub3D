/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 07:17:55 by phnguyen          #+#    #+#             */
/*   Updated: 2020/08/26 01:45:20 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/cub3d_bonus.h"
#include "../include_bonus/hub_bonus.h"

int		init_bonus(t_game *g)
{
	if (!(g->bonus = (t_bonus*)malloc(sizeof(t_bonus))))
		error_exit("malloc Bonus\n", g);
	bzero(g->bonus, sizeof(t_bonus));
	g->bonus->map.img = mlx_new_image(g->mlx_ptr,
			g->p->res_w / 6, g->p->res_h / 6);
	g->bonus->map.data = (int*)mlx_get_data_addr(g->bonus->map.img,
		&g->bonus->map.bpp, &g->bonus->map.sizeline, &g->bonus->map.endian);
	if (!(g->bonus->attack = (t_image*)malloc(sizeof(t_image) * 5)))
		error_exit("Can't load images for attacks\n", g);
	load_images(g);
	system(PLAY_MUSIC);
	return (0);
}

void	get_data_image(void *mlx_ptr, t_image *image, char *path)
{
	image->img = mlx_xpm_file_to_image(mlx_ptr, path,
		&image->width, &image->height);
	image->data = (int*)mlx_get_data_addr(image->img,
		&image->bpp, &image->sizeline, &image->endian);
}

void	load_images(t_game *g)
{
	get_data_image(g->mlx_ptr, &g->texture_floor, FLOOR_PATH);
	get_data_image(g->mlx_ptr, &g->texture_ceil, CEILING_PATH);
	get_data_image(g->mlx_ptr, &g->bonus->hp, HEALTH_PATH);
	get_data_image(g->mlx_ptr, &g->bonus->attack[0], ATTACK_F1_PATH);
	get_data_image(g->mlx_ptr, &g->bonus->attack[1], ATTACK_F2_PATH);
	get_data_image(g->mlx_ptr, &g->bonus->attack[2], ATTACK_F3_PATH);
	get_data_image(g->mlx_ptr, &g->bonus->attack[3], ATTACK_F4_PATH);
	get_data_image(g->mlx_ptr, &g->bonus->attack[4], ATTACK_F5_PATH);
	get_data_image(g->mlx_ptr, &g->bonus->end_game, ENDSCREEN_PATH);
	get_data_image(g->mlx_ptr, &g->bonus->start_game, STARTSCREEN_PATH);
}
