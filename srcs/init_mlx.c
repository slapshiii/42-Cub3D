/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 02:59:10 by phnguyen          #+#    #+#             */
/*   Updated: 2020/07/10 05:30:39 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_param.h"
#include "get_next_line.h"
#include "cub3d.h"
#include <mlx.h>

int	init_mlx(game_t *g)
{
	int size_x;
	int size_y;

	size_x = 0;
	size_y = 0;
	if ((g->mlx_ptr = mlx_init()) == NULL)
		return (1);
	if (mlx_get_screen_size(g->mlx_ptr, &size_x, &size_y) == 0)
	{
		if (size_x < (g->p->res_w))
			g->p->res_w = size_x;
		if (size_y < g->p->res_h)
			g->p->res_h = size_y;
		if (MIN_SIZE_W > (g->p->res_w))
			g->p->res_w = MIN_SIZE_W;
		if (MIN_SIZE_H > g->p->res_h)
			g->p->res_h = MIN_SIZE_H;
	}
	return (0);
}
