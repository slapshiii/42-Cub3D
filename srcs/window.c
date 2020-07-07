/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 14:37:55 by phnguyen          #+#    #+#             */
/*   Updated: 2020/07/07 04:59:11 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>
#include "hook.h"
#include <math.h>

void    draw_map(game_t *g);
void    draw_player(game_t *g);
void    player_set_dir(game_t *g);

void    init_data(game_t *g)
{
    g->coord_to_res.x = g->p->res_w / g->p->max_x;
    g->coord_to_res.y = g->p->res_h / g->p->max_y;

    g->player.x = g->p->spawn_x + 0.5;
    g->player.y = g->p->spawn_y + 0.5;
    if (g->p->spawn_dir == 'N')
    {
        g->plane = (vect_t){0.66, 0.00};
        g->player_rad = 270;
    }
    if (g->p->spawn_dir == 'S')
    {
        g->plane = (vect_t){-0.66, 0.00};
        g->player_rad = 80;
    }
    if (g->p->spawn_dir == 'E')
    {
        g->plane = (vect_t){0.00, 0.66};
        g->player_rad = 0;
    }
    if (g->p->spawn_dir == 'W')
    {
        g->plane = (vect_t){0.00, -0.66};
        g->player_rad = 180;
    }
    player_set_dir(g);
}

int     make_window(game_t *g)
{
    init_data(g);
    if (!(g->win_temp = mlx_new_window(g->mlx_ptr, g->p->res_w, g->p->res_h, "Cub3D")))
        return (1);
    mlx_do_key_autorepeatoff(g->mlx_ptr);
    init_raycast(g);
    mlx_hook(g->win_temp, 2, 0, key_press_hook, g);
	mlx_hook(g->win_temp, 3, 0, key_release_hook, g);
    // mlx_hook(g->win_temp, 12, 0, mouse_focus_hook, g);
    // mlx_hook(g->win_temp, 6, 0, mouse_motion_hook, g);
    // mlx_hook(g->win_temp, 25, 0, resized_hook, g);
    mlx_hook(g->win_temp, 17, 0, exit_hook, g);
    mlx_loop_hook(g->mlx_ptr, loop, g);
    mlx_loop(g->mlx_ptr);
    
    return (0);
}

void    player_set_dir(game_t *g)
{
    if (g->player_rad >= 360)
        g->player_rad -= 360;
    else if (g->player_rad < 0)
        g->player_rad += 360;
    g->player_dir.x = cos((g->player_rad * 3.14159 / 180));
    g->player_dir.y = sin((g->player_rad * 3.14159 / 180));
}
