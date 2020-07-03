

#include "cub3d.h"
#include "struct.h"
#include <math.h>

#define FOV 0.66

coord_t  init_sidedist(game_t *g);
coord_t  calc_dda(game_t *g);
void     draw_test(game_t *g, coord_t *t);

void    init_raycast(game_t *g)
{
    coord_t rays[g->p->res_w];
    int     i;
    double  camerax;
    
    i = 0;
    while (i < g->p->res_w)
    {
        camerax = 2 * i / (double)g->p->res_w - 1;
        g->ray_dir = (vect_t){g->player_dir.x + g->plane.x * camerax,
                            g->player_dir.y + g->plane.y * camerax};
        g->map_x = (int)g->player.x;
        g->map_y = (int)g->player.y;
        g->hit = 0;
        rays[i] = init_sidedist(g);
        i++;
    }
    draw_test(g, rays);
}

coord_t    init_sidedist(game_t *g)
{
    if(g->ray_dir.y == 0)
        g->deltadist.x = 0;
    else if (g->ray_dir.x == 0)
        g->deltadist.x = 1;
    else    
        g->deltadist.x = fabs(1/g->ray_dir.x);
    if(g->ray_dir.x == 0)
        g->deltadist.y = 0;
    else if (g->ray_dir.y == 0)
        g->deltadist.y = 1;
    else    
        g->deltadist.y = fabs(1/g->ray_dir.y);

    if (g->ray_dir.x < 0)
    {
        g->step_x = -1;
        g->sidedist.x = (g->player.x - g->map_x) * g->deltadist.x;
    }
    else
    {
        g->step_x = 1;
        g->sidedist.x = (g->map_x + 1.0 - g->player.x) * g->deltadist.x;
    }
    if (g->ray_dir.y < 0)
    {
        g->step_y = -1;
        g->sidedist.y = (g->player.y - g->map_y) * g->deltadist.y;
    }
    else
    {
        g->step_y = 1;
        g->sidedist.y = (g->map_y + 1.0 - g->player.y) * g->deltadist.y;
    }
    return (calc_dda(g));
}

coord_t   calc_dda(game_t *g)
{
    coord_t res;

    while (g->hit == 0)
    {
        if (g->sidedist.x < g->sidedist.y)
        {
          g->sidedist.x += g->deltadist.x;
          g->map_x += g->step_x;
          g->side = 0;
        }
        else
        {
          g->sidedist.y += g->deltadist.y;
          g->map_y += g->step_y;
          g->side = 1;
        }
        if (g->p->map[g->map_y][g->map_x] == '1')
        {
            g->hit = 1;
        }
    }
    if (g->side == 0)
        g->perpwalldist = (g->map_x - g->player.x + (1 - g->step_x) / 2) / g->ray_dir.x;
    else
        g->perpwalldist = (g->map_y - g->player.y + (1 - g->step_y) / 2) / g->ray_dir.y;

    g->col = (int)(g->p->res_h / (g->perpwalldist));
    res.x = -(g->col) / 2 + g->p->res_h / 2;
    if(res.x < 0)
        res.x = 0;
    res.y = g->col / 2 + g->p->res_h / 2;
    if(res.y >= g->p->res_h)
        res.y = g->p->res_h - 1;
    return (res);
}

void     draw_test(game_t *g, coord_t *t)
{
    int x;
    int y;

    x = 0;
    while(x < g->p->res_w)
    {
        y = 0;
        while(y < g->p->res_h)
        {
            if (y > t[x].x && y < t[x].y)
                mlx_pixel_put(g->mlx_ptr, g->win_temp, x, y, 0xFFFFFF);
            else
                mlx_pixel_put(g->mlx_ptr, g->win_temp, x, y, 0);
            y++;
        }
        x++;
    }
}