

#include "cub3d.h"
#include "hook.h"
#include <math.h>

void move_up(game_t *g)
{
    if (g->p->map[(int)(g->player.y)][(int)(g->player.x + (g->player_dir.x * SPEED_WALK))] != '1')
        g->player = (coord_t){g->player.x + (g->player_dir.x * SPEED_WALK), g->player.y};
    if (g->p->map[(int)(g->player.y + (g->player_dir.y * SPEED_WALK))][(int)(g->player.x)] != '1')
        g->player = (coord_t){g->player.x, g->player.y + (g->player_dir.y * SPEED_WALK)};
    init_raycast(g);
}

void move_down(game_t *g)
{
    if (g->p->map[(int)(g->player.y)][(int)(g->player.x - (g->player_dir.x * SPEED_WALK))] != '1')
        g->player = (coord_t){g->player.x - (g->player_dir.x * SPEED_WALK), g->player.y};
    if (g->p->map[(int)(g->player.y - (g->player_dir.y * SPEED_WALK))][(int)(g->player.x)] != '1')
        g->player = (coord_t){g->player.x, g->player.y - (g->player_dir.y * SPEED_WALK)};
    init_raycast(g);
}

void move_left(game_t *g)
{
    if (g->p->map[(int)(g->player.y)][(int)(g->player.x + (g->player_dir.y * SPEED_WALK))] != '1')
        g->player = (coord_t){g->player.x + (g->player_dir.y * SPEED_WALK), g->player.y};
    if (g->p->map[(int)(g->player.y - (g->player_dir.x * SPEED_WALK))][(int)(g->player.x)] != '1')
        g->player = (coord_t){g->player.x, g->player.y - (g->player_dir.x * SPEED_WALK)};
    init_raycast(g);
}

void move_right(game_t *g)
{
    if (g->p->map[(int)(g->player.y)][(int)(g->player.x - (g->player_dir.y * SPEED_WALK))] != '1')
        g->player = (coord_t){g->player.x - (g->player_dir.y * SPEED_WALK), g->player.y};
    if (g->p->map[(int)(g->player.y + (g->player_dir.x * SPEED_WALK))][(int)(g->player.x)] != '1')
        g->player = (coord_t){g->player.x, g->player.y + (g->player_dir.x * SPEED_WALK)};
    init_raycast(g);
}

void turn_left(game_t *g)
{
    vect_t  olddir;
    vect_t  oldplane;

    olddir = g->player_dir;
    oldplane = g->plane;
    g->player_dir.x = g->player_dir.x * cos(-SPEED_TURN) - g->player_dir.y * sin(-SPEED_TURN);
    g->player_dir.y = olddir.x * sin(-SPEED_TURN) + g->player_dir.y * cos(-SPEED_TURN);
    g->plane.x = g->plane.x * cos(-SPEED_TURN) - g->plane.y * sin(-SPEED_TURN);
    g->plane.y = oldplane.x * sin(-SPEED_TURN) + g->plane.y * cos(-SPEED_TURN);
    init_raycast(g);
}

void turn_right(game_t *g)
{
    vect_t  olddir;
    vect_t  oldplane;

    olddir = g->player_dir;
    oldplane = g->plane;
    g->player_dir.x = g->player_dir.x * cos(SPEED_TURN) - g->player_dir.y * sin(SPEED_TURN);
    g->player_dir.y = olddir.x * sin(SPEED_TURN) + g->player_dir.y * cos(SPEED_TURN);
    g->plane.x = g->plane.x * cos(SPEED_TURN) - g->plane.y * sin(SPEED_TURN);
    g->plane.y = oldplane.x * sin(SPEED_TURN) + g->plane.y * cos(SPEED_TURN);
    init_raycast(g);
}