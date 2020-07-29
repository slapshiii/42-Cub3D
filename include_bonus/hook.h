

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

int     key_press_hook(int key, game_t *g);
int     key_release_hook(int key, game_t *g);
int     mouse_motion_hook(int x, int y, game_t *g);
int     exit_hook(game_t *g);
int     loop(game_t *g);

void    move_up(game_t *g);
void    move_down(game_t *g);
void    move_left(game_t *g);
void    move_right(game_t *g);

void    turn_left(game_t *g);
void    turn_right(game_t *g);
void	turn_down(game_t *g);
void	turn_up(game_t *g);

int	    mlx_mouse_hide();
int     mlx_mouse_move(void *win_ptr, int x, int y); 

#endif