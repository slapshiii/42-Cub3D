/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 15:32:39 by phnguyen          #+#    #+#             */
/*   Updated: 2020/07/28 01:38:14 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../include/parser_param.h"

void	ft_game(game_t *g, int screen, char *path)
{
	if (screen)
		g->save++;
	if (parser_param(g, path) != 0)
		error_exit("Parsing Error\n", g);
	if (init_mlx(g) != 0)
		error_exit("Init MLX failed\n", g);
	if (parser_file(g) != 0)
		error_exit("There is a not a valid file\n", g);
	if (make_window(g) != 0)
		error_exit("Error making window\n", g);
	clear_game(g);
}
