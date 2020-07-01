/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 14:37:55 by phnguyen          #+#    #+#             */
/*   Updated: 2020/07/01 14:56:51 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>
#include "hook.h"

int make_window(game_t *g)
{
    if ((g->win_ptr = mlx_new_window(g->mlx_ptr, g->p->res_w, g->p->res_h, "Cub3D")) == 0)
        return (1);

    mlx_hook(g->win_ptr, 2, 0, key_press_hook, g);
	mlx_hook(g->win_ptr, 3, 0, key_release_hook, g);
    mlx_hook(g->win_ptr, 17, 0, exit_hook, g);
//    mlx_loop_hook(g->win_ptr, loop, g);
    mlx_loop(g->mlx_ptr);
    
    return (0);
}
