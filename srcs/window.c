/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 14:37:55 by phnguyen          #+#    #+#             */
/*   Updated: 2020/07/01 19:02:04 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>
#include "hook.h"

void    draw_map(game_t *g);

void    init_data(game_t *g)
{
    g->player.x = g->p->spawn_x;
    g->player.y = g->p->spawn_y;
    if (g->p->spawn_dir == 'N')
    { 
        g->player_dir.x = 0;
        g->player_dir.y = -1;
    }
    if (g->p->spawn_dir == 'S')
    { 
        g->player_dir.x = 0;
        g->player_dir.y = 1;
    }
    if (g->p->spawn_dir == 'E')
    { 
        g->player_dir.x = 1;
        g->player_dir.y = 0;
    }
    if (g->p->spawn_dir == 'W')
    { 
        g->player_dir.x = -1;
        g->player_dir.y = 0;
    }
}

int     make_window(game_t *g)
{
    init_data(g);
    if ((g->win_ptr = mlx_new_window(g->mlx_ptr, g->p->res_w, g->p->res_h, "Cub3D")) == 0)
        return (1);
    //g->screen.img = mlx_xpm_file_to_image(g->mlx_ptr, "./texture/map.xpm", &g->screen.width, &g->screen.height);
    // mlx_get_data_addr(g->screen.img, &g->screen.bpp, &g->screen.sizeline, &g->screen.endian);
    //mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->screen.img, 0, 0);
    draw_map(g);
    mlx_pixel_put(g->mlx_ptr, g->win_ptr,
        (g->player.x * g->p->res_w / g->p->max_x), 
        (g->player.y * g->p->res_h / g->p->max_y), 123456);
    mlx_hook(g->win_ptr, 2, 0, key_press_hook, g);
	mlx_hook(g->win_ptr, 3, 0, key_release_hook, g);
    mlx_hook(g->win_ptr, 17, 0, exit_hook, g);
    mlx_loop_hook(g->win_ptr, loop, g);
    mlx_loop(g->mlx_ptr);
    
    return (0);
}

void    draw_map(game_t *g)
{
    int pixel_x;
    int pixel_y = 0;

    while (pixel_y < g->p->res_h)
    {
        pixel_x = 0;
        while (pixel_x < g->p->res_w)
        {
            if (g->p->map[(pixel_y * 14/g->p->res_h)][(pixel_x * 33/g->p->res_w)] == ' ')
                mlx_pixel_put(g->mlx_ptr, g->win_ptr, (pixel_x), (pixel_y), 0);
            if (g->p->map[(pixel_y * 14/g->p->res_h)][(pixel_x * 33/g->p->res_w)] == '1')
                mlx_pixel_put(g->mlx_ptr, g->win_ptr, (pixel_x), (pixel_y), 0xffffff);
            if (g->p->map[(pixel_y * 14/g->p->res_h)][(pixel_x * 33/g->p->res_w)] == '0')
                mlx_pixel_put(g->mlx_ptr, g->win_ptr, (pixel_x), (pixel_y), 0x111111);
            if (g->p->map[(pixel_y * 14/g->p->res_h)][(pixel_x * 33/g->p->res_w)] == '2')
                mlx_pixel_put(g->mlx_ptr, g->win_ptr, (pixel_x), (pixel_y), 0x555555);
            if (g->p->map[(pixel_y * 14/g->p->res_h)][(pixel_x * 33/g->p->res_w)] == 'N')
                mlx_pixel_put(g->mlx_ptr, g->win_ptr, (pixel_x), (pixel_y), 0x777777);     
            pixel_x++;
        }
        pixel_y++;
    }
}