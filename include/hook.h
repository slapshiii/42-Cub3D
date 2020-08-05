/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 02:17:57 by phnguyen          #+#    #+#             */
/*   Updated: 2020/08/05 02:34:43 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_H
# define HOOK_H

/*
**	DEFINE KEYCODE QUIT
*/

# define KEY_ESC 53

/*
**	DEFINE KEYCODE MOVE
*/

# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2

/*
**	DEFINE KEYCODE TURN
*/

# define KEY_Q 12
# define KEY_E 14

# include "cub3d.h"

int		key_press_hook(int key, t_game *g);
int		key_release_hook(int key, t_game *g);
int		mouse_motion_hook(int x, int y, t_game *g);
int		exit_hook(t_game *g);
int		loop(t_game *g);

void	move_up(t_game *g);
void	move_down(t_game *g);
void	move_left(t_game *g);
void	move_right(t_game *g);

void	turn_left(t_game *g);
void	turn_right(t_game *g);

int		mlx_mouse_hide();
int		mlx_mouse_move(void *win_ptr, int x, int y);

#endif
