

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

int     mouse_focus_hook(game_t *g)
{
    (void)g;
    mlx_mouse_hide();
    return (0);
}

int mouse_motion_hook(int x, int y, game_t *g)
{
    if (x != g->p->res_w / 2)
    {
        if (x > g->p->res_w / 2)
            turn_right(g);
        else if (x < g->p->res_w / 2)
            turn_left(g);
    }
    (void)y;
    mlx_mouse_move(g->win_temp, g->p->res_w / 2, g->p->res_h / 2);
    return (0);
}

int resized_hook(int x, int y, game_t *g)
{
    printf("Resized %d %d\n", x, y);
    (void)g;
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