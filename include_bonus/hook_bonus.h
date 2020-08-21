/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 02:46:12 by phnguyen          #+#    #+#             */
/*   Updated: 2020/08/22 00:06:17 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_BONUS_H
# define HOOK_BONUS_H
# ifdef __APPLE__

/*
**	DEFINE KEYCODE QUIT
*/

#  define KEY_ESC 53

/*
**	DEFINE KEYCODE MOVE
*/

#  define KEY_W 13
#  define KEY_S 1
#  define KEY_A 0
#  define KEY_D 2
#  define KEY_X 7
#  define KEY_R 15
#  define KEY_T 17
#  define KEY_SPACE 49
#  define KEY_SHIFT 257
#  define KEY_VERMAJ 272

/*
**	DEFINE KEYCODE TURN
*/

#  define KEY_Q 12
#  define KEY_E 14

# else

/*
**	DEFINE KEYCODE QUIT
*/

#  define KEY_ESC 65307

/*
**	DEFINE KEYCODE MOVE
*/

#  define KEY_Z 122
#  define KEY_W 119
#  define KEY_S 115
#  define KEY_A 113
#  define KEY_D 100
#  define KEY_X 120
#  define KEY_R 114
#  define KEY_T 116
#  define KEY_SPACE 32
#  define KEY_SHIFT 65505
#  define KEY_VERMAJ 65509

/*
**	DEFINE KEYCODE TURN
*/

#  define KEY_Q 97
#  define KEY_E 101
#  define ARR_R 65363
#  define ARR_L 65361

# endif

# include "cub3d_bonus.h"

int		key_press_hook(int key, t_game *g);
int		key_release_hook(int key, t_game *g);
int		mouse_motion_hook(int x, int y, t_game *g);
int		mouse_press_hook(int button, t_game *g);
int		exit_hook(t_game *g);
int		loop(t_game *g);

void	set_speed(t_game *g);
void	move_up(t_game *g);
void	move_down(t_game *g);
void	move_left(t_game *g);
void	move_right(t_game *g);

void	dash(t_game *g);
void	turn_left(t_game *g);
void	turn_right(t_game *g);
void	turn_down(t_game *g);
void	turn_up(t_game *g);

void	attack(t_game *g);
int		check_distx_sprite(t_game *g, double vect);
int		check_disty_sprite(t_game *g, double vect);

#endif
