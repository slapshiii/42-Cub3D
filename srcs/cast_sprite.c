
#include "cub3d.h"
#include "struct.h"
#include <math.h>

void    cast_sprite(game_t *g)
{
    int x;
    double  inv_det;
    int sprite_screen;

    x = 0;
    while (x < g->p->num_sprite)
    {
        g->s = (coord_t){g->p->sprite[x].pos.x - g->player.x, g->p->sprite[x].pos.y - g->player.y};
        inv_det = 1.0 / (g->plane.x * g->player_dir.y - g->player_dir.x * g->plane.y);
        g->trans = (coord_t){inv_det * (g->player_dir.y * g->p->sprite[x].pos.x - g->player_dir.x * g->p->sprite[x].pos.y),
            inv_det * (-g->plane.y * g->p->sprite[x].pos.x + g->plane.x * g->p->sprite[x].pos.y)};
        sprite_screen = (int)((g->p->res_w / 2) * (1 + g->trans.x / g->trans.y));
        calc_hw_sprite(g, g->trans, sprite_screen);
        x++;
    }
}

void    calc_hw_sprite(game_t *g, coord_t trans, int sprite_screen)
{
    coord_t draw_y;
    coord_t draw_x;
    g->sprite_h = abs((int)(g->p->res_h / trans.y));
    draw_y.x = (-g->sprite_h) / 2 + g->p->res_h / 2;
    if(draw_y.x < 0)
        draw_y.x = 0;
    draw_y.y = g->sprite_h / 2 + g->p->res_h / 2;
    if(draw_y.y >= g->p->res_h)
        draw_y.y = g->p->res_h - 1;
    //int spriteWidth = abs( int (h / (transformY))); WTF IS THAT
    draw_x.x = (-g->sprite_h) / 2 + sprite_screen;
    if (draw_x.x < 0)
        draw_x.x = 0;
    draw_x.y = g->sprite_h / 2 + sprite_screen;
    if (draw_x.y >= g->p->res_w)
        draw_x.y = g->p->res_w - 1;
    draw_sprite(g, draw_y, draw_x, sprite_screen);
}

void draw_sprite(game_t *g, coord_t draw_y, coord_t draw_x, int sprite_screen)
{
    int stripe;
    int color;
    int y;
    int d;

    stripe = (int)draw_x.x;
    y = draw_y.x;
    while (stripe < (int)draw_x.y)
    {
        g->tex_x = (int)(256 * (stripe - ((-g->sprite_w) / 2 + sprite_screen)) * g->texture[0].width / g->sprite_h) / 256;
        if(g->trans.y > 0 && stripe > 0 && stripe < g->p->res_w && g->trans.y < g->zbuffer[stripe])
            while (y < draw_y.y)
            {
                d = (y) * 256 - g->p->res_h * 128 + g->sprite_h * 128;
                g->tex_y = ((d * g->texture[0].height) / g->sprite_h) / 256;
                color = (int)g->texture[0].data[g->texture[0].height * g->tex_y + g->tex_x];
                if((color & 0x00FFFFFF) != 0)
                    g->win_img.data[(g->p->res_w + 1) * y + stripe] = color;
                y++;
            }
        stripe++;
    }
}