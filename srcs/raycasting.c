

#include "cub3d.h"
#include "struct.h"
#include <math.h>

coord_t calc_dda(game_t *g);
coord_t calc_texture(game_t *g, coord_t res);
image_t get_texture(game_t *g);

void    init_raycast(game_t *g)
{
    coord_t rays[g->p->res_w];
    double  camerax;
    
    g->x = 0;
    g->win_img.img = mlx_new_image(g->mlx_ptr, g->p->res_w, g->p->res_h);
    g->win_img.data = (int*)mlx_get_data_addr(g->win_img.img, &g->win_img.bpp, &g->win_img.sizeline, &g->win_img.endian);
    while (g->x < g->p->res_w)
    {
        camerax = 2 * g->x / (double)g->p->res_w - 1;
        g->ray_dir = (vect_t){g->player_dir.x + g->plane.x * camerax,
                            g->player_dir.y + g->plane.y * camerax};
        g->map_x = (int)g->player.x;
        g->map_y = (int)g->player.y;
        g->hit = 0;
        rays[g->x] = init_sidedist(g);
        g->x++;
    }
    mlx_put_image_to_window(g->mlx_ptr, g->win_temp, g->win_img.img, 0, 0);
    mlx_destroy_image(g->mlx_ptr, g->win_img.img);
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
    init_sidedist_bis(g);
    return (calc_dda(g));
}

void    init_sidedist_bis(game_t *g)
{
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
        if (g->p->map[g->map_y][g->map_x] == '1'
        || g->p->map[g->map_y][g->map_x] == '2')
            g->hit = 1;
    }
    if (g->side == 0)
    {
        g->perpwalldist = (g->map_x - g->player.x + (1 - g->step_x) / 2) / g->ray_dir.x;
        g->wallx = g->player.y + g->perpwalldist * g->ray_dir.y;
    }
    else
    {
        g->perpwalldist = (g->map_y - g->player.y + (1 - g->step_y) / 2) / g->ray_dir.y;
        g->wallx = g->player.x + g->perpwalldist * g->ray_dir.x;
    }
    res = hit_texture(g);
    return (calc_texture(g, res));
}

coord_t hit_texture(game_t *g)
{
    coord_t res;

    g->texture_side = get_texture(g);
    g->wallx -= floor(g->wallx);
    g->tex_x = (int)(g->wallx * (g->texture_side.width));
    if (g->side == 0 && g->ray_dir.x > 0)
        g->tex_x = (g->texture_side.width - g->tex_x - 1);
    if (g->side == 1 && g->ray_dir.y < 0)
        g->tex_x = (g->texture_side.width - g->tex_x - 1);
    g->col = (int)(g->p->res_h / (g->perpwalldist));
    res.x = -(g->col) / 2 + g->p->res_h / 2;
    if(res.x < 0)
        res.x = 0;
    res.y = g->col / 2 + g->p->res_h / 2;
    if(res.y >= g->p->res_h)
        res.y = g->p->res_h - 1;
    return (res);
}

coord_t calc_texture(game_t *g, coord_t res)
{
    int     color;

    g->y = 0;
    while (g->y < (int)res.x)
    {
        g->win_img.data[(g->p->res_w + 1) * g->y + g->x] = g->p->color_ceiling;
        g->y++;
    }
    g->step = 1.0 * g->texture_side.height / g->col;
    g->tex_pos = (res.x - g->p->res_h / 2 + g->col / 2) * g->step;
    while (g->y < res.y)
    {
        g->tex_y = (int)g->tex_pos & (g->texture_side.height - 1);
        g->tex_pos += g->step;
        color = (int)g->texture_side.data[g->texture_side.height * g->tex_y + g->tex_x];
        if (g->side == 0)
            color = (color >> 1) & 0x7F7F7F;
        g->win_img.data[(g->p->res_w + 1) * g->y + g->x] = color;
        g->y++;
    }
    while (g->y < g->p->res_h)
    {
        g->win_img.data[(g->p->res_w + 1) * g->y + g->x] = g->p->color_floor;
        g->y++;
    }
    return (res);
}

image_t get_texture(game_t *g)
{
    if (g->p->map[g->map_y][g->map_x] == '2')
        return (g->texture[0]);
    if (g->side == 1 && g->ray_dir.y < 0) //North
        return (g->texture[1]);
    else if (g->side == 1) //south
        return (g->texture[2]);
    else if (g->side == 0 && g->ray_dir.x > 0) //West
        return (g->texture[3]);
    else //east
        return (g->texture[4]);
}
