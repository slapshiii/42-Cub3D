/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 02:20:56 by phnguyen          #+#    #+#             */
/*   Updated: 2020/08/07 12:33:48 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../include/hook.h"
#include <stdio.h>

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
	if (key == ARR_L)
		g->key_q = 1;
	if (key == ARR_R)
		g->key_e = 1;
	if (key == KEY_ESC)
	{
		mlx_destroy_window(g->mlx_ptr, g->win_temp);
		error_exit("", g);
	}
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
	if (key == ARR_L)
		g->key_q = 0;
	if (key == ARR_R)
		g->key_e = 0;
	return (0);
}

int	exit_hook(t_game *g)
{
	mlx_destroy_window(g->mlx_ptr, g->win_temp);
	error_exit("", g);
	return (0);
}

int	loop(t_game *g)
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
