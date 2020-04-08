/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 15:32:39 by phnguyen          #+#    #+#             */
/*   Updated: 2020/04/08 15:51:09 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void    ft_game(game_t *g, int screen, char *path)
{
    free(g);
    screen++;
    path = NULL;
    ft_putstr_fd("GAME\n", 1);
    exit(0);
}