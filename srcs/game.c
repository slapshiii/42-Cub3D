/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 15:32:39 by phnguyen          #+#    #+#             */
/*   Updated: 2020/06/30 14:37:21 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include "parser_param.h"

void    ft_game(game_t *g, int screen, char *path)
{
    if (parser_param(g, path) != 0)
        error_exit("Parsing Error\n", g);
    if (init_mlx(g) != 0)
        error_exit("Init MLX failed\n", g);
    if (parser_file(g) != 0)
        error_exit("There is a not a valid file\n", g);
    if (screen)
        screen--;
    clear_game(g);
}