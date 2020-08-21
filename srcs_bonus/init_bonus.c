/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 07:17:55 by phnguyen          #+#    #+#             */
/*   Updated: 2020/08/21 07:54:29 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/cub3d_bonus.h"
#include "../include_bonus/hub_bonus.h"

int		init_bonus(t_game *g)
{
	g->texture_floor.img = mlx_xpm_file_to_image(g->mlx_ptr,
		FLOOR_PATH, &g->texture_floor.width,
		&g->texture_floor.height);
	g->texture_floor.data = (int*)mlx_get_data_addr(g->texture_floor.img,
		&g->texture_floor.bpp, &g->texture_floor.sizeline,
		&g->texture_floor.endian);
	g->texture_ceil.img = mlx_xpm_file_to_image(g->mlx_ptr, CEILING_PATH,
		&g->texture_ceil.width, &g->texture_ceil.height);
	g->texture_ceil.data = (int*)mlx_get_data_addr(g->texture_ceil.img,
		&g->texture_ceil.bpp, &g->texture_ceil.sizeline,
		&g->texture_ceil.endian);
	init_hud(g);
	return (0);
}

void	init_hud(t_game *g)
{
	if (!(g->bonus = (t_bonus*)malloc(sizeof(t_bonus))))
		error_exit("malloc Bonus\n", g);
	bzero(g->bonus, sizeof(t_bonus));
	g->bonus->hp.img = mlx_xpm_file_to_image(g->mlx_ptr,
		HEALTH_PATH, &g->bonus->hp.width, &g->bonus->hp.height);
	g->bonus->hp.data = (int*)mlx_get_data_addr(g->bonus->hp.img,
		&g->bonus->hp.bpp, &g->bonus->hp.sizeline, &g->bonus->hp.endian);
	g->bonus->map.img = mlx_new_image(g->mlx_ptr,
			g->p->res_w / 6, g->p->res_h / 6);
	g->bonus->map.data = (int*)mlx_get_data_addr(g->bonus->map.img,
		&g->bonus->map.bpp, &g->bonus->map.sizeline, &g->bonus->map.endian);
	if (!(g->bonus->attack = (t_image*)malloc(sizeof(t_image) * 5)))
		error_exit("Can't load images for attacks\n", g);
	load_images(g);
	system(PLAY_MUSIC);
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
	get_data_image(g->mlx_ptr, &g->bonus->attack[0], ATTACK_F1_PATH);
	get_data_image(g->mlx_ptr, &g->bonus->attack[1], ATTACK_F2_PATH);
	get_data_image(g->mlx_ptr, &g->bonus->attack[2], ATTACK_F3_PATH);
	get_data_image(g->mlx_ptr, &g->bonus->attack[3], ATTACK_F4_PATH);
	get_data_image(g->mlx_ptr, &g->bonus->attack[4], ATTACK_F5_PATH);
	get_data_image(g->mlx_ptr, &g->bonus->end_game, ENDSCREEN_PATH);
	get_data_image(g->mlx_ptr, &g->bonus->start_game, STARTSCREEN_PATH);
}
