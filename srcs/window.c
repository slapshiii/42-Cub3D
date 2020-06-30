/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 14:37:55 by phnguyen          #+#    #+#             */
/*   Updated: 2020/06/30 18:56:09 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>
#include "hook.h"

int make_window(game_t *g)
{
    if ((g->win_ptr = mlx_new_window(g->mlx_ptr, g->p->res_w, g->p->res_h, "Cub3D")) == 0)
        return (1);
    set_hook(g->win_ptr, g);
    //mlx_pixel_put(g->mlx_ptr, g->win_ptr, 50, 50, 16719360);
    mlx_loop(g->mlx_ptr);
    
    return (0);
}

void    set_hook(void *win_ptr, game_t *g)
{
    mlx_do_key_autorepeatoff(g->mlx_ptr);
    mlx_key_hook (win_ptr, get_key, g);
    mlx_hook(win_ptr, 2, 0, key_press_hook, g);
	mlx_hook(win_ptr, 3, 0, key_release_hook, g);
    mlx_hook(win_ptr, 17, 0, exit_hook, g);
    mlx_loop_hook(win_ptr, loop, g);
}