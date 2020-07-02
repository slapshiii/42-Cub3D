/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 14:37:55 by phnguyen          #+#    #+#             */
/*   Updated: 2020/07/03 00:39:14 by phnguyen         ###   ########.fr       */
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
        g->player_rad = 90;
    if (g->p->spawn_dir == 'S')
        g->player_rad = 270;
    if (g->p->spawn_dir == 'E')
        g->player_rad = 0;
    if (g->p->spawn_dir == 'W')
        g->player_rad = 180;
    player_set_dir(g);
}

int     make_window(game_t *g)
{
    init_data(g);
    if ((g->win_ptr = mlx_new_window(g->mlx_ptr, g->p->res_w, g->p->res_h, "Cub3D")) == 0)
        return (1);
    //g->screen.img = mlx_xpm_file_to_image(g->mlx_ptr, "./texture/map.xpm", &g->screen.width, &g->screen.height);
    // mlx_get_data_addr(g->screen.img, &g->screen.bpp, &g->screen.sizeline, &g->screen.endian);
    //mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->screen.img, 0, 0);
    draw_player(g);
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

void    player_set_dir(game_t *g)
{
    if (g->player_rad >= 360)
        g->player_rad -= 360;
    else if (g->player_rad < 0)
        g->player_rad += 360;
    g->player_dir.x = cos((g->player_rad * 3.14159 / 180));
    g->player_dir.y = sin((g->player_rad * 3.14159 / 180));
}

void    draw_player(game_t *g)
{
    int pixel_x;
    int pixel_y = 0;
    vect_t line;

    line.x = g->player.x + g->player_dir.x;
    line.y = g->player.y + g->player_dir.y;

    while (pixel_y < g->p->res_h)
    {
        pixel_x = 0;
        while (pixel_x < g->p->res_w && (pixel_x * 33/g->p->res_w) < (int)ft_strlen(g->p->map[(pixel_y * 14/g->p->res_h)]))
        {
            if (g->p->map[(pixel_y * 14/g->p->res_h)][(pixel_x * 33/g->p->res_w)] == ' ')
                mlx_pixel_put(g->mlx_ptr, g->win_ptr, (pixel_x), (pixel_y), 0x000000);
            else if (g->p->map[(pixel_y * 14/g->p->res_h)][(pixel_x * 33/g->p->res_w)] == '1')
                mlx_pixel_put(g->mlx_ptr, g->win_ptr, (pixel_x), (pixel_y), 0xffffff);
            else if (g->p->map[(pixel_y * 14/g->p->res_h)][(pixel_x * 33/g->p->res_w)] == '0')
                mlx_pixel_put(g->mlx_ptr, g->win_ptr, (pixel_x), (pixel_y), 0x111111);
            else if (g->p->map[(pixel_y * 14/g->p->res_h)][(pixel_x * 33/g->p->res_w)] == '2')
                mlx_pixel_put(g->mlx_ptr, g->win_ptr, (pixel_x), (pixel_y), 0x550000);
            else if (g->p->map[(pixel_y * 14/g->p->res_h)][(pixel_x * 33/g->p->res_w)] == 'N')
                mlx_pixel_put(g->mlx_ptr, g->win_ptr, (pixel_x), (pixel_y), 0x0000FF);
            else
                mlx_pixel_put(g->mlx_ptr, g->win_ptr, (pixel_x), (pixel_y), 0x000000);
            pixel_x++;
        }
        pixel_y++;
    }
    mlx_pixel_put (g->mlx_ptr, g->win_ptr,
        (g->player.x * g->p->res_w / g->p->max_x), 
        (g->player.y * g->p->res_h / g->p->max_y), 0xFFFF00);
    mlx_pixel_put (g->mlx_ptr, g->win_ptr,
        (line.x * g->p->res_w / g->p->max_x), 
        (line.y * g->p->res_h / g->p->max_y), 0x00FFFF);
    init_raycast(g);
}

// void    draw_player(game_t *g)
// {
//     vect_t line;
//     double  x = g->player.x;
//     double  y = g->player.y;

//     line.x = g->player.x + g->player_dir.x;
//     line.y = g->player.y + g->player_dir.y;

//     draw_map(g);
//     if (x <= line.x)
//     {
//         while (x <= line.x)
//         {
//             y = g->player.y;
//             if (y <= line.y)
//                 while (y <= line.y)
//                 {
//                     if ((int)(y * g->coord_to_res.y) ==
//                     (int)((((line.y * g->coord_to_res.y) - (g->player.y * g->coord_to_res.y))
//                     / ((line.x * g->coord_to_res.x) - (g->player.x * g->coord_to_res.x)))
//                     * ((x * g->coord_to_res.x) - (g->player.x * g->coord_to_res.x))
//                     + (g->player.y * g->coord_to_res.y) + 0.5))
//                         mlx_pixel_put(g->mlx_ptr, g->win_ptr,
//                         (int)(x * g->coord_to_res.x),
//                         (int)(y * g->coord_to_res.y), 0xFF0000);
//                     y += 0.01;
//                 }
//             else
//             {
//                 while (y >= line.y)
//                 {
//                     if ((int)(y * g->coord_to_res.y) ==
//                     (int)((((line.y * g->coord_to_res.y) - (g->player.y * g->coord_to_res.y))
//                     / ((line.x * g->coord_to_res.x) - (g->player.x * g->coord_to_res.x)))
//                     * ((x * g->coord_to_res.x) - (g->player.x * g->coord_to_res.x))
//                     + (g->player.y * g->coord_to_res.y) + 0.5))
//                         mlx_pixel_put(g->mlx_ptr, g->win_ptr,
//                         (int)(x * g->p->res_w / g->p->max_x),
//                         (int)(y * g->p->res_h / g->p->max_y), 0xFF0000);
//                     y -= 0.01;
//                 }
//             }
//             x += 0.01;
//         }
//     }
//     else
//     {
//         while (x >= line.x)
//         {
//             y = g->player.y;
//             if (y <= line.y)
//                 while (y <= line.y)
//                 {
//                     if ((int)(y * g->coord_to_res.y) ==
//                     (int)((((line.y * g->coord_to_res.y) - (g->player.y * g->coord_to_res.y))
//                     / ((line.x * g->coord_to_res.x) - (g->player.x * g->coord_to_res.x)))
//                     * ((x * g->coord_to_res.x) - (g->player.x * g->coord_to_res.x))
//                     + (g->player.y * g->coord_to_res.y) + 0.5))
//                         mlx_pixel_put(g->mlx_ptr, g->win_ptr,
//                         (int)(x * g->p->res_w / g->p->max_x),
//                         (int)(y * g->p->res_h / g->p->max_y), 0xFF0000);
//                     y += 0.01;
//                 }
//             else
//             {
//                 while (y >= line.y)
//                 {
//                     if ((int)(y * g->coord_to_res.y) ==
//                     (int)((((line.y * g->coord_to_res.y) - (g->player.y * g->coord_to_res.y))
//                     / ((line.x * g->coord_to_res.x) - (g->player.x * g->coord_to_res.x)))
//                     * ((x * g->coord_to_res.x) - (g->player.x * g->coord_to_res.x))
//                     + (g->player.y * g->coord_to_res.y) + 0.5))
//                         mlx_pixel_put(g->mlx_ptr, g->win_ptr,
//                         (int)(x * g->p->res_w / g->p->max_x),
//                         (int)(y * g->p->res_h / g->p->max_y), 0xFF0000);
//                     y -= 0.01;
//                 }
//             }
//             x -= 0.01;
//         }
//     }
//    printf("%f %f %f %f %f\n", g->player.y * g->p->res_h / g->p->max_y, y, line.y, g->player_dir.y, g->player.y);
//     mlx_pixel_put (g->mlx_ptr, g->win_ptr,
//         (g->player.x * g->p->res_w / g->p->max_x), 
//         (g->player.y * g->p->res_h / g->p->max_y), 0xFFFF00);
//     mlx_pixel_put (g->mlx_ptr, g->win_ptr,
//         (line.x * g->p->res_w / g->p->max_x), 
//         (line.y * g->p->res_h / g->p->max_y), 0x00FFFF);
// }