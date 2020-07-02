

#include "cub3d.h"
#include "struct.h"
#include <math.h>

void    init_sidedist(game_t *g);
void    calc_dda(game_t *g);

void    init_raycast(game_t *g)
{
    g->map_x = (int)g->player.x;
    g->map_y = (int)g->player.y;

    if(g->player_dir.x == 0)
        g->deltadist = (vect_t){1, 0};
    else if (g->player_dir.y == 0)
        g->deltadist = (vect_t){0, 1};
    else
        g->deltadist = (vect_t){fabs(1/g->player_dir.x),
                                fabs(1/g->player_dir.y)};
    g->hit = 0;
    init_sidedist(g);
}

void    init_sidedist(game_t *g)
{
    if (g->player_dir.x < 0)
    {
        g->step_x = -1;
        g->sidedist.x = (g->player.x - g->map_x) * g->deltadist.x;
    }
    else
    {
        g->step_x = 1;
        g->sidedist.x = (g->map_x + 1.0 - g->player.x) * g->deltadist.x;
    }
    if (g->player_dir.y < 0)
    {
        g->step_y = -1;
        g->sidedist.y = (g->player.y - g->map_y) * g->deltadist.y;
    }
    else
    {
        g->step_y = 1;
        g->sidedist.y = (g->map_y + 1.0 - g->player.y) * g->deltadist.y;
    }
    calc_dda(g);
}

void    calc_dda(game_t *g)
{
    while (g->hit == 0)
    {
        //jump to next map square, OR in x-direction, OR in y-direction
        if (g->sidedist.x < g->sidedist.y)
        {
          g->sidedist.x += g->deltadist.y;
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
            printf("%d %d\n", g->map_x, g->map_y);
            g->hit = 1;
        }
    }
}