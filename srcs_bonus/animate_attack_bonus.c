/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_attack_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 04:04:55 by phnguyen          #+#    #+#             */
/*   Updated: 2020/08/21 07:42:03 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/cub3d_bonus.h"
#include "../include_bonus/hub_bonus.h"

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
