/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 15:32:39 by phnguyen          #+#    #+#             */
/*   Updated: 2020/08/21 07:17:30 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/cub3d_bonus.h"
#include "../include_bonus/parser_param_bonus.h"

void	ft_game(t_game *g, int screen, char *path)
{
	if (screen)
		g->save++;
	if (parser_param(g, path) != 0)
		error_exit("Parsing Error\n", g);
	if (init_mlx(g) != 0)
		error_exit("Init MLX failed\n", g);
	if (parser_file(g) != 0)
		error_exit("There is a not a valid file\n", g);
	if (init_bonus(g) != 0)
		error_exit("Failed to init bonus part", g);
	if (make_window(g) != 0)
		error_exit("Error making window\n", g);
	clear_game(g);
}
