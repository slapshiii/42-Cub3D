

#include "cub3d.h"
#include "hook.h"
#include <stdio.h>

int get_key(int key, game_t* g)
{
    if (key == KEY_ESC)
    {
        mlx_destroy_window(g->mlx_ptr, g->win_ptr);
        error_exit("KEY_ESC pressed\n", g);
    }
    if (key == KEY_W)
        printf("forward\n");
    return (0);
}

int key_press_hook(int key, game_t *g)
{
    if (key == KEY_W)
    {
        g->key_w = 1;
        printf("forward press\n");
    }
    if (key == KEY_ESC)
    {
        mlx_destroy_window(g->mlx_ptr, g->win_ptr);
        error_exit("KEY_ESC pressed\n", g);
    }
    return (0);
}

int key_release_hook(int key, game_t *g)
{
    if (key == KEY_W)
    {
        g->key_w = 0;
        printf("forward release\n");
    }
    return (0);
}

int exit_hook(game_t *g)
{
    mlx_destroy_window(g->mlx_ptr, g->win_ptr);
    error_exit("Exit button pressed\n", g);
    return (0);
}

int loop(game_t *g)
{
    printf("loop\n");
    if(g->key_w == 1)
        printf("moving forward\n");
    else
        printf("nothing\n");
    return (0);
}