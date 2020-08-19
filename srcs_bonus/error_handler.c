/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 15:26:04 by phnguyen          #+#    #+#             */
/*   Updated: 2020/08/20 01:33:05 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/cub3d.h"
#include "../include_bonus/parser_param.h"

void	clear_path(t_param *p)
{
	if (p->path_no)
		free(p->path_no);
	if (p->path_so)
		free(p->path_so);
	if (p->path_we)
		free(p->path_we);
	if (p->path_ea)
		free(p->path_ea);
	if (p->path_sprite)
		free(p->path_sprite);
	if (p->map)
		clear_tab(p->map, 0);
}

void	clear_game(t_game *g)
{
	if (g)
	{
		if (g->p)
		{
			if (g->p->sprite)
				free(g->p->sprite);
			clear_path(g->p);
			free(g->p);
		}
		if (g->bonus)
		{
			if (g->bonus->attack)
				free(g->bonus->attack);
			free(g->bonus);
		}
		free(g);
	}
}

void	clear_tab(char **tab, int max)
{
	int i;

	i = 0;
	if (tab)
	{
		if (max > 0)
			while (i <= max)
			{
				free(tab[i]);
				i++;
			}
		else
		{
			while (tab[i])
			{
				free(tab[i]);
				i++;
			}
			free(tab);
		}
	}
}

void	error_exit(char *msg, t_game *g)
{
	ft_putstr_fd(msg, 2);
	clear_game(g);
	mlx_destroy_window(g->mlx_ptr, g->win_temp);
	system("pkill afplay");
	exit(1);
}
