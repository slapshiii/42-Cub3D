#include "cub3d.h"
#include "struct.h"
#include <math.h>

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
    res.x = (-g->col) / 2 + g->p->res_h / 2;
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
    if (g->side == 1 && g->ray_dir.y < 0) //North
        return (g->texture[1]);
    else if (g->side == 1) //south
        return (g->texture[2]);
    else if (g->side == 0 && g->ray_dir.x > 0) //West
        return (g->texture[3]);
    else //east
        return (g->texture[4]);
}
