

#ifndef HOOK_H
# define HOOK_H

/* DEFINE KEYCODE QUIT */

# define KEY_ESC 53

/* DEFINE KEYCODE MOVE */

# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2

/* DEFINE KEYCODE TURN */

# define KEY_Q 12
# define KEY_E 14


# include "cub3d.h"

void    set_hook(void *win_ptr, game_t *g);

int     get_key(int key, game_t* g);
int     key_press_hook(int key, game_t *g);
int     key_release_hook(int key, game_t *g);
int     exit_hook(game_t *g);
int     loop(game_t *g);

#endif