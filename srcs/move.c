

#include "cub3d.h"
#include "hook.h"

void move_up(game_t *g)
{
    mlx_pixel_put (g->mlx_ptr, g->win_ptr,
        (g->player.x * g->p->res_w / g->p->max_x), 
        (g->player.y * g->p->res_h / g->p->max_y), 0);
    g->player.y -= 0.5;
    mlx_pixel_put (g->mlx_ptr, g->win_ptr,
        (g->player.x * g->p->res_w / g->p->max_x), 
        (g->player.y * g->p->res_h / g->p->max_y), 123456);
}

void move_down(game_t *g)
{
    mlx_pixel_put (g->mlx_ptr, g->win_ptr,
        (g->player.x * g->p->res_w / g->p->max_x), 
        (g->player.y * g->p->res_h / g->p->max_y), 0);
    g->player.y += 0.5;
    mlx_pixel_put (g->mlx_ptr, g->win_ptr,
        (g->player.x * g->p->res_w / g->p->max_x), 
        (g->player.y * g->p->res_h / g->p->max_y), 123456);
}

void move_left(game_t *g)
{
    mlx_pixel_put (g->mlx_ptr, g->win_ptr,
        (g->player.x * g->p->res_w / g->p->max_x), 
        (g->player.y * g->p->res_h / g->p->max_y), 0);
    g->player.x -= 0.5;
    mlx_pixel_put (g->mlx_ptr, g->win_ptr,
        (g->player.x * g->p->res_w / g->p->max_x), 
        (g->player.y * g->p->res_h / g->p->max_y), 123456);
}

void move_right(game_t *g)
{
    mlx_pixel_put (g->mlx_ptr, g->win_ptr,
        (g->player.x * g->p->res_w / g->p->max_x), 
        (g->player.y * g->p->res_h / g->p->max_y), 0);
    g->player.x += 0.5;
    mlx_pixel_put (g->mlx_ptr, g->win_ptr,
        (g->player.x * g->p->res_w / g->p->max_x), 
        (g->player.y * g->p->res_h / g->p->max_y), 123456);
}