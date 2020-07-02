

#include "cub3d.h"
#include "hook.h"

void move_up(game_t *g)
{
    if (g->p->map[(int)(g->player.y + (g->player_dir.y * SPEED_WALK))]
    [(int)(g->player.x + (g->player_dir.x * SPEED_WALK))] != '1')
        g->player = (coord_t){g->player.x + (g->player_dir.x * SPEED_WALK),
                            g->player.y + (g->player_dir.y * SPEED_WALK)};
    draw_player(g);
}

void move_down(game_t *g)
{
    if (g->p->map[(int)(g->player.y - (g->player_dir.y * SPEED_WALK))]
    [(int)(g->player.x - (g->player_dir.x * SPEED_WALK))] != '1')
        g->player = (coord_t){g->player.x - (g->player_dir.x * SPEED_WALK),
                            g->player.y - (g->player_dir.y * SPEED_WALK)};
    draw_player(g);
}

void move_left(game_t *g)
{
    if (g->p->map[(int)(g->player.y - (g->player_dir.x * SPEED_WALK))]
    [(int)(g->player.x + (g->player_dir.y * SPEED_WALK))] != '1')
        g->player = (coord_t){g->player.x + (g->player_dir.y * SPEED_WALK),
                            g->player.y - (g->player_dir.x * SPEED_WALK)};
    draw_player(g);
}

void move_right(game_t *g)
{
    if (g->p->map[(int)(g->player.y + (g->player_dir.x * SPEED_WALK))]
    [(int)(g->player.x - (g->player_dir.y * SPEED_WALK))] != '1')
        g->player = (coord_t){g->player.x - (g->player_dir.y * SPEED_WALK),
                            g->player.y + (g->player_dir.x * SPEED_WALK)};
    draw_player(g);
}

void turn_left(game_t *g)
{
    g->player_rad -= SPEED_TURN;
    player_set_dir(g);
    draw_player(g);
}

void turn_right(game_t *g)
{
    g->player_rad += SPEED_TURN;
    player_set_dir(g);
    draw_player(g);
}