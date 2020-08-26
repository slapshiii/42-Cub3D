/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_file_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 14:34:56 by phnguyen          #+#    #+#             */
/*   Updated: 2020/08/26 22:32:34 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/parser_param_bonus.h"
#include "../get_next_line/get_next_line.h"
#include "../include_bonus/cub3d_bonus.h"

void	init_data(t_game *g)
{
	g->player = (t_coord){g->p->spawn_x + 0.5, g->p->spawn_y + 0.5};
	g->pitch = 0;
	g->posz = 0;
	g->hp = HP_MAX;
	if (g->p->spawn_dir == 'N')
	{
		g->plane = (t_vect){0.66, 0.00};
		g->player_dir = (t_vect){0, -1};
	}
	if (g->p->spawn_dir == 'S')
	{
		g->plane = (t_vect){-0.66, 0.00};
		g->player_dir = (t_vect){0, 1};
	}
	if (g->p->spawn_dir == 'E')
	{
		g->plane = (t_vect){0.00, 0.66};
		g->player_dir = (t_vect){1, 0};
	}
	if (g->p->spawn_dir == 'W')
	{
		g->plane = (t_vect){0.00, -0.66};
		g->player_dir = (t_vect){-1, 0};
	}
}

int		load_image(t_game *g, t_image *image, char* path)
{
	if (!(image->img = mlx_xpm_file_to_image(g->mlx_ptr, path, &(image->width),
					&(image->height)))
	|| (!(image->data = (int*)mlx_get_data_addr(image->img,
					&image->bpp, &image->sizeline,
					&image->endian))))
		return (-1);
	return (0);
}

int		parser_file(t_game *g)
{
	init_bonus(g);
	if ((load_image(g, &g->texture[4], g->p->path_sprite)
	|| load_image(g, &g->texture[3], g->p->path_no)
	|| load_image(g, &g->texture[2], g->p->path_so)
	|| load_image(g, &g->texture[1], g->p->path_ea)
	|| load_image(g, &g->texture[0], g->p->path_we)
	|| load_image(g, &g->texture_floor, FLOOR_PATH)
	|| load_image(g, &g->texture_ceil, CEILING_PATH)
	|| load_image(g, &g->bonus->hp, HEALTH_PATH)
	|| load_image(g, &g->bonus->attack[0], ATTACK_F1_PATH)
	|| load_image(g, &g->bonus->attack[1], ATTACK_F2_PATH)
	|| load_image(g, &g->bonus->attack[2], ATTACK_F3_PATH)
	|| load_image(g, &g->bonus->attack[3], ATTACK_F4_PATH)
	|| load_image(g, &g->bonus->attack[4], ATTACK_F5_PATH)
	|| load_image(g, &g->bonus->end_game, ENDSCREEN_PATH)
	|| load_image(g, &g->bonus->start_game, STARTSCREEN_PATH)))
		return (-1);
	init_data(g);
	g->frame = 0;
	return (0);
}

void	destroy_image(t_game *g, t_image *image)
{
	if (image->img != NULL)
	{
		mlx_destroy_image(g->mlx_ptr, image->img);
	}
}

void	clear_image(t_game *g)
{
	destroy_image(g, &g->texture[0]);
	destroy_image(g, &g->texture[1]);
	destroy_image(g, &g->texture[2]);
	destroy_image(g, &g->texture[3]);
	destroy_image(g, &g->texture[4]);
	destroy_image(g, &g->texture_floor);
	destroy_image(g, &g->texture_ceil);
	destroy_image(g, &g->bonus->hp);
	destroy_image(g, &g->bonus->attack[0]);
	destroy_image(g, &g->bonus->attack[1]);
	destroy_image(g, &g->bonus->attack[2]);
	destroy_image(g, &g->bonus->attack[3]);
	destroy_image(g, &g->bonus->attack[4]);
	destroy_image(g, &g->bonus->end_game);
	destroy_image(g, &g->bonus->start_game);
	destroy_image(g, &g->bonus->map);
	destroy_image(g, &g->win_img);
}

