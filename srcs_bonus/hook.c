/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 02:20:56 by phnguyen          #+#    #+#             */
/*   Updated: 2020/08/07 12:42:12 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/cub3d.h"
#include "../include_bonus/hook.h"

int	key_press_hook(int key, t_game *g)
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
	if (key == KEY_SPACE)
		g->posz = g->p->res_h / 5;
	if (key == KEY_SHIFT)
		g->key_shift = 1;
	if (key == KEY_X)
		g->key_x = 1;
	if (key == KEY_T)
		attack(g);
	if (key == KEY_ESC)
		exit_hook(g);
	return (0);
}

int	key_release_hook(int key, t_game *g)
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
	if (key == KEY_R)
		dash(g);
	if (key == KEY_SHIFT)
		g->key_shift = 0;
	if (key == KEY_X)
	{
		g->posz = 0;
		g->key_x = 0;
	}
	return (0);
}

int	mouse_motion_hook(int x, int y, t_game *g)
{
	mlx_mouse_hide(g->mlx_ptr, g->win_temp);
	if (x > g->p->res_w / 2)
		turn_right(g);
	else if (x < g->p->res_w / 2)
		turn_left(g);
	if (y > g->p->res_h / 2)
		turn_down(g);
	else if (y < g->p->res_h / 2)
		turn_up(g);
	mlx_mouse_move(g->mlx_ptr, g->win_temp, g->p->res_w / 2, g->p->res_h / 2);
	return (0);
}

int	exit_hook(t_game *g)
{
	if (g->bonus->status == 1)
		g->bonus->status++;
	else
	{
		mlx_destroy_window(g->mlx_ptr, g->win_temp);
		error_exit("", g);
	}
	return (0);
}

int	loop(t_game *g)
{
	set_speed(g);
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
