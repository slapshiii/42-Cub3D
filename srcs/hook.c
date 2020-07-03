

#include "cub3d.h"
#include "hook.h"
#include <stdio.h>

int key_press_hook(int key, game_t *g)
{
    if (key == KEY_W)
        g->key_w = 1;
    if (key == KEY_S)
        g->key_s = 1;
    if (key == KEY_D)
        g->key_d = 1;
    if (key == KEY_A)
        g->key_a = 1;
    if (key == KEY_Q)
        g->key_q = 1;
    if (key == KEY_E)
        g->key_e = 1;
    if (key == KEY_ESC)
    {
        mlx_destroy_window(g->mlx_ptr, g->win_temp);
        error_exit("KEY_ESC pressed\n", g);
    }
    loop(g);
    return (0);
}

int key_release_hook(int key, game_t *g)
{
    if (key == KEY_W)
        g->key_w = 0;
    if (key == KEY_S)
        g->key_s = 0;
    if (key == KEY_D)
        g->key_d = 0;
    if (key == KEY_A)
        g->key_a = 0;
    if (key == KEY_Q)
        g->key_q = 0;
    if (key == KEY_E)
        g->key_e = 0;
    return (0);
}

int exit_hook(game_t *g)
{
    mlx_destroy_window(g->mlx_ptr, g->win_temp);
    error_exit("Exit button pressed\n", g);
    return (0);
}

int loop(game_t *g)
{
    if (g->key_w == 1)
        move_up(g);
    if (g->key_s == 1)
        move_down(g);
    if (g->key_a == 1)
        move_left(g);
    if (g->key_d == 1)
        move_right(g);
    if (g->key_q == 1)
        turn_left(g);
    if (g->key_e == 1)
        turn_right(g);
    return (0);
}