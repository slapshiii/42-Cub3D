/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 07:17:55 by phnguyen          #+#    #+#             */
/*   Updated: 2020/08/26 22:15:16 by phnguyen         ###   ########.fr       */
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
	system(PLAY_MUSIC);
	return (0);
}
